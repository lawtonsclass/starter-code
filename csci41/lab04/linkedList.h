#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "point2D.h"

struct Node {
  Point2D data;
  Node* next;
};

class LinkedList {
public:

  LinkedList();
  ~LinkedList();
  LinkedList& operator=(const LinkedList& other);
  LinkedList(const LinkedList& other);

  const Node* getFirst();
  const Node* getLast();

  void push_front(Point2D data);
  void push_back(Point2D data);
  void pop_front();
  void pop_back();
  int size();

private:

  Node* first;
  Node* last;
};

#endif /* LINKEDLIST_H */
