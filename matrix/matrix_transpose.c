#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int trace() {
  int trace = 0;


  return trace;
}

void transpose(int arr[]) {
  int m = 3;
  int n = 3;
  int transpose_arr[9] = {0};

  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      int index = i * n + j;
      int new_index = j * m + i;
      transpose_arr[new_index] = arr[index];
    }
  }

  for ( int i = 0; i < 9; i++) {
    arr[i] = transpose_arr[i];
  }
}

char parse_input(const char *input, int arr[], int arr_size) {

  int j = 0;
  char c;
  for (int i = 0; i < strlen(input); i++) {
    if (!(input[0] >= 'A') && !(input[0] <= 'D')) {
      printf("Bad variable name.");
      return 1;
    }
    else {
      c = input[0];

    }
    if ((input[i] >= '0') && (input[i] <= '9')) {
      int current_val = input[i] - '0';
      arr[j] = current_val;
      j++;
    }
  }
  return c;
}

void print_matrix(int arr[]) {
  for (int i = 0; i < 9; i++) {
    if (i == 3 || i == 6) {
      printf("\n");
    }

    if (i == 0 || i == 3 || i == 6) {
      printf("    ");
    }
    printf("%d  ", arr[i]);
  }
  printf("\n");
}


int main() {
  int arr_A[9] = {0};
  int arr_B[9] = {0};
  char var_1;
  char var_2;

  char *input = calloc(100, sizeof(char));
  size_t size = 0;
  ssize_t chars_read;
  
  while (input[0] != 'Q') {
    printf(">> ");
    chars_read = getline(&input, &size, stdin);

    if (chars_read < 0) {
      printf("Couldn't read string input");
      free(input);
      return 1;
    }

    if (input[chars_read - 1] == '\n') {
      input[chars_read - 1] = '\0';
      chars_read--;  // Update the length to reflect the removal
    }

    if (input[0] >= 'A' && input[0] <= 'D') {
      var_1 = parse_input(input, arr_A, 9);
      printf("\n");
      printf("%c = \n", var_1);
      print_matrix(arr_A);
    }
  
    if (input[0] == 'T') {
      transpose(arr_A);
      printf("\n");
      print_matrix(arr_A);
    }

  }
  return 0;
}
