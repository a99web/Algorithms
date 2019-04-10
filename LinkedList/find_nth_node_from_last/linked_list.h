struct LinkedList {
  int data;
  struct LinkedList* next;
};

typedef struct LinkedList LinkedList;

// add's node to the list
void add_node(LinkedList*, LinkedList*);

// print the list
void print_list(LinkedList*);
