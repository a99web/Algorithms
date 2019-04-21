#include <stdio.h>
#include <stdlib.h>
#include "../linked_list.h"

int check_for_loop(LinkedList *head) {

  if(head == NULL || head->next == NULL) return 0;

  LinkedList *slow = head, *fast = head;

  while(fast != NULL && fast->next != NULL) {
    slow = slow->next;
    fast = fast->next->next;
    if(slow == fast) return 1;
  }

  return 0;
}

int main() {

  LinkedList *head = (LinkedList *)malloc(sizeof(LinkedList));

  /*
          3
         /  \
   1 -- 2    4
         \   /
           5
  */

  head->data = 1;

  LinkedList *n2 = (LinkedList *)malloc(sizeof(LinkedList));
  LinkedList *n3 = (LinkedList *)malloc(sizeof(LinkedList));
  LinkedList *n4 = (LinkedList *)malloc(sizeof(LinkedList));
  LinkedList *n5 = (LinkedList *)malloc(sizeof(LinkedList));

  n2->data = 2;
  n3->data = 3;
  n4->data = 4;
  n5->data = 5;

  head->next = n2;
  n2->next = n3;
  n3->next = n4;
  n4->next = n5;
  n5->next = n2;

  if(check_for_loop(head)) printf("Loop found\n");
  else printf("Loop not found\n");

  // removing the loop from list, to verify for negative case
  n5->next = NULL;

  if(check_for_loop(head)) printf("Loop found\n");
  else printf("Loop not found\n");

  return 0;
}
