#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Concatenate two strings a + b 
char* string_concat(char* a, char* b) {
  char* ap = a;
  int len_a = strlen(a);
  int len_b = strlen(b);
  int len = len_a + len_b;
  
  for (int i = 0; i < len; i++) {
    if (i < len_a) {
      a++;
      continue;
    }
    else {
      *a = *b;
      a++;
      b++;
    }
  } 

  return ap;
}

int main() {
  char a[20] = "Hello ";
  char* b = "World";

  printf("%s%s\n", a, b);
  printf("\n");

  printf("%s\n", string_concat(a, b));

  
  return 0;
}
