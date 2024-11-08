#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include <vector>


// node structure for linked list
template<typename T>
struct Node {
  T data;
  Node* next;
  Node(T val) : data(val), next(nullptr) {}
};

// temp class for queue
template<typename T>
class Queue {
private:

  Node<T>* frontNode;  
  Node<T>* rearNode;   
  int count;  

public:

  Queue();
  ~Queue();

  void push(T value);    
  void pop();            
  T front();             
  int size();            
  bool empty();          
  void display();        
  void move_to_rear();   
};

int recursiveLastOccurrence(const std::vector<int>& arr, int target, int index);


#endif
