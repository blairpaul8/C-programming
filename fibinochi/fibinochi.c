#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int fibinochi(int n) {
  if (n <= 1) {
    return 1;
  }
  return fibinochi(n - 1) + fibinochi(n - 2);
}

int main() {
  printf("Enter a ")
}

