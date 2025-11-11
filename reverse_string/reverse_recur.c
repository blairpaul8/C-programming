#include <stdlib.h>
#include <stdio.h>
#include <string.h>


char* reverse(char* s) {
  char* r;
  if (s == NULL) {
    return s;
  }
  int len = strlen(s);
  r = reverse(s);

  r += s[len];
  s[len] = '\0';
  return r;
}

int main() {
  char* a = "top";
  char* b = reverse(a);

  printf("%s", b);
  return 0;
}
