#include <stdio.h>
#include <malloc.h>
#include "linked_list.h"


LinkedList* create_list() {

  LinkedList *head = NULL;
  // loop to add nodes to the list
  while(1) {
    int data;
    printf("Enter data: ");
    scanf("%d", &data);
    LinkedList *node = (LinkedList*) malloc (sizeof(LinkedList));
    node->data = data;
    node->next = NULL;
    if(head == NULL) head = node;
    else add_node(head, node);
    printf("Add more? 1 for Yes, 0 for No: ");
    int option;
    scanf("%d", &option);
    if(option == 0) break;
  }
 
  return head;
}

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
    //std::cout<<curr->data<<"-->";
    printf("%d-->", curr->data);
    curr = curr->next;
  }
  //std::cout<<"NULL"<<std::endl;
  printf("NULL\n");
  return;
}
