#include <Arduino.h>

template <typename T, int maxSize>
class MyList {
private:
  T data[maxSize];
  int front;
  int rear;
  int count;

public:
  MyList() {
    front = 0;
    rear = -1;
    count = 0;
  }

  void push(T value) {
    if (count < maxSize) {
      rear = (rear + 1) % maxSize;
      data[rear] = value;
      count++;
    } else {
      // List is at maxSize, pop the first element before pushing
      pop(); 

      // Push the new value
      rear = (rear + 1) % maxSize;
      data[rear] = value;
    }
  }

  T pop() {
    if (count > 0) {
      T value = data[front];
      front = (front + 1) % maxSize;
      count--;
      return value;
    } else {
      Serial.println("List underflow! Cannot pop element.");
      return T(); // Return a default value or handle underflow as needed
    }
  }

  int Count()
  {
    return count;
  }
};