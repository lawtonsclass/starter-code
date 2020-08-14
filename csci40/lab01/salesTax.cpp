#include <iostream>
#include <cmath>
#include <ios> // for fixed
#include <iomanip> // for setprecision

using namespace std;

int main() {
  double price;

  cout << "Enter the price: ";
  cin >> price;

  // we're living in an alternate universe where there are no pennies or nickels,
  // so everything is rounded to the nearest 10 cents

  // Your program will calculate 7.75% tax, *rounded to the nearest dime*
  // Come to office hours and I'll give you a hint!

  // FIXME: print the following on separate lines
  //        (all #s rounded to the nearest 2 decimal places):
  //          1. the price
  //          2. the (rounded) sales tax calculated for the price, with a '+' at the front
  //          3. a line with 10 '=' characters
  //          4. the total price
  //
  // Some of these lines will begin with a space or a '+' character--see the example
  // in the write-up.

  return 0;
}