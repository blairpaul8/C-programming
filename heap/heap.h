#ifndef HEAP_H
#define HEAP_H
#include "vector.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct Heap {
  int size;
  int capacity;
  Vector v;
} Heap;

//*h is a pointer to the heap and i is the index on which 
//heapify is called.
void heapify(Heap *h, int i);
void init_heap(Heap *h, int a);
void build_heap(Heap *h);


#endif //HEAP_H
