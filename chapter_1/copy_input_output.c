#include <stdio.h>

int main() {
  int c = getchar();
  while(c != EOF) {
    putchar(c);
    c = getchar();
    if (c == 3) {
      c = EOF;
      break;
    }
  }
  if (c == EOF) {
    putchar(c);
  }

}
