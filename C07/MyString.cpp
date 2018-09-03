//
// Created by lihanguang on 2018/9/3.
//

#include "MyString.h"
#include <cstring>

using std::ostream;
using std::endl;

MyString::MyString() { buf = 0; }

MyString::MyString(const char *str) {
    buf = new Mem(strlen(str) + 1);
    strcpy(reinterpret_cast<char *>(
                   buf->pointer()
           ),
           str);
}

void MyString::concat(const char *str) {
    if (!buf) buf = new Mem();

    size_t oldSize = buf->msize();
    size_t newLen = oldSize + strlen(str);
    if (oldSize == 0) {
        newLen += 1;
    }

    strcat(reinterpret_cast<char *>(
                   buf->pointer(newLen)),
           str);
}

void MyString::concat(MyString &other) {
    if (!buf) buf = new Mem();

    size_t newLen = this->length() + other.length() + 1;
    strcat(reinterpret_cast<char *>(
                   buf->pointer(newLen)),
           reinterpret_cast<char *> (other.buf->pointer()));
}

size_t MyString::length() {
    return !buf ? 0 : (buf->msize() - 1);
}

void MyString::print(ostream &os) {
    if (!buf) return;
    os << "\"" << buf->pointer() << "\"" << endl;
}

MyString::~MyString() { delete buf; }
