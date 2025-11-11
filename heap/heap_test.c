#include "heap.h"
#include "vector.h"
#include <stdio.h>
#include <stdlib.h>

void print_vector(Vector *v) {
  for (int i = 0; i < size(v); i++) {
    printf("%d ", v->array[i]);
  }
  printf("\n");
}

int main() {
  Vector vec;
  Heap heap;

  init_heap(&heap, 5);

  init_vector(&vec, 5);

  push_back(&vec, 3);
  push_back(&vec, 1);
  push_back(&vec, 4);
  push_back(&vec, 2);

  heap.v = vec;

  // Print vector before build heap
  print_vector(&heap.v);

  build_heap(&heap);
  print_vector(&heap.v);

  return 0;
}
