#include <iostream>
using namespace std;

int main() {
  int size;
  cout << "Enter size: ";
  cin >> size;
  cout << endl;

  if (size < 0) {
    cout << "Invalid size." << endl;
    // FIXME: stop the program if the size was invalid.
    // You should exit the program with exit or return.
  }

  // FIXME: print a (right-leaning) right triangle of the requested size
  // Hint: what is the value of (total spaces) + (total stars) on each line?

  return 0;
}
