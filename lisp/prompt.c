#include "mpc.h"
#include <editline/history.h>
#include <editline/readline.h>
#include <stdio.h>
#include <stdlib.h>

int main() {

  printf("LISP version: 0.0.1\n");
  printf("\n");

  while (1) {
    char *input = readline("LISP > ");

    add_history(input);

    printf("%s\n", input);
    free(input);
  }

  return 0;
}
