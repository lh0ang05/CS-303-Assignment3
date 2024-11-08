#include "functions.h"
#include <stdexcept>
#include <vector>


// initialize the queue
template<typename T>
Queue<T>::Queue() : frontNode(nullptr), rearNode(nullptr), count(0) {}

// destructor 
template<typename T>
Queue<T>::~Queue() {
  while (!empty()) {
    pop();
  }
}

// push function to add element to butt  
template<typename T>
void Queue<T>::push(T value) {
  Node<T>* newNode = new Node<T>(value);
  if (empty()) {
    frontNode = rearNode = newNode;
  } 

  else {
    rearNode->next = newNode;
    rearNode = newNode;
  }

  count++;
}

// pop to remove  element from front 
template<typename T>
void Queue<T>::pop() {
  if (empty()) {
    std::cout << "queue empty\n";
    return;
  }

  Node<T>* temp = frontNode;
  frontNode = frontNode->next;
  delete temp;
  count--;

  // if queue is empty, reset 
  if (empty()) {
    rearNode = nullptr;
  }
}

// front to get element at front
template<typename T>
T Queue<T>::front() {
  if (!empty()) {
    return frontNode->data;
  }

  else {
    throw std::runtime_error("queue empty");
  }
}

// size to return number 
template<typename T>
int Queue<T>::size() {
  return count;
}

// empty to check if queue empty
template<typename T>
bool Queue<T>::empty() {
  return count == 0;
}

// display all elements
template<typename T>
void Queue<T>::display() {
  if (empty()) {
    std::cout << "queue empty\n";
    return;
  }
    
  Node<T>* current = frontNode;
  while (current) {
    std::cout << current->data << " ";
    current = current->next;
  }

  std::cout << std::endl;
}

//  move front element to butt
template<typename T>
void Queue<T>::move_to_rear() {
  if (empty() || size() == 1) {
    return; 
  }
  
  T frontValue = front();  
  pop();                   
  push(frontValue);         
}

int recursiveLastOccurrence(const std::vector<int>& arr, int target, int index) {
  // base case
  if (index < 0) {
    return -1;
  }

  // recursive case
  int restOfArray = recursiveLastOccurrence(arr, target, index - 1);

  if (restOfArray != -1) {
    return restOfArray;
  }

  if (arr[index] == target) {
    return index;
  }

  return -1;

}
