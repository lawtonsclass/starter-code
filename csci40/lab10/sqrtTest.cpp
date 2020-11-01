#include <iostream>
#include <cmath>
using namespace std;

#include "sqrt.h"
#include "testing.h"

class squareRootTests {
 public:
  void squareRootTest1();
  void squareRootTest2();
  void squareRootTest3();
};

int main() {
  squareRootTests tests;

  tests.squareRootTest1();
  tests.squareRootTest2();
  tests.squareRootTest3();

  // FIXME: Write 4 more tests and run them here
  // Follow my pattern and add them to the squareRootTests class

  return 0;
}

void squareRootTests::squareRootTest1() {
  assertTrue(abs(squareRoot(2) - 1.4142136) < 0.0001, "squareRoot(2)");
}

void squareRootTests::squareRootTest2() {
  assertTrue(abs(squareRoot(0.5) - 0.7071068) < 0.0001, "squareRoot(0.5)");
}

void squareRootTests::squareRootTest3() {
  bool threwException = false;
  try {
    squareRoot(-1.0);
  } catch (runtime_error& e) {
    threwException = true;
  }
  assertTrue(threwException, "squareRoot(-1.0)");
}