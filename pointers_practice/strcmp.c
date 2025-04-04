//This program will lexographically sort an array of strigns
#include <stdio.h>
#include <stdlib.h>


int string_compare(char* s, char* t) {
  for (; *s == *t; s++, t++) {
    if (*s == '\0') {
      return 0;
    }
  }
  return *s - *t;
}


int main() {
  

  char a[] = "byte";
  char b[] = "bart"; 

  printf("Compare: %d\n", string_compare(b,a));
  return 0;
}
