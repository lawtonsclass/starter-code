#include "vec.h"

#include <algorithm>

/********** NEW STUFF ***************************************/

// FIXME: implement this method
Vec::~Vec() {
  // delete[] our array
}

// FIXME: implement this method
Vec::Vec(const Vec& other) {
  // make a new array the same capacity as other's
  // set our current capacity/numItems to other's capacity/numItems
  // copy the contents of other's array into our own array
}

// FIXME: implement this method
Vec& Vec::operator=(const Vec& other) noexcept {
  // delete our current array
  // make a new array the same capacity as other's
  // set our current capacity/numItems to other's capacity/numItems
  // copy the contents of other's array into our own array
  // return a reference to ourselves
  return /* FIXME */ *static_cast<Vec*>(nullptr);
}

/********* OLD STUFF ***************************************/

// FIXME: copy all your method implementations from the previous lab