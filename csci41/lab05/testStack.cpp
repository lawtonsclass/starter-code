#include <iostream>
#include "Stack.h"
#include "testing.h"
using namespace std;

void testStack1();

int main() {
  testStack1();

  // FIXME: add 2 more test cases

  return 0;
}

void testStack1() {
  Stack<int> s;
  bool is_correct = true;

  if (s.size() != 0) is_correct = false;
  s.push(5);
  s.push(3);
  if (s.size() != 2) is_correct = false;
  if (s.peek() != 3) is_correct = false;
  if (s.size() != 2) is_correct = false;
  if (s.pop() != 3) is_correct = false;
  if (s.peek() != 5) is_correct = false;
  if (s.pop() != 5) is_correct = false;
  if (!s.empty()) is_correct = false;

  assertTrue(is_correct, "general Stack<int> operations");
}
