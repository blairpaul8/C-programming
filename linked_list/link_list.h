#ifndef LINK_LIST_H
#define LINK_LIST_H

struct Node {
  int data;
  struct Node *next;
};

void push_front(struct Node **head, int data);
void push_back(struct Node **head, int data);
void remove_node(struct Node **head, int data);
void clear(struct Node **head);
void print_list(struct Node *head);
struct Node* reverse_list(struct Node *head);

#endif //LINK_LIST_H
