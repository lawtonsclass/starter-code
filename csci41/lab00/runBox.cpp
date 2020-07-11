#include <iostream>
using namespace std;

#include "box.h"

int main(int argc, char *argv[]) {
  int width;
  char c;

  cout << "Enter a width: ";
  cin >> width;
  cout << "Enter a character to draw the box with: ";
  cin >> c;

  Box b(width, c);
  cout << b;

  return 0;
}
