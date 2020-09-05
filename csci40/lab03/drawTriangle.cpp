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
    // You should exit with a return code of 1.

    // The autograder output will look a little different in this case because
    // it sees the nonzero return code, but there's nothing extra you need to
    // print other than the "Invalid size." above.
  }

  // FIXME: print a (right-leaning) right triangle of the requested size
  // Hint: what is the value of (total spaces) + (total stars) on each line?

  return 0;
}
