#include "vector.h"
#include <stdlib.h>
#include <stdio.h>


void init_vector(Vector *v, int a) {
  v->array = (int*)malloc(a * sizeof(int));
  v->size = 0;
  v->capacity = a;
}

void resize(Vector *v) {
  v->array = (int*)realloc(v->array, v->capacity * 2 * sizeof(int)); 
}

void push_back(Vector *v, int a) {

  if (v->size < v->capacity) {
    v->array[v->size] = a; 
    v->size++;

  }
  else {
    resize(v);
    v->array[v->size] = a; 
    v->size++;

  }
}

int size(Vector *v) {
  return v->size;
}

int pop(Vector *v) {
  if (v->size == 0) {
    printf("Vector empty nothing to pop.\n");
    return -1;
  }

  int temp = v->array[v->size - 1];
  v->array[v->size] = 0;
  v->size--;

  return temp;
}

