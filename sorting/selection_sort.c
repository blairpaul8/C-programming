#include <stdio.h>
#include <stdlib.h>

void selection(int a[], int N) {
  int i, j, min, t;

  for (i = 0; i <= N - 1; i++) {
    min = i;
    for (j = i + 1; j <= N - 1; j++) {
      if (a[j] < a[min]) {
        min = j;
      }
    }

    t = a[min];
    a[min] = a[i];
    a[i] = t;
  }

}

void print_list(int a[], int N) {
  for (int i = 0; i <= N-1; i++) {
    printf("%d ", a[i]);
  }
  printf("\n");
}

int main() {
  int N = 10;
  int a[10] = {4, 7, 8, 3, 1, 5, 9, 2, 0, 6};
  print_list(a, N);
  selection(a, N);
  print_list(a, N);
}
