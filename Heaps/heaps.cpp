#include <iostream>

#include "heaps.h"

BinaryHeap::BinaryHeap() { 
  this->a = new int[10];
  this->capacity = 10;
  this->size = 0;
}

int BinaryHeap::left_child(int node) { 
  int index = 2*node + 1;
  if(index > this->size) return -1;
  
  return index; 
}

int BinaryHeap::right_child(int node) {  
  int index = 2*node + 2;
  if(index > this->size) return -1;
             
  return index;
}

void BinaryHeap::percolate_down(int node) {
  int min, l, r;

  l = left_child(node);
  r = right_child(node);

  if(l != -1 && this->a[l] < this->a[node] ) min = l;
  else min = node;

  if(r != -1 && this->a[r] < this->a[min] ) min = r;

  if(min != node) { 
    int temp = this->a[node];
    this->a[node] = this->a[min];
    this->a[min] = temp;

    // recursively call Percolate down on node i
    percolate_down(min);
  }
}

void BinaryHeap::percolate_up(int node) {
  int i = this->size - 1, data = this->a[node];
  while(i > 0 && this->a[(i - 1)/2] > data ) {
    this->a[i] = this->a[(i-1)/2];
    i = (i - 1)/2;
  }

  this->a[i] = data;
}

void BinaryHeap::insert(int data) {
  if(this->size == this->capacity) { 
    std::cout<<"heap is full.."<<std::endl;
    return; 
  } 
  this->size++;
  this->a[this->size - 1] = data;
  percolate_up(this->size - 1);
}

int BinaryHeap::delete_min() { 

  if(this->size == 0) { 
    std::cout<<"Heap is empty, can't delete"<<std::endl;
    return -1;
  }

  int data = this->a[0];
 
  this->a[0] = this->a[this->size-1];

  this->size--;

  percolate_down(0);

  return data;
}

// heap sort

void BinaryHeap::heapsort() {

  while(this->size > 0) {
    int data = this->a[0];
    std::cout<<data<<std::endl;
    this->a[0] = this->a[this->size - 1];
    this->size--;
    this->percolate_down(0);
  }

}
