#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

char *int_to_str(int a) {
  int i = 0;
  char *buff = malloc(256 * sizeof(char));
  char *out = malloc(256 * sizeof(char));

  while (a != 0) {

    int num = a % 10;
    a = a / 10;

    char c = '0' + num;
    buff[i] = c;
    i++;
  }

  buff[i] = '\0';

  int len = strlen(buff);
  int j = 0;
  for (int i = len - 1; i >= 0; i--) {
    out[j] = buff[i];
    j += 1;
  }

  out[j] = '\0';

  return out;
}

void print(char *s, ...) {
  va_list args;
  va_start(args, s);
  int size = strlen(s);
  int len = 0;
  char output[4096];

  for (int i = 0; i < size; i++) {

    if (s[i] == '%') {
      i += 1;

      switch (s[i]) {
      case 'd': {
        int arg = va_arg(args, int);
        char *temp = int_to_str(arg);
        strcat(output, temp);
        len += strlen(temp);

      } break;
      case 's': {
        const char *temp = va_arg(args, const char *);
        strcat(output, temp);
        len += strlen(temp);

      } break;
      }
      continue;
    } else {
      output[len] = s[i];
      len += 1;
    }
  }

  write(0, output, len);
}

int main(int argc, char *argv[]) {

  print("Hello %d %s\n", 4, "world");

  return 0;
}
