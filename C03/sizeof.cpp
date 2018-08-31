//: C03:sizeof.cpp
// From Thinking in C++, 2nd Edition
// Available at http://www.BruceEckel.com
// (c) Bruce Eckel 2000
// Copyright notice in Copyright.txt
#include <iostream>
using namespace std;
int main() {
  int* i = NULL;
  char* i1 = NULL;
  float* i2 = NULL;
  int j = -1;
  cout << "sizeof(double) = " << sizeof(double);
  cout << ", sizeof(char) = " << sizeof(char);
  cout << ", sizeof(i) = " << sizeof(i); // as size as long type
  cout << ", sizeof(i1) = " << sizeof(i1); // as size as long type
  cout << ", sizeof(i1) = " << sizeof(i2); // as size as long type
  cout << ", sizeof(j) = " << sizeof(j);

  int arr[] = {7,8,9,10};
  cout << ", sizeof(arr) = " << sizeof(arr);
  cout << ", sizeof(*arr) = " << sizeof(*arr);

  cout << ", sizeof(arr) / sizeof(*arr) = " << sizeof(arr) / sizeof(*arr);

  return EXIT_SUCCESS;
} ///:~
