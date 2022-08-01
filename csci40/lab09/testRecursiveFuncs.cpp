#include <iostream>
#include <string>
using namespace std;

#include "recursiveFuncs.h"

void assertTrue(bool b, string description) {
  if (!b) {
    cout << "FAILED: " << description << endl;
  } else {
    cout << "PASSED: " << description << endl;
  }
}

void testPalindrome();
void testSumDigits();
void testStringLength();

int main() {
  testPalindrome();
  testSumDigits();
  testStringLength();

  return 0;
}

void testPalindrome() {
  assertTrue(isPalindrome("a"), "\"a\" is a palindrome");
  assertTrue(isPalindrome("abcddcba"), "\"abcddcba\" is a palindrome");
  assertTrue(isPalindrome("RaCe car"), "\"RaCe car\" is a palindrome");
  assertTrue(!isPalindrome("daffodil"), "\"daffodil\" is not a palindrome");
}

void testSumDigits() {
  assertTrue(sumDigits(123) == 6, "sumDigits(123)");
  assertTrue(sumDigits(4873) == 22, "sumDigits(4873)");
  assertTrue(sumDigits(0) == 0, "sumDigits(0)");
}

void testStringLength() {
  assertTrue(stringLength("asdf") == 4, "stringLength(asdf)");
  assertTrue(stringLength("Hello, world!") == 13,
             "stringLength(Hello, world!)");
  assertTrue(stringLength("a") == 1, "stringLength(a)");
  assertTrue(stringLength("") == 0, "stringLength(empty string)");
}
