#include <stdio.h>

int main() {
  int far;
  int cel;
  int lower = 0;
  int upper = 300;
  int step = 20;

  far = lower;
  while (far <= upper) {
    cel = (5.0/9.0) * (far - 32);
    printf("%d\t%d\n", far, cel);
    far += step;
  }
}
