#include <iostream>
using namespace std;

#include "rotate3.h"

void rotate3_tests();

void assertTrue(bool b, string description) {
  if (!b) {
    cout << "FAILED: " << description << endl;
  } else {
    cout << "PASSED: " << description << endl;
  }
}

int main() {
  rotate3_tests();

  return 0;
}

void rotate3_tests() {
  int x = 42, y = 43, z = 44;
  
  rotate3(&x, &y, &z);
  assertTrue(x == 44 && y == 42 && z == 43, "rotate 42, 43, 44");

  rotate3(&x, &y, &z);
  assertTrue(x == 43 && y == 44 && z == 42, "rotate 44, 42, 43");
  
  rotate3(&x, &y, nullptr);
  assertTrue(x == 43 && y == 44 && z == 42, "rotate with nullptr");

  rotate3(&x, nullptr, &z);
  assertTrue(x == 43 && y == 44 && z == 42, "rotate with nullptr");

  rotate3(nullptr, nullptr, nullptr);
  assertTrue(x == 43 && y == 44 && z == 42, "rotate with nullptr");
}