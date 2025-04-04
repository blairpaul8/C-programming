#include <stdio.h>
#include <stdlib.h>

#define IN 1  //Inside a word
#define OUT 0 //Outside a word

int main() {
  int c;
  int nw;
  int ln;
  int nc;
  int state = OUT;
  nw = 0;
  ln = 0;
  nc = 0;
  
  while ((c = getchar()) != EOF) {
    ++nc;
    if ((c == ' ') || (c == '\n') || (c == '\t')) {
      state = OUT;
    }
    else {
      state = IN;
      ++nw;
    }
  }
}

