#include <iostream>
#include "linked_list.h"

// add node at the end of the list
void add_node(LinkedList *head, LinkedList *node) {
  LinkedList *curr = head, *p;
  while(curr != NULL) {
    p = curr;
    curr = curr->next;
  }

  p->next = node;
  return;
}

// print the list node by node
void print_list(LinkedList *head) {
  LinkedList *curr = head;
  while(curr != NULL) {
    std::cout<<curr->data<<"-->";
    curr = curr->next;
  }
  std::cout<<"NULL"<<std::endl;
  return;
}
