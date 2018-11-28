
// implementing a mean heap

class BinaryHeap { 

  private:
    //pointer to an array that stores the element
    int *a;
    long int capacity;
    int size;

  public:
    BinaryHeap();
    // method to delete the min element from the heap
    int delete_min();
    void insert(int);
    void percolate_up(int);
    void percolate_down(int);
    int left_child(int);
    int right_child(int);
    void heapsort();
};
