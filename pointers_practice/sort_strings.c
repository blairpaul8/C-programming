// This program will lexographically sort an array of strigns
#include <stdio.h>
#include <stdlib.h>
#define MAXLINES 500

void swap(char **a, char **b) {
  char *temp;
  temp = *a;
  *a = *b;
  *b = temp;
}

int string_compare(char *s, char *t) {
  for (; *s == *t; s++, t++) {
    if (*s == '\0') {
      return 0;
    }
  }
  return *s - *t;
}

void sort_strings(char **strings) {

  for (int i = 0; i < 4; i++) {
    if (string_compare(strings[i], strings[i + 1]) == 0) {
      continue;
    }

    if (string_compare(strings[i], strings[i + 1]) > 0) {
      swap(&strings[i], &strings[i + 1]);
    }
  }
}

int main() {
  char *strings[MAXLINES] = {"Hello", "Byte", "Charlie", "Tucker", "Willie"};

  for (int i = 0; i < 5; i++) {
    printf("%s\n", strings[i]);
  }
  printf("\n");

  sort_strings(strings);

  for (int i = 0; i < 5; i++) {
    printf("%s\n", strings[i]);
  }
  printf("\n");
  return 0;
}
