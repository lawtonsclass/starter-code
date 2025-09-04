#include <cstdlib>  // for exit
#include <fstream>  // for ifstream
#include <string>   // for getline, stoi
#include <iomanip>  // for setw and setfill
#include <iostream> // lol you know what this is for
#include "vec.h"
using namespace std;

int main(int argc, char *argv[]) {
  if (argc != 2) {
    cout << "Usage: " << argv[0] << " order_file.csv" << endl;
    exit(1);
  }

  ifstream ifs(argv[1]);
  Vec prices;

  string currentLine;
  while (getline(ifs, currentLine)) {
    // FIXME: add the price from the current line into the prices Vec

    // Hint: use find, substr, and stoi to extract the prices
  }

  // FIXME: print the *sorted* prices, a line with exactly 6 '-'s, and
  // finally the total. Prices should be displayed with dollar signs
  // and cents.

  // Hint: using setw(2) and setfill('0') is one way to output the
  // cents correctly

  return 0;
}
