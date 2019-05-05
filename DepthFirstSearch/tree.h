#include <vector>

class Tree {
  int node_no;
  std::vector<Tree*> children;

  public:
    Tree(int node_no);

    void add_child(Tree* node);

    int get_node_no();

    int get_child_count();

    Tree* get_child(int);
};
