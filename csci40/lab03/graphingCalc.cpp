#include <iostream>
#include <cmath>
using namespace std;

int main() {
  int choice;

  cout << "Enter 0, 1, or 2 (0 = 0.15*x^2 - 3, 1 = 0.15*x^3 + 2, 3 = 5*sin(0.25*x)): ";
  cin >> choice;
  cout << endl;

  for (int y = 12; y >= -11; y--) {
    for (int x = -38; x <= 39; x++) {
      // the current coordinate is (x, y)

      // FIXME: check if the current coordinate is in the graph that the user chose
      // (make sure to round() the y coordinate!)

      // FIXME: if it is, print a '*' character at this coordinate and continue 
      // to the next loop iteration

      // FIXME: if we don't hit a point on the graph, print either the axis line or a space
      //   - if y = 0, print a vertical axis line here
      //   - if x = 0, print a horizontal axis line here
      //   - if x = 0 and y = 0, print the axes crossing ('+')
      //   - if none of the above are true, print a single blank space (' ')
    }

    // FIXME: this is the end of a row--output a newline
  }
}