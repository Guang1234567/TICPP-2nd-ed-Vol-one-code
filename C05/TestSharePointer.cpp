#include <iostream>
#include <memory>
#include <thread>
#include <mutex>

using std::cout;
using std::cin;
using std::endl;
using std::this_thread::sleep_for;
using std::shared_ptr;
using std::make_shared;
using std::chrono::seconds;
using std::mutex;
using std::lock_guard;
using std::thread;

struct Base {
    Base() { cout << "  Base::Base()\n"; }

    // Note: non-virtual destructor is OK here
    ~Base() { cout << "  Base::~Base()\n"; }
};

struct Derived : public Base {
    Derived() { cout << "  Derived::Derived()\n"; }

    ~Derived() { cout << "  Derived::~Derived()\n"; }
};

void thr(shared_ptr<Base> p) {
    sleep_for(seconds(1));
    shared_ptr<Base> lp = p;  // thread-safe, even though the
    // shared use_count is incremented
    {
        static mutex io_mutex;
        lock_guard<mutex> lk(io_mutex);
        cout << "local pointer in a thread:\n"
             << "  lp.get() = " << lp.get()
             << ", lp.use_count() = " << lp.use_count() << '\n';
    }
}

void foo(std::shared_ptr<Base> &lp){
    cout << "local pointer in a foo:\n"
         << "  lp.get() = " << lp.get()
         << ", lp.use_count() = " << lp.use_count() << '\n';
}

int main() {
    shared_ptr<Base> p = make_shared<Derived>();

    cout << "Created a shared Derived (as a pointer to Base)\n"
         << "  p.get() = " << p.get()
         << ", p.use_count() = " << p.use_count() << '\n';

    foo(p);

    // 这里面 smartpointer 的引用数是 10,
    // 因为有 5 个 Thread 实例, 每个实例引发 smartpointer + 2
    thread t1(thr, p), t2(thr, p), t3(thr, p), t4(thr, p), t5(thr, p);
    p.reset();  // release ownership from main
    cout << "Shared ownership between 3 threads and released\n"
         << "ownership from main:\n"
         << "  p.get() = " << p.get()
         << ", p.use_count() = " << p.use_count() << '\n';
    // 排队执行, 每执行完一个线程, smartpointer - 2
    t1.join();
    t2.join();
    t3.join();
    t4.join();
    t5.join();
    cout << "All threads completed, the last one deleted Derived\n";
}
