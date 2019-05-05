#include <vector>
#include "tree.h"

Tree::Tree(int node_no) {
  this->node_no = node_no;
}

void Tree::add_child(Tree* node) {
  children.push_back(node);
}

int Tree::get_node_no() { 
  return this->node_no; 
}

Tree* Tree::get_child(int i) { 
  return this->children[i];
}

int Tree::get_child_count() {
  return this->children.size();
}
