//: C03:Boolean.cpp
// From Thinking in C++, 2nd Edition
// Available at http://www.BruceEckel.com
// (c) Bruce Eckel 2000
// Copyright notice in Copyright.txt
// Relational and logical operators.
#include <iostream>

// using namespace std;
using std::cout;
using std::cin;
using std::endl;
using std::boolalpha;
using std::noboolalpha;
using std::to_string;

int main() {
    int i, j;
    cout << "Enter an integer: ";
    cin >> i;
    cout << "Enter another integer: ";
    cin >> j;
    cout << "true is " << true << endl;
    cout << "false is " << false << endl;
    cout << "0.0000 is " << boolalpha << (0.0000) << endl;
    cout << "0.0001 is " << boolalpha << (0.0001) << endl;
    cout << "0.0001 > 0.0000 is " << boolalpha << (0.0001 > 0.0000) << endl;
    cout << "0.0001 < 0.0000 is " << boolalpha << (0.0001 < 0.0000) << endl;
    cout << "0.0001 == 0.0000 is " << boolalpha << (0.0001 == 0.0000) << endl;
    cout << "0.0001 == 0.0001 is " << boolalpha << (0.0001 == 0.0001) << endl;
    cout << "0.0000 == 0.0000 is " << boolalpha << (0.0000 == 0.0000) << endl;
    cout << "i > j is " << to_string(i > j) << endl;
    cout << "i > j is " << boolalpha << (i > j) << endl;
    cout << "i > j is " << noboolalpha << (i > j) << endl;
    // https://stackoverflow.com/questions/29383/converting-bool-to-text-in-c
    cout << "i > j is " << noboolalpha << (i > j) << '\t'
         << boolalpha << (i > j) << endl;
    cout << "i < j is " << (i < j) << endl;
    cout << "i >= j is " << (i >= j) << endl;
    cout << "i <= j is " << (i <= j) << endl;
    cout << "i == j is " << (i == j) << endl;
    cout << "i != j is " << (i != j) << endl;
    cout << "i && j is " << (i && j) << endl;
    cout << "i || j is " << (i || j) << endl;
    cout << " (i < 10) && (j < 10) is "
         << ((i < 10) && (j < 10)) << endl;
}  ///:~
