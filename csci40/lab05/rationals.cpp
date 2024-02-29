#include "rationals.h"

#include <iostream>
#include <cstdlib> // for abs
#include <string> // for to_string
using namespace std;

/*
Calculates the greatest common divisor of a and b using Euclid's algorithm.

We need this function to use in our rationalSimplify function.

This is a function our user doesn't get to see/know about, so we 
won't put it in the .h file.
*/
int GCD(int a, int b) {
  while (b != 0) {
    int newA = b;
    int newB = a % b;
    a = newA;
    b = newB;
  }

  return a;
}

/*
If the number is negative, the numer should become negative (*not* the denom).
*/
void rationalSimplify(int& numer, int& denom) {
  // FIXME: implement this function

  // FIXME: First, figure out if the rational number is negative or positive by 
  // checking 3 cases:
  // 1. if numer < 0 and denom >= 0, it's negative
  // 2. if numer >= 0 and denom < 0, it's negative
  // 3. if none of the above are true, then it's positive
  // Save that information for later, because we'll need to make numer and denom
  // be positive for a little while.


  // FIXME: convert numer and denom to positive numbers so we can use GCD


  // FIXME: simplify numer and denom using the GCD


  // FIXME: negate numer if it should be negative


  // Now you're done! You don't have to return anything from this function
  // because numer and denom were passed by reference---you just changed
  // them without needing to return anything.
}

// Multiplies two rational numbers, putting the result in resultNumer and resultDenom
void rationalTimes(int numer1, int denom1, int numer2, int denom2, int& resultNumer, int& resultDenom) {
  // FIXME: implement this function


  // be sure to simplify after performing the operation by calling your rationalSimplify function

}

/*
Return a pretty string version of a given rational number.
Use the to_string function in <string> to convert an int
to a string (so you can use the string's + operator.)

For example, if numer = 2 and denom = -44 (i.e., -1/22),
The final string you return should be exactly "-1 / 22"
If numer = 2 and denom = 4, the final string should be "1 / 2"
*/
string rationalPrettyString(int numer, int denom) {
  // FIXME: call simplify before converting

  return "stub";
}
