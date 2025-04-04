#include <stdlib.h>
#include <stdio.h>
int main() {
  int x = 5;
  int y = 10;
  int *p = &x;  //pointer that holds the memory address of y


  printf("%p\n", (void *)p);
  printf("x = %d\n", x);

  *p = 20;

  printf("x now equals: %d\n", x);
}
