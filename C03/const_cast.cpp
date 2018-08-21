//: C03:const_cast.cpp
// From Thinking in C++, 2nd Edition
// Available at http://www.BruceEckel.com
// (c) Bruce Eckel 2000
// Copyright notice in Copyright.txt
#include <iostream>
using namespace std;

int main() {
  const int i = 0;
  int* j = (int*)&i; // Deprecated form
  j  = const_cast<int*>(&i); // Preferred
  *j = 3;
  cout << "i = " << i << " address: " << &i << endl;
  cout << "*j = " << *j << " address: " << j << endl;
  
  int* y = &i; 
  // Can't do simultaneous additional casting:
//! long* l = const_cast<long*>(&i); // Error
  volatile int k = 0;
  int* u = const_cast<int*>(&k);
  
  int* z = &k; 
} ///:~
