#include <iostream>
#include "Deque.h"
#include "testing.h"
using namespace std;

void testDeque1();

int main() {
  testDeque1();

  // FIXME: add 2 more test cases

  return 0;
}

void testDeque1() {
  Deque<int> d;
  bool is_correct = true;

  if (d.size() != 0) is_correct = false;
  d.push_back(5);
  d.push_front(3);
  if (d.size() != 2) is_correct = false;
  if (d.peek_front() != 3) is_correct = false;
  if (d.peek_back() != 5) is_correct = false;
  d.pop_front();
  d.pop_back();
  if (!d.empty()) is_correct = false;

  assertTrue(is_correct, "general Deque<int> operations");
}
