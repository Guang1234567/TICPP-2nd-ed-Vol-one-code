//: C07:SuperVar.cpp
// From Thinking in C++, 2nd Edition
// Available at http://www.BruceEckel.com
// (c) Bruce Eckel 2000
// Copyright notice in Copyright.txt
// A super-variable
#include <iostream>

using namespace std;

class SuperVar {
    enum {
        character,
        integer,
        floating_point
    } mVartype;  // Define one
    union {  // Anonymous union
        char mC;
        int mI;
        float mF;
    };
public :
    explicit SuperVar(char ch);

    explicit SuperVar(int ii);

    explicit SuperVar(float ff);

    void print();
};

SuperVar::SuperVar(char ch) {
    mVartype = character;
    mC = ch;
}

SuperVar::SuperVar(int ii) {
    mVartype = integer;
    mI = ii;
}

SuperVar::SuperVar(float ff) {
    mVartype = floating_point;
    mF = ff;
}

void SuperVar::print() {
    switch (mVartype) {
        case character:
            cout << "character: " << mC << endl;
            break;
        case integer:
            cout << "integer: " << mI << endl;
            break;
        case floating_point:
            cout << "float: " << mF << endl;
            break;
    }
}

int main() {
    SuperVar A('c'), B(12), C(1.44F);
    A.print();
    B.print();
    C.print();
} ///:~
