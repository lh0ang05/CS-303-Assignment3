#include "functions.h"

int main() {
  
  Queue<int> q;

  for (int i = 1; i <= 10; i++) {
    q.push(i);
  }

  std::cout << "Queue elements after pushing 10 values: ";
  q.display();

  q.move_to_rear();
    
  std::cout << "Queue elements after moving front to rear: ";
  q.display();

  return 0;
}
