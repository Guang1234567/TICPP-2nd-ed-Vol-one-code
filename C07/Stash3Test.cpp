//: C07:Stash3Test.cpp
// From Thinking in C++, 2nd Edition
// Available at http://www.BruceEckel.com
// (c) Bruce Eckel 2000
// Copyright notice in Copyright.txt
// {L} Stash3
// Function overloading
#include "Stash3.h"

#include <fstream>
#include <iostream>
#include <string>

#include "../require.h"

using std::ifstream;
using std::string;
using std::cout;
using std::endl;

int main() {
    Stash intStash(sizeof(int));
    for (int i = 0; i < 100; i++)
        intStash.add(&i);
    for (int j = 0; j < intStash.count(); j++)
        cout << "intStash.fetch(" << j << ") = "
             << *reinterpret_cast<int *> (intStash.fetch(j))
             << endl;
    const int bufsize = 80;
    Stash stringStash(sizeof(char) * bufsize, 100);
    // ifstream in("Stash3Test.cpp");
    ifstream in("../C07/Stash3Test.cpp");
    assure(in, "Stash3Test.cpp");
    string line;
    while (getline(in, line))
        stringStash.add((const void *) line.c_str());
    int k = 0;
    char *cp;
    while ((cp = reinterpret_cast<char *> (stringStash.fetch(k++))) != 0)
        cout << "stringStash.fetch(" << k << ") = "
             << cp << endl;
}  ///:~
