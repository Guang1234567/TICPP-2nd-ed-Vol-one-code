//: C04:CLib.cpp {O}
// From Thinking in C++, 2nd Edition
// Available at http://www.BruceEckel.com
// (c) Bruce Eckel 2000
// Copyright notice in Copyright.txt
// Implementation of example C-like library
// Declare structure and functions:
#include "CLib.h"
#include <iostream>
#include <cassert> 
using namespace std;
// Quantity of elements to add
// when increasing storage:
const int increment = 100;

typedef unsigned char Byte;

void initialize(CStash* s, int sz) {
  s->size = sz;     // 每个元素占的字节数
  s->quantity = 0;  // 内存空间的总字节数
  s->storage = 0;   // 指向内存空间的字节数组指针
  s->next = 0;     //  下一个空的用于存放新元素的存储空间的下标
}

int add(CStash* s, const void* element) {
  if(s->next >= s->quantity) //Enough space left?
    inflate(s, increment);

  // Copy element into storage,
  // starting at next empty space:
  int startBytes = s->next * s->size;
  const Byte* e = (const Byte*)element;
  for(int i = 0; i < s->size; i++)
    s->storage[startBytes + i] = e[i];

  s->next++;
  return(s->next - 1); // Index number
}

void* fetch(CStash* s, int index) {
  // Check index boundaries:
  assert(0 <= index);
  if(index >= s->next)
    return 0; // To indicate the end
  // Produce pointer to desired element:
  return &(s->storage[index * s->size]);
}

int count(CStash* s) {
  return s->next;  // Elements in CStash
}

void inflate(CStash* s, int increase) {
  assert(increase > 0);
  int newQuantity = s->quantity + increase;
  int newBytes = newQuantity * s->size;
  int oldBytes = s->quantity * s->size;
  Byte* b = new Byte[newBytes];
  for(int i = 0; i < oldBytes; i++)
    b[i] = s->storage[i]; // Copy old to new
  delete [](s->storage); // Old storage
  s->storage = b; // Point to new memory
  s->quantity = newQuantity;
}

void cleanup(CStash* s) {
  if(s->storage != 0) {
   cout << "freeing storage" << endl;
   delete [](s->storage);
  }
} ///:~
