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

class SimpleTests {
 public:
  static void testWinner(GameTree& t);
  static void testBuildTree(GameTree& t);
};

void testTicTacToe1(GameTree& t);
void testTicTacToe2(GameTree& t);
void testTicTacToe3(GameTree& t);
void testTicTacToe4(GameTree& t);

int main(int argc, char* argv[]) {
  GameTree t;

  if (argc == 2 && string(argv[1]) == "runtests") {
    SimpleTests::testWinner(t);
    SimpleTests::testBuildTree(t);

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

void SimpleTests::testWinner(GameTree& t) {
  bool is_correct = true;

  Board b1 = {{'-', 'O', 'X'}, {'O', 'X', 'O'}, {'X', 'O', '-'}};
  is_correct = t.winner(b1) == 'X' ? true : false;

  Board b2 = {{'-', 'X', 'O'}, {'X', 'X', 'O'}, {'-', 'X', 'O'}};
  is_correct = t.winner(b2) == 'O' ? true : false;

  Board b3 = {{'X', 'O', '-'}, {'-', '-', 'X'}, {'O', '-', '-'}};
  is_correct = t.winner(b3) == '?' ? true : false;

  assertTrue(is_correct, "testWinner");
}

void SimpleTests::testBuildTree(GameTree& t) {
  bool is_correct = true;

  // this test will start with the following board:
  //   X | O | O 
  //  ---+---+---
  //   O | X | - 
  //  ---+---+---
  //   X | - | - 
  // (and it's X's turn to move)

  Board startingBoard = {{'X', 'O', 'O'}, {'O', 'X', '-'}, {'X', '-', '-'}};

  // let's build a tree starting there
  shared_ptr<GameTreeNode> root = make_shared<GameTreeNode>();
  root->board = startingBoard;
  t.buildTree(root, 'X');

  // the following next moves are possible:
  //      (1)          (2)          (3)
  //   X | O | O    X | O | O    X | O | O 
  //  ---+---+---  ---+---+---  ---+---+---
  //   O | X | -    O | X | -    O | X | X 
  //  ---+---+---  ---+---+---  ---+---+---
  //   X | - | X ,  X | X | - ,  X | - | - 

  // Let's make sure they were added
  Board nextMove1 = {{'X', 'O', 'O'}, {'O', 'X', '-'}, {'X', '-', 'X'}};
  Board nextMove2 = {{'X', 'O', 'O'}, {'O', 'X', '-'}, {'X', 'X', '-'}};
  Board nextMove3 = {{'X', 'O', 'O'}, {'O', 'X', 'X'}, {'X', '-', '-'}};
  // the following three lines are disgusting, but they work
  shared_ptr<GameTreeNode> subtree1 = *root->nextMoves.begin();
  shared_ptr<GameTreeNode> subtree2 = *++root->nextMoves.begin();
  shared_ptr<GameTreeNode> subtree3 = *++++root->nextMoves.begin();
  is_correct = subtree1->board == nextMove1 ? true : false;
  is_correct = subtree2->board == nextMove2 ? true : false;
  is_correct = subtree3->board == nextMove3 ? true : false;

  // child board #1 is a winner, so it should have no children of its own
  is_correct = subtree1->nextMoves.size() == 0 ? true : false;

  // child board #2 should have two children:
  //     (2.1)        (2.2)
  //   X | O | O    X | O | O 
  //  ---+---+---  ---+---+---
  //   O | X | -    O | X | - 
  //  ---+---+---  ---+---+---
  //   X | X | O ,  X | X | O 
  Board nextMove2_1 = {{'X', 'O', 'O'}, {'O', 'X', '-'}, {'X', 'X', 'O'}};
  Board nextMove2_2 = {{'X', 'O', 'O'}, {'O', 'X', 'O'}, {'X', 'X', '-'}};
  shared_ptr<GameTreeNode> subtree2_1 = *subtree2->nextMoves.begin();
  shared_ptr<GameTreeNode> subtree2_2 = *++subtree2->nextMoves.begin();
  is_correct = subtree2_1->board == nextMove2_1 ? true : false;
  is_correct = subtree2_2->board == nextMove2_2 ? true : false;
  
  // child board #3 should also have two children:
  //     (3.1)        (3.2)
  //   X | O | O    X | O | O 
  //  ---+---+---  ---+---+---
  //   O | X | X    O | X | X 
  //  ---+---+---  ---+---+---
  //   X | - | O ,  X | O | - 
  Board nextMove3_1 = {{'X', 'O', 'O'}, {'O', 'X', 'X'}, {'X', '-', 'O'}};
  Board nextMove3_2 = {{'X', 'O', 'O'}, {'O', 'X', 'X'}, {'X', 'O', '-'}};
  shared_ptr<GameTreeNode> subtree3_1 = *subtree3->nextMoves.begin();
  shared_ptr<GameTreeNode> subtree3_2 = *++subtree3->nextMoves.begin();
  is_correct = subtree3_1->board == nextMove3_1 ? true : false;
  is_correct = subtree3_2->board == nextMove3_2 ? true : false;

  assertTrue(is_correct, "testBuildTree");
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
