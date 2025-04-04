#include <stdio.h>
#include <stdlib.h>

int main() {
  int c;
  int ln = 0;
  
  while ((c = getchar()) != EOF) {
    if ((c == '\n') || (c == ' ')) {
      ++ln;
    }
  }
  printf("%d\n", ln);
}
