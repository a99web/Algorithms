#include <bits/stdc++.h>

#include "../linked_list.h"

// program to find nth node from the end

LinkedList* find_nth_node(LinkedList *head, int n) {
  LinkedList *pnth = NULL, *ptemp = head;
  // move the ptemp pointer n times
  for(int i=1;i<n;i++) {
    ptemp = ptemp->next;
    if(ptemp == NULL) break;
  }

  // now move the pnth till ptemp reaches the end
  while(ptemp) {
    if(pnth == NULL) pnth = head;
    else pnth = pnth->next;
    ptemp = ptemp->next;
  }

  if(pnth) return pnth;
  return NULL;
}

int main() {
  LinkedList *head = NULL;
  
  // loop to add nodes to the list
  while(1) {
    int data;
    printf("Enter data: ");
    std::cin>>data;
    LinkedList *node = (LinkedList*) malloc (sizeof(LinkedList));
    node->data = data;
    node->next = NULL;
    if(head == NULL) head = node;
    else add_node(head, node);
    printf("Add more? 1 for Yes, 0 for No: ");
    int option;
    std::cin>>option;
    if(option == 0) break;
  }

  print_list(head);

  int N;
  printf("Enter n: ");
  scanf("%d", &N);

  LinkedList* node = find_nth_node(head, N);
  if(node) std::cout<<node->data<<std::endl;
  else printf("Position not found\n");
  return 0;
}
