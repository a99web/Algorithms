#include <iostream>

#include "heaps.h"

int main() {
  BinaryHeap heap = BinaryHeap();

  heap.insert(2);
  heap.insert(4);
  heap.insert(3);

  heap.insert(-1);
  heap.insert(6);
  heap.insert(0);

  heap.insert(-6);
  heap.insert(5);

  //heap.delete_min();
  //std::cout<<heap.delete_min()<<std::endl;
  //std::cout<<heap.delete_min()<<std::endl;
  //std::cout<<heap.delete_min()<<std::endl;

  heap.heapsort();

}
