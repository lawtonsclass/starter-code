#include "vec.h"

#include <algorithm>

Vec::Vec() {
  // FIXME: implement this method
  // make arr a size 1 array to start with
  // so, capacity is 1 because the array can hold 1 thing
  // there's nothing in the Vec yet so the numItems is 0
}

// doubles the array capacity
void Vec::resize() {
  // FIXME: implement this method

  // Double the current capacity. This means we need to make a new
  // array on the heap and copy all the existing stuff into it.

  // remember to delete[] the old array and increase the capacity
  // memeber variable appropriately!
}

void Vec::push_back(int x) {
  // FIXME: implement this method
  // If we have enough space, just add to the next available location.
  // If not, use the resize function to double the space and then add 
  // to the next available location.
}

// return the number of items in the Vec
int Vec::size() const {
  // FIXME: implement this method
  return 42;
}

// return the element at index i
// (it's a reference so that it can potentially be changed)
int& Vec::at(int i) {
  // FIXME: implement this method
  int fixme;
  return fixme;
}

void Vec::sort() {
  // sort the inner array using std::sort in <algorithm>
  std::sort(arr, arr + numItems);
}
