#include <fstream>
#include <iostream>
#include <sstream>
using namespace std;

#include "testing.h"
#include "tictactoe.h"

string prettyBoard(const Board& b) {
  string res = "";

  for (int row = 0; row < 3; row++) {
    for (int col = 0; col < 3; col++) {
      res += ' ';
      res += b.at(row).at(col);
      res += ' ';
      if (col < 2) res += '|';
    }
    res += '\n';
    if (row < 2) res += "---+---+---\n";
  }

  return res;
}

void testTicTacToe1(GameTree& t);
void testTicTacToe2(GameTree& t);
void testTicTacToe3(GameTree& t);
void testTicTacToe4(GameTree& t);

int main(int argc, char* argv[]) {
  GameTree t;

  if (argc == 2 && string(argv[1]) == "runtests") {
    testTicTacToe1(t);
    testTicTacToe2(t);
    testTicTacToe3(t);
    testTicTacToe4(t);
    return 0;
  }

  char c11, c12, c13, c21, c22, c23, c31, c32, c33;
  char whoseTurnIsIt;

  cout << "Enter the board: ";
  cin >> c11 >> c12 >> c13 >> c21 >> c22 >> c23 >> c31 >> c32 >> c33;
  cout << "Enter the player whose turn it is: ";
  cin >> whoseTurnIsIt;

  Board b = {{c11, c12, c13}, {c21, c22, c23}, {c31, c32, c33}};

  cout << "Current board:\n";
  cout << prettyBoard(b);

  cout << endl;
  cout << "Best next moves:\n";

  auto nextMoves = t.bestNextMoves(b, whoseTurnIsIt);
  if (nextMoves.empty()) {
    cout << "(No next moves)\n";
  } else {
    for (const auto& move : nextMoves) {
      cout << prettyBoard(move);
      cout << endl;
    }
  }

  return 0;
}

void testTicTacToe1(GameTree& t) {
  list<Board> levelOrder = t.bfs();
  stringstream ss;
  for (auto& b : levelOrder) {
    for (auto& v : b) {
      for (auto c : v) {
        ss << c;
      }
    }
    ss << endl;
  }

  ifstream ifs("levelOrderReference");
  string reference = "";
  char c;
  while (ifs.get(c)) {
    reference += c;
  }

  assertTrue(reference == ss.str(), "game tree level order");
}

// X O -
// X - O
// - - -
void testTicTacToe2(GameTree& t) {
  Board b = {{'X', 'O', '-'}, {'X', 'O', '-'}, {'-', '-', '-'}};
  auto nextMoves = t.bestNextMoves(b, 'X');
  assertTrue(nextMoves.size() == 1 && prettyBoard(*nextMoves.begin()) ==
                                          " X | O | - \n"
                                          "---+---+---\n"
                                          " X | O | - \n"
                                          "---+---+---\n"
                                          " X | - | - \n",
             "XO-X-O---");
}

// X - -
// X X -
// O O -
void testTicTacToe3(GameTree& t) {
  Board b = {{'X', '-', '-'}, {'X', 'X', '-'}, {'O', 'O', '-'}};
  auto nextMoves = t.bestNextMoves(b, 'O');
  assertTrue(nextMoves.size() == 1 && prettyBoard(*nextMoves.begin()) ==
                                          " X | - | - \n"
                                          "---+---+---\n"
                                          " X | X | - \n"
                                          "---+---+---\n"
                                          " O | O | O \n",
             "X--XX-OO-");
}

// X - -
// X X -
// O O O
void testTicTacToe4(GameTree& t) {
  Board b = {{'X', '-', '-'}, {'X', 'X', '-'}, {'O', 'O', 'O'}};
  auto nextMoves = t.bestNextMoves(b, 'X');
  assertTrue(nextMoves.size() == 0, "X--XX-OOO");
}
