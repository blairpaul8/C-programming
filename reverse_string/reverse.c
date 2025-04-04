#include <stdio.h>
#include <string.h>

void reverse_string(char a[]) {
  int length = strlen(a);

  int j = length - 1; 
  for (int i = 0; i < length / 2; i++) {
    char temp = a[i];
    a[i] = a[j];
    a[j] = temp;
    j--;
  }
}

int main() {
  char a[] = "even";
  char b[] = "odd";

  printf("%s\n", a);
  reverse_string(a);

  printf("%s\n", a);
  printf("\n");

  printf("%s\n", b);
  reverse_string(b);
  printf("%s\n", b);
}
