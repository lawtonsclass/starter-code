#ifndef STACK_H
#define STACK_H

#include "Deque.h"

// we'll make a Stack class using our Deque class

template <class T>
class Stack {
public:
  void push(const T& item);
  T pop();
  T& peek();
  bool empty() const;
  int size() const;
private:
  Deque<T> d;
};

// FIXME: implement the member functions


#endif /* STACK_H */
