#include <stdio.h>
#include "../linked_list.h"

LinkedList* reverse_list(LinkedList *head) {
  LinkedList *prev = NULL, *curr = head, *next;

  while(curr) {
    next = curr->next;
    curr->next = prev;
    prev = curr;
    curr = next;
  }
  return prev;
}

int main() {
  LinkedList *head = create_list();

  print_list(head);

  head = reverse_list(head);

  printf("******* List after reversing *******\n");

  print_list(head);  
}
