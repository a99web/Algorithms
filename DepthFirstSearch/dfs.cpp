/*
  Depth first search tree traversal using stack
*/

#include <iostream>
#include <stack>
#include <map>
#include <vector>
#include "tree.h"


bool all_visited(Tree* node, std::map<int, bool>& visited) {

  int len = node->get_child_count();

  for(int i=0;i<len;i++) {
      Tree* child = node->get_child(i);
      if(visited.find(child->get_node_no()) == visited.end()) { 
         return false;
      }
  }

  return true;
}


void dfs(Tree* node, std::vector<int>& array) {

  std::stack<Tree*> s;

  int node_no = node->get_node_no();

  s.push(node);

  array.push_back(node_no);

  std::map<int, bool> visited;


  while(!s.empty()) {
    Tree* top = s.top();
    //std::cout<<top->get_node_no()<<std::endl;

    int len = top->get_child_count();
    visited[top->get_node_no()] = true;
    
    if(len == 0 || all_visited(top, visited)) {
      s.pop();

    } else {
      for(int i=0;i<len;i++) {
        Tree* child = top->get_child(i);
        if(visited.find(child->get_node_no()) == visited.end()) { 
          s.push(child);
          array.push_back(child->get_node_no());
          break;
        }
      }
    }

  }
}

int main() {
  Tree* root = new Tree(1);

  /*
 
      1

   2     3
 
      4     5
          
         6     7

    DFS -->  1 2 3 4 5 6 7

  */

  
  Tree* c2 = new Tree(2);
  Tree* c3 = new Tree(3);
  Tree* c4 = new Tree(4);
  Tree* c5 = new Tree(5);
  Tree* c6 = new Tree(6);
  Tree* c7 = new Tree(7);
  

  root->add_child(c2);
  root->add_child(c3);
  
  c3->add_child(c4);
  c3->add_child(c5);

  c5->add_child(c6);
  c5->add_child(c7);
  

  std::vector<int> dfs_traversal;

  dfs(root, dfs_traversal);

  int len = dfs_traversal.size();

  for(int i=0;i<len;i++) std::cout<<dfs_traversal[i]<<" ";


  return 0;
}
