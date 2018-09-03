//: C07:MemTest.cpp
// From Thinking in C++, 2nd Edition
// Available at http://www.BruceEckel.com
// (c) Bruce Eckel 2000
// Copyright notice in Copyright.txt
// Testing the Mem class
//{L} Mem

#include "MyString.h"
#include <iostream>

using std::cout;
using std::endl;

int main() {
    MyString s("My test string");
    s.print(cout);
    s.concat(" some additional stuff");
    s.print(cout);
    MyString s2;
    s2.concat("Using default constructor");
    s2.print(cout);

    MyString s3;
    s3.concat("1234");
    s3.concat("56789");
    s3.print(cout);
    cout << "s3 = " << s3.length() << endl;

    MyString s4("");
    s4.concat("1234");
    s4.concat("56789");
    s4.print(cout);
    cout << "s4 = " << s4.length() << endl;

    MyString s5;
    s5.concat("");
    s5.print(cout);
    cout << "s5 = " << s5.length() << endl;

    MyString s6;
    s6.concat("");
    s6.print(cout);
    cout << "s6 = " << s6.length() << endl;

    MyString s7("abc");
    s7.concat(s4);
    s7.print(cout);
    cout << "s7 = " << s7.length() << endl;
} ///:~
