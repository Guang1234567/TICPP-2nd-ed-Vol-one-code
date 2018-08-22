//: C03:PointerArithmetic.cpp
// From Thinking in C++, 2nd Edition
// Available at http://www.BruceEckel.com
// (c) Bruce Eckel 2000
// Copyright notice in Copyright.txt
#include <iostream>
using namespace std;

#define P(EX) cout << #EX << ": " << EX << endl;

int main() {
  int a[10];
  for(int i = 0; i < 10; i++)
    a[i] = i * i; // Give it index values
  int* ip = a;
  P(*ip); // 0
  P(ip); // ip = 0
  P(*++ip); // 1
  P(ip); // ip = 1
  P(*ip++); // 1
  P(ip); //ip = 2
  P((*ip++)); // 4
  P(ip); // ip = 3
  P(*(ip + 5));  //  64
  P(ip); // ip = 3
  int* ip2 = ip + 5; // ip2 = 8
  P(*ip2); // 64
  P(*(ip2 - 4)); // 16
  P(*--ip2); // 49   ip2 = 7
  P(*ip2--); // 49  ip2 = 6
  P((*ip2--)); // 36  ip2 = 5
  P(ip2 - ip); // Yields number of elements   2

  cout << endl << endl << "++++++++++++++++++++" << endl << endl;

    for(int i = 0; i < 10; i++) {
        cout << "a[" << i << "] = " << a[i] << endl;
        P(&a[i]);
    }

} ///:~
