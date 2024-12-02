#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct Node {
  int data;
  struct Node *next;
};

static struct Node *head, *z, *t;

void queue_init() {
  head = (struct Node *) malloc(sizeof(*head));
  z = (struct Node *) malloc(sizeof(*z));
  head->data = 0;
  head->next = z;
  z->next = z;
}

void push(int v) {
  t = (struct Node *) malloc(sizeof(*t));
  t->data = v;
  t->next = head->next;
  head->next = t;
}

int pop() {
  int x;
  struct Node *currentNode = head;
  while (currentNode->next->next != z) {
    currentNode = currentNode->next;
  }

  struct Node *temp = currentNode->next;
  currentNode->next = currentNode->next->next;
  x = temp->data;
  free(temp);
  return x;
}

int main() {
  queue_init();
  push(10);
  push(15);
  push(5);
  push(20);
  printf("%d\n", pop());
}
