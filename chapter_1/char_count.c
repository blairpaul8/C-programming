#include <stdio.h>

int main() {
  int char_count;
  int c;
  char_count = 0;
  while (getchar() != EOF) {
    ++char_count;
  }
  printf("Char count: %d\n", char_count);
}
