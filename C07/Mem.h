//: C07:Mem.h
// From Thinking in C++, 2nd Edition
// Available at http://www.BruceEckel.com
// (c) Bruce Eckel 2000
// Copyright notice in Copyright.txt
#ifndef MEM_H
#define MEM_H

#include <cstdlib>

typedef unsigned char byte;

class Mem {
    byte *mem;
    size_t size;

    void ensureMinSize(size_t minSize);

public:
    Mem();

    Mem(size_t sz);

    ~Mem();

    size_t msize();

    byte *pointer();

    byte *pointer(size_t minSize);
};

#endif  // MEM_H

///:~
