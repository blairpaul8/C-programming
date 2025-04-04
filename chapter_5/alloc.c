#include <stdio.h>
#include <stdlib.h>

#define ALLOCSIZE 10000 /* Size of available space */ 

static char allocbuf[ALLOCSIZE];
static char *alloc_pointer = allocbuf;

char *alloc(int n) {
  if (alloc_buf + ALLOCSIZE - alloc_pointer >= n) { /* There is enough space in the buffer */
    alloc_pointer += n; // Increment the pointer by n
    return alloc_pointer - n; // return the original pointer
  }
  else {
    return 0;
  }
}

void afree(char *p) { /*Free memory pointed to by p */
  if (p >= alloc_buf && p < alloc_buf + ALLOCSIZE) {
    alloc_pointer = p;
  }
}
