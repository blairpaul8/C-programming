#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
  int key;
  struct Node *next;
};

static struct Node *head, *z, *t;

void stack_init() {
  head = (struct Node *) malloc(sizeof(*head));
  z = (struct Node *) malloc(sizeof(*z));
  head->next = z;
  head->key = 0;
  z->next = z;
}

void push(int v) {
  t = (struct Node *) malloc(sizeof(*t));
  t->key = v;
  t->next = head->next;
  head->next = t;
}

int pop() {
  int x;
  t = head->next;
  x = t->key;
  head->next = t->next;
  free(t);
  return x;
}

int stack_empty() {
  return head->next == z;
}

void print_stack() {
  struct Node *currentNode = head->next;
  while (currentNode != z) {
    if (currentNode->next != z) {
      printf("%d, ", currentNode->key);
    }
    else {
      printf("%d\n", currentNode->key);
    }
    currentNode = currentNode->next;
  }
}

int main() {
  stack_init();
  push(10);
  push(25);
  push(2);
  print_stack();

}
