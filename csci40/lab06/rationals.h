#ifndef RATIONALS_H
#define RATIONALS_H

#include <string>

class Rational {
public:
  // constructor--initializes the numerator and denominator to n and d
  Rational(int n, int d);
  // creates a pretty string for our Rational
  std::string toPrettyString() const;
  // multiplies two Rationals
  Rational operator*(const Rational& other) const;
  // adds two rationals
  Rational operator+(const Rational& other) const;

private:
  // we don't let the user call simplify--it's just for us
  void simplify();

  // member variables for numerator and denominator
  int numer;
  int denom;
};

#endif