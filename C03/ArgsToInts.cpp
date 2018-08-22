//: C03:ArgsToInts.cpp
// From Thinking in C++, 2nd Edition
// Available at http://www.BruceEckel.com
// (c) Bruce Eckel 2000
// Copyright notice in Copyright.txt
// Converting command-line arguments to ints
#include <iostream>
#include <cstdlib>
using namespace std;

int main(int argc, char* argv[]) {
    cout << "--------" <<  argv[0] << "--------" << endl;
  cout << "--------" <<  atoi(argv[0]) << "--------" << endl;

  for(int i = 1; i < argc; i++) {
      cout << '-' << atoi(argv[i]) << '-' << endl;
      cout << '-' << atof(argv[i]) << '-' << endl;
  }
} ///:~
