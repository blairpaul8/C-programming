#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  int fd = open("test.txt", O_RDONLY);

  char byte;

  while (read(fd, &byte, sizeof(char)) == 1) {
    printf("%c", byte);
  }
  printf("\n");

  return EXIT_SUCCESS;
}
