#include <cctype>
#include <iostream>
#include <string>
using namespace std;

#include "recursiveFuncs.h"
bool isPalindromeRecursive(const string str);

// isPalindrome IS THE ONE NON-RECURSIVE FUNCTION YOU'LL WRITE
// isPalindrome is called a "helper" function--it'll clean up
// the argument and then call your recursive palindrome-checking function

// Returns true if str is a palindrome.
// str might have spaces or capitals, and those should *not* be
// considered when looking for a palindrome. Therefore, the string
// "aa aA" *is* a palindrome, because that simplifies to "aaaa".
bool isPalindrome(const string str) {
  // FIXME: create a new version of str that is "cleaned up"
  // i.e., one that has no spaces, and where all capitals have been converted

  // FIXME: return the result of your isPalindromeRecursive function
  // on the preprocessed string

  return false;
}

////////////////////////////////////////////////////////////
// All function implementations below must use recursion. //
////////////////////////////////////////////////////////////

// FIXME: recursively checks whether a preprocessed string is a palindrome
bool isPalindromeRecursive(const string str) {
  return false;
}

// FIXME: sum all the digits of a number.
// The number n will never be negative.
// For example: sumDigits(123) should return 6, because 1+2+3=6.
int sumDigits(int n) {
  return -42;
}

// FIXME: return the length of the C-string s.
// For example, stringLength("asdf") should return 4.
// The length of an empty string is 0.
// How do you extract a smaller string from s? Hint: remember that s
// is a pointer to the first character in the string.
int stringLength(const char* s) {
  return -42;
}
