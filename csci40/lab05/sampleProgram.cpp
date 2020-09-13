#include <iostream>
#include "rationals.h"
using namespace std;

int main() {
  int numer1, denom1, numer2, denom2;
  cout << "Enter first numerator: ";
  cin >> numer1;
  cout << "Enter first denominator: ";
  cin >> denom1;
  cout << "Enter second numerator: ";
  cin >> numer2;
  cout << "Enter second denominator: ";
  cin >> denom2;

  cout << endl;

  rationalSimplify(numer1, denom1);

  cout << "Simplified first number: " << rationalPrettyString(numer1, denom1) << endl;
  cout << "Second number: " << rationalPrettyString(numer2, denom2) << endl;

  int resultN, resultD;
  rationalTimes(numer1, denom1, numer2, denom2, resultN, resultD);

  cout << "First number * Second number: " << rationalPrettyString(resultN, resultD) << endl;

  return 0;
}