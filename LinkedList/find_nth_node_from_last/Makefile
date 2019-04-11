nth_node: find_nth_node.cpp linked_list.o
	g++ -o nth_node find_nth_node.cpp linked_list.o


linked_list.o: linked_list.h linked_list.cpp
	g++ -c linked_list.cpp

clean:
	rm -rf *.o nth_node
