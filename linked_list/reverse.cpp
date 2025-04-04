

Node* reverse_list(Node* head) {
  Node *current = head;
  Node *previous = NULL;
  Node *temp = current->next; 
  while (current != NULL) {
    current->next = previous;
    previous = current;
    current = temp;
    temp = current->next;
    
    
  }
  head = previous;

  return head;
}
