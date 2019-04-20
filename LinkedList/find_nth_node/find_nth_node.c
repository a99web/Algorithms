#include <stdio.h>
#include "../linked_list.h"

LinkedList *find_nth(LinkedList *head, int n) {
  if(head == NULL) return NULL;

  LinkedList *curr = head;
  for(int i=1; i < n && curr; i++, curr = curr->next) ;

  return curr;
}

int main() {
  LinkedList *head = create_list();

  print_list(head);

  int n;
  
  printf("Enter n: ");
  scanf("%d", &n);

  LinkedList *nth = find_nth(head, n);
  if(nth == NULL) printf("Position not found\n");
  else printf("The data at position %d = %d\n", n, nth->data);

  return 0;
}
