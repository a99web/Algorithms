nth_node: find_nth_node_from_last/find_nth_node.c linked_list.o
	gcc -o nth_node find_nth_node_from_last/find_nth_node.c linked_list.o


reverse: reverse_list/reverse_list.c linked_list.o
	gcc -o reverse reverse_list/reverse_list.c linked_list.o

linked_list.o: linked_list.h linked_list.c
	gcc -c linked_list.c

clean:
	rm *.o nth_node reverse
