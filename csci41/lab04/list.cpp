#include "list.h"

List::List() {
  // FIXME: implement the constructor
  // make list initially empty
}

// FIXME: implement List's getFirst method to get the first element

// FIXME: implement List's getLast method to get the last element

void List::push_front(Point2D data) {
  // FIXME: implement this method to add a new Node at the front of the list
  // Watch out for the special case when the list is initially empty!
}

void List::push_back(Point2D data) {
  // FIXME: implement this method to add a new Node at the end of the list
  // Watch out for the special case when the list is initially empty!
}

void List::pop_front() {
  // FIXME: implement this method to remove the Node at the front of the list
  // Watch out for the case where you remove the only Node in the list!
}

void List::pop_back() {
  // FIXME: implement this method to remove the Node at the back of the list
  // Watch out for the case where you remove the only Node in the list!
}

int List::size() {
  // FIXME: implement this method to return the number of Nodes in the list

  return -1;
}

List::~List() {
  // FIXME: implement the destructor--it should delete every Node in the list
}

List& List::operator=(const List& other) {
  // FIXME: implement the copy assignment operator
  return /* FIXME */ *static_cast<List*>(nullptr);
}

List::List(const List& other) {
  // FIXME: implement the copy constructor
}
