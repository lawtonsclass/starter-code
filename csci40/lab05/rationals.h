#ifndef RATIONALS_H
#define RATIONALS_H

#include <string>

// see the .cpp file for a more thorough description of the functions

// convert a rational # to a nice-looking string
std::string rationalPrettyString(int numer, int denom);

// multiply two rational numbers
void rationalTimes(int numer1, int denom1, int numer2, int denom2, int& resultNumer, int& resultDenom);

// simplify a rational # to lowest terms
void rationalSimplify(int& numer, int& denom);

#endif