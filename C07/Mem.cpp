//: C07:Mem.cpp {O}
// From Thinking in C++, 2nd Edition
// Available at http://www.BruceEckel.com
// (c) Bruce Eckel 2000
// Copyright notice in Copyright.txt
#include "Mem.h"
#include <cstring>

using namespace std;

Mem::Mem() {
    mem = 0;
    size = 0;
}

Mem::Mem(size_t sz) {
    mem = 0;
    size = 0;
    ensureMinSize(sz);
}

Mem::~Mem() { delete[]mem; }

size_t Mem::msize() { return size; }

void Mem::ensureMinSize(size_t minSize) {
    if (size < minSize) {
        byte *newmem = new byte[minSize];
        memset(newmem + size, 0, minSize - size);
        memcpy(newmem, mem, size);
        delete[]mem;
        mem = newmem;
        size = minSize;
    }
}

byte *Mem::pointer() {
    return mem;
}

byte *Mem::pointer(size_t minSize) {
    ensureMinSize(minSize);
    return mem;
} ///:~
