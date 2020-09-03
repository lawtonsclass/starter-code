#include "linkedList.h"

LinkedList::LinkedList() {
  // FIXME: implement the constructor
  // make list initially empty
}

// FIXME: implement LinkedList's getFirst method to get the first element

// FIXME: implement LinkedList's getLast method to get the last element

void LinkedList::push_front(Point2D data) {
  // FIXME: implement this method to add a new Node at the front of the list
  // Watch out for the special case when the list is initially empty!
}

void LinkedList::push_back(Point2D data) {
  // FIXME: implement this method to add a new Node at the end of the list
  // Watch out for the special case when the list is initially empty!
}

void LinkedList::pop_front() {
  // FIXME: implement this method to remove the Node at the front of the list
  // Watch out for the case where you remove the only Node in the list!
}

void LinkedList::pop_back() {
  // FIXME: implement this method to remove the Node at the back of the list
  // Watch out for the case where you remove the only Node in the list!
}

int LinkedList::size() {
  // FIXME: implement this method to return the number of Nodes in the list

  return -1;
}

LinkedList::~LinkedList() {
  // FIXME: implement the destructor--it should delete every Node in the list
}

LinkedList& LinkedList::operator=(const LinkedList& other) {
  // FIXME: implement the copy assignment operator
  return /* FIXME */ *static_cast<LinkedList*>(nullptr);
}

LinkedList::LinkedList(const LinkedList& other) {
  // FIXME: implement the copy constructor
}
