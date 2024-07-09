#include <fstream>
#include <iostream>
#include <cstdlib>

#include "etchASketch.h"
using namespace std;

int main(int argc, char *argv[]) {
  if (argc != 2) {
    cout << "Usage: " << argv[0] << " inputFile" << endl;
    exit(1);
  }

  // FIXME: open up the file whose name is in argv[1]

  // FIXME: create an EtchASketch object

  // FIXME: read the file, one character at a time, and make our
  // etch-a-sketch move in a given direction:
  // if you read a 'l', make the EtchASketch object move left, 
  // if you read a 'r', make the EtchASketch object move right, etc.
  // if you read an *invalid* character (not in {l, r, u, d}), skip to the next one

  // FIXME: print the pretty drawing that you built up in the EtchASketch object

  return 0;
}
