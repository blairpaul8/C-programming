#include "link_list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void parse_input(struct Node **head, char *cmd, int data) {
  if (cmd[0] == 'P') {
    print_list(*head);
  }
  if (cmd[0] == 'F') {
    push_front(head, data);
  }
  if (cmd[0] == 'B') {
    push_back(head, data);
  }
  if (cmd[0] == 'R') {
    remove_node(head, data);
  }
  if (cmd[0] == 'C') {
    clear(head);
  }
}

int main() {
  struct Node *head = NULL;
  char c[2];
  int data;

  while (1) {
    printf(">> ");
    scanf("%s %d", c, &data);
    if (c[0] == 'Q') {
      break;
    }
    parse_input(&head, c, data);
  }

  return 0;
}
