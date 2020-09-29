#ifndef STACK_H
#define STACK_H

#include "Deque.h"

// we'll make a Stack class using our Deque class

template <class T>
class Stack {
public:
  void push(const T& item);
  // for pop, you will also return a copy of the value you pop
  T pop();
  // "peek" means "top"--I think it's a silly name, but we might as well 
  // be consistent with your textbook
  T& peek(); 
  bool empty() const;
  int size() const;
private:
  Deque<T> d;
};

// FIXME: implement the member functions


#endif /* STACK_H */
