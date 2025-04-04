#include "vector.h"
#include <stdlib.h>
#include <stdio.h>

int main() {
  Vector v;
  init_vector(&v, 3);

  push_back(&v, 1);
  push_back(&v, 2);
  push_back(&v, 3);
  for (int i = 0; i < size(&v); i++) {
    printf("%d ", v.array[i]);
  }
  printf("\n");
  push_back(&v, 4);
  printf("Resized\n");

  
  for (int i = 0; i < size(&v); i++) {
    printf("%d ", v.array[i]);
  }
  printf("\n");

  int temp = pop(&v);

  printf("\n");
  printf("\n");

  printf("Popped: %d\n", temp);


  return 0;
}
