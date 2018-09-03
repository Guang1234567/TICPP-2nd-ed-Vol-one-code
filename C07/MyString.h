//
// Created by lihanguang on 2018/9/3.
//

#ifndef MYSTRING_H
#define MYSTRING_H

#include "Mem.h"
#include <iostream>

class MyString;

class MyString {
    Mem *buf;
public:
    MyString();

    explicit MyString(const char *str);

    ~MyString();

    void concat(const char *str);

    void concat(MyString &str);

    size_t length();

    void print(std::ostream &os);
};

#endif //MYSTRING_H
