#include <iostream>
using namespace std;

#include "counter.h"

void assertTrue(bool b, string description) {
  if (!b) {
    cout << "FAILED: " << description << endl;
  } else {
    cout << "PASSED: " << description << endl;
  }
}

void counterTestConstruct();
void counterTestInc();
void counterTestReset();
void counterTestGetCount();

int main() {
  counterTestConstruct();
  counterTestInc();
  counterTestReset();
  counterTestGetCount();

  // FIXME: add 2 more of your own tests

  return 0;
}

void counterTestConstruct() {
  Counter c;
  Counter_construct(&c, 42);
  assertTrue(c.count == 42, "construct");
}

void counterTestInc() {
  Counter* c = new Counter;
  Counter_construct(c);
  Counter_inc(c);  // as if I said c.inc(); with classes
  Counter_inc(c);
  Counter_inc(c);
  assertTrue(c->count == 3, "inc");
  delete c;
}

void counterTestReset() {
  Counter c;
  Counter_construct(&c, 0);
  Counter_inc(&c);
  Counter_inc(&c);
  Counter_inc(&c);
  Counter_reset(&c, 42);
  Counter_inc(&c);
  assertTrue(c.count == 43, "reset");
}

void counterTestGetCount() {
  Counter c;
  Counter_construct(&c, 0);
  Counter_reset(&c, 42);
  Counter_inc(&c);
  assertTrue(Counter_getCount(&c) == 43, "getCount");
}
