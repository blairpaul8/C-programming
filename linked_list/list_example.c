#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node *next;
};
struct Node *head, *z, *t;

//initialize the list
void initialize() {
  head = (struct Node*)malloc(sizeof(*head));
  z = (struct Node*)malloc(sizeof(*z));
  t = (struct Node*)malloc(sizeof(*t));
  head->next = z;
  z->next = z;
}

void push_front(int v) {
  struct Node *temp;
  temp = (struct Node*)malloc(sizeof(*temp));
  temp->data = v;
  temp->next = head->next;
  head->next = temp;
}

void print_list() {
  t = head->next;
  while (t != z) {
    printf("%d, ",t->data);
    t = t->next;
  }
  printf("\n");
}


int main() {
  initialize();
  push_front(1);
  push_front(2);
  print_list();

}
