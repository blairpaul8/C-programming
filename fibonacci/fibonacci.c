#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int fibonacci(int n) {
  if (n <= 1) {
    return 1;
  }
  return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
  printf("Enter a");
}

