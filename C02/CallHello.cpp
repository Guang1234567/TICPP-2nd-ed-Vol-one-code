//: C02:CallHello.cpp
// From Thinking in C++, 2nd Edition
// Available at http://www.BruceEckel.com
// (c) Bruce Eckel 2000
// Copyright notice in Copyright.txt
// Call another program
#include <cstdlib> // Declare "system()"
#include <string>
#include <iostream>
using namespace std;

int main() {
  cout << "Execute files:"<< endl;
  cout << "=============================================================="<< endl;
  system("ls *.exe");
  cout << "=============================================================="<< endl;
  cout << endl;
  
  string exeFile;
  cout << "Enter the other execute file above: ";
  cin >> exeFile;
  exeFile = "./" + exeFile;
  system(exeFile.c_str());
} ///:~
