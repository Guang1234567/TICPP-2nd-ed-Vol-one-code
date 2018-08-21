//: C02:FillString.cpp
// From Thinking in C++, 2nd Edition
// Available at http://www.BruceEckel.com
// (c) Bruce Eckel 2000
// Copyright notice in Copyright.txt
// Read an entire file into a single string
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

int main() {
  ifstream in("FillString.cpp");
  string s, line;
  int lineNo = 1;
  while(getline(in, line)) {
    s += to_string(lineNo) + ": " + line + "\n";
    lineNo++;
  }
  cout << s;
} ///:~
