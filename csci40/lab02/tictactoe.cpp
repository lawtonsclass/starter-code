#include <iostream>

using namespace std;

int main() {
  cout << "Enter the board (left to right, top to bottom): ";

  // FIXME: get 9 characters from the user. 
  // Call the board characters b11, b12, b13, b21, b22, b23, b31, b32, and b33
  // This is what they represent:
  //   b11 | b12 | b13
  //   ----+-----+----
  //   b21 | b22 | b23
  //   ----+-----+----
  //   b31 | b32 | b33
  // Each char will be separated by any kind of whitespace
  // (e.g., spaces, tabs, newlines) and will represent the
  // game board.

  // FIXME: determine if the winner is 'X', 'O', or if it is a tie

  char winner = '?';

  // check rows for a winner
  // there will only ever be one, so else ifs would work too

  if (b11 == b12 && b12 == b13) {
    // since b11 is the same as b12 and b13, we can just save the winner as b11
    winner = b11;
  }

  if (b21 == b22 && b22 == b23) {
    winner = b21;
  }

  if (b31 == b32 && b32 == b33) {
    winner = b31;
  }

  // FIXME: check columns for a winner

  // FIXME: check diagonals for a winner
  
  // FIXME: if X wins, print out a line saying "X wins!" (and similarly for if O wins)
  // FIXME: if it's a tie, print out a line saying "It's a tie!"

  return 0;
}