#include<iostream>
#include<string>

using namespace std;

#define MAX_SIZE 2

template<class T>
class Queue {
  int front;
  int rear;
  T elements[MAX_SIZE];
  public:
    Queue() {
      front = -1;
      rear = -1;
    }

    void enqueue(T a) {
      if((rear + 1) % MAX_SIZE == front) cout<<"Queue if full, can't enqueue more"<<endl;
      else {
        if(front == -1) front = 0;
        rear = (rear+1) % MAX_SIZE;
        elements[rear] = a;
      }
    }

    T dequeue() {
      if(front == -1) cout<<"Queue is empty, can't dequeue"<<endl;
      else {
        T remove = elements[front];
        if(front == rear) front = rear = -1;
        else front = (front + 1) % MAX_SIZE;
        return remove;
      }
      return T();
    }

    int size() {
       if(front != -1)   {
         if(front > rear) return (MAX_SIZE - front + rear + 1) % MAX_SIZE;
         else return (rear - front + 1);
       }
       else return 0;
    }

    bool is_empty() {
      return front == -1;
    }
};



int main() {
    Queue<string> *q =  new Queue<string>();
    q->enqueue("1");
    q->enqueue("2");
    q->enqueue("3");

    cout<<q->size()<<endl;

    q->dequeue();
    q->dequeue();
    q->dequeue();

    cout<<q->size()<<endl;

    q->enqueue("1");
    q->dequeue();
    q->enqueue("2");
    q->enqueue("3");

    q->dequeue();

    cout<<q->size()<<endl;

    q->dequeue();
    
    cout<<q->size()<<endl;
    
    q->dequeue();

    return 0;
}
