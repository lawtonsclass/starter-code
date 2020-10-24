#ifndef HEAP_H
#define HEAP_H

#include <string>
#include <vector>

template <class T>
class PriorityQueue {
 public:
  void push(const T& x);
  T pop();
  const T& peek() const;
  bool isEmpty() const;
  int getLength() const;

 private:
  int leftChildIndex(int index) const;
  int rightChildIndex(int index) const;
  int parentIndex(int index) const;

  // the underlying "array" that holds the heap nodes
  std::vector<T> heapArray;
};

// FIXME: calculate the left child index, given a node's index
template <class T>
int PriorityQueue<T>::leftChildIndex(int index) const {
  return -42;
}

// FIXME: calculate the right child index, given a node's index
template <class T>
int PriorityQueue<T>::rightChildIndex(int index) const {
  return -42;
}

// FIXME: calculate the parent index, given a node's index
template <class T>
int PriorityQueue<T>::parentIndex(int index) const {
  return -42;
}

// FIXME: implement the push method to add a new node into the heap

// FIXME: implement the remove method
// Remove the min element, and also return a copy of it
template <class T>
T PriorityQueue<T>::pop() {
  // replace the root with the bottommost, rightmost node
  // we will return the node you just "popped" at the very end of this method

  // remove the bottommost, rightmost node

  // bubble the new root down to where it needs to be

  // return a copy of the value you removed
}

// FIXME: implement the peek method to return a reference to the current min

// FIXME: implement the isEmpty method to return whether the heap is empty

// FIXME: implement the getLength method to get the size of the heap

// The following is not a method--you'll *use* the PriorityQueue class
// FIXME: sort the input vector (from smallest to biggest) using a
// PriorityQueue<T>
template <class T>
std::vector<T> heapSort(const std::vector<T>& v) {
  std::vector<T> result;

  return result;
}

#endif /* HEAP_H */
