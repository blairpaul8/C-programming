#include "link_list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node* reverse_list(struct Node *head) {
  struct Node *current = head;
  struct Node *previous = NULL;
  struct Node *temp = current->next;

  while (current != NULL) {
    current->next = previous;
    previous = current;
    current = temp;
    temp = current->next;
  }
  head = previous;
  return head;
}

void push_front(struct Node **head, int data) {
  struct Node *newNode = malloc(sizeof(struct Node));
  newNode->data = data;
  newNode->next = NULL;
  if (*head == NULL) {
    *head = newNode;
    return;
  }

  newNode->next = *head;
  *head = newNode;
  return;
}

void push_back(struct Node **head, int data) {
  struct Node *newNode = malloc(sizeof(struct Node));
  newNode->data = data;
  newNode->next = NULL;
  if (*head == NULL) {
    *head = newNode;
    return;
  }
  struct Node *currentNode = *head;

  while (currentNode->next != NULL) {
    currentNode = currentNode->next;
  }
  currentNode->next = newNode;
  return;
}

void remove_node(struct Node **head, int data) {
  struct Node *temp;
  if ((*head)->data == data) {
    temp = *head;
    *head = (*head)->next;
    free(temp);
  }
  struct Node *currentNode = *head;
  while (currentNode->next->data != data) {
    currentNode = currentNode->next;
  }
  temp = currentNode->next;
  currentNode->next = temp->next;
  free(temp);
  return;
}

void clear(struct Node **head) {
  struct Node *temp;
  struct Node *currentNode;
  currentNode = *head;
  while (currentNode != NULL) {
    temp = currentNode;
    currentNode = currentNode->next;
    free(temp);
  }
  *head = NULL;
  return;
}

void print_list(struct Node *head) {
  struct Node *currentNode = head;

  while (currentNode != NULL) {
    if (currentNode->next == NULL) {
      printf("%d\n", currentNode->data);
    }
    else {
      printf("%d, ", currentNode->data);
    }
    currentNode = currentNode->next;

  }
}

