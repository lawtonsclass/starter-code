#include <iostream>
#include "vec.h"
#include "testing.h"
using namespace std;

void testVecCopyConstructor();
void testVecCopyAssignment();

int main() {
  testVecCopyConstructor();
  testVecCopyAssignment();

  // FIXME: Add 4 more tests

  return 0;
}

void testVecCopyConstructor() {
  Vec v1;
  v1.push_back(1);
  v1.push_back(2);
  v1.push_back(3);
  Vec v2(v1);
  v1.push_back(4);
  v1.push_back(5);
  v2.push_back(-4);
  v2.push_back(-5);

  assertTrue(v1.at(0) == v2.at(0) &&
             v1.at(1) == v2.at(1) &&
             v1.at(2) == v2.at(2) &&
             v1.at(3) == 4 &&
             v2.at(3) == -4 &&
             v1.at(4) == 5 &&
             v2.at(4) == -5,
             "copy constructor");
}

void testVecCopyAssignment() {
  Vec v1, v2;
  v1.push_back(1);
  v1.push_back(2);
  v2.push_back(3);
  v2.push_back(4);

  v2 = v1;

  v2.push_back(5);
  v1.push_back(3);

  assertTrue(v2.at(0) == 1 &&
             v2.at(1) == 2 &&
             v2.at(2) == 5 &&
             v1.at(0) == 1 &&
             v1.at(1) == 2 &&
             v1.at(2) == 3 &&
             v2.size() == 3 &&
             v1.size() == 3,
             "copy assignment operator");
}
