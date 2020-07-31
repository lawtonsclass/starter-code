#include <iostream>
#include <cstdlib> // for srand and rand
#include <ctime> // for time
#include <ios> // for fixed
#include <iomanip> // for setprecision
using namespace std;

int main() {
  srand(time(0)); // seed the random number generator

  // FIXME: generate 5 random numbers

  cout << "Random numbers between 1 and 100:" << endl;
  // FIXME: output your 5 random numbers, on 5 separate lines

  // FIXME: print the average, rounded to 2 decimal places, after the string "Average: "

  return 0;
}