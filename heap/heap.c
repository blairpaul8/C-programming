#include "heap.h"
#include "vector.h"
#include <stdlib.h>
#include <stdio.h>

void init_heap(Heap *h, int a) {
  h->capacity = a;
  h->size = 0;
  init_vector(&h->v, a);
}

//Used to swap two values in the vector.
static void swap(Vector *v, int a, int b) {
  int temp = v->array[a];
  v->array[a] = v->array[b];
  v->array[b] = temp;
}

//*h is a pointer to the heap and i is the index on which 
//heapify is called.
void heapify(Heap *h, int i) {
  int left = 2 * i + 1;
  int right = 2 * i + 2;
  int largest = i;

  if (left <= h->v.size && h->v.array[left] > largest) {
    largest = left;
  }

  if (right <= h->v.size && h->v.array[right] > largest) {
    largest = right;
  }

  if (largest != i) {
    swap(&h->v, i, largest);
    heapify(h, largest);
  }
}

void build_heap(Heap *h) {
  int start = (h->size - 1) / 2;

  for (int i = start; i >= 0; i--) {
    heapify(h, i);
  }
}
