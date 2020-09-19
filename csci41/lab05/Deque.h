#ifndef DEQUE_H
#define DEQUE_H

#include <list>

// a deque using a std::list

template <class T>
class Deque {
public:
  void push_front(const T& item);
  void push_back(const T& item);
  void pop_front();
  void pop_back();
  T& peek_front(); // gets the front element
  T& peek_back();  // gets the back element
  bool empty() const;
  int size() const;
private:
  std::list<T> l;
};

// FIXME: implement the member functions (implement them below)
// Remember that we can't use a .cpp file for templates

// here's everything except the body of the push_front function
template <class T>
void Deque<T>::push_front(const T& item) {
  // FIXME
}

// add in the rest



#endif /* DEQUE_H */
