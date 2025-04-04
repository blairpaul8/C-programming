#ifndef VECTOR_H
#define VECTOR_H

#include <stdlib.h>
#include <stdio.h>


typedef struct Vector {
  int size;
  int capacity;
  int *array;
} Vector;

void init_vector(Vector *v, int a);
void resize(Vector *v); 
void push_back(Vector *v, int a);
int pop(Vector *v);
int size(Vector *v);

#endif // VECTOR_H
