#include "tictactoe.h"

#include <algorithm>
#include <queue>
#include <tuple>
using namespace std;


// If we want sets of shared_ptr<GameTreeNode>s, we have to
// tell C++ how to order them in the set's underlying BST
bool CompareGameTreeNodeSharedPtr::operator()(const shared_ptr<GameTreeNode> a, 
                                              const shared_ptr<GameTreeNode> b) const {
  return a->board < b->board;
}


GameTree::GameTree() {
  // the root is an empty game board
  Board emptyBoard = {{'-', '-', '-'}, {'-', '-', '-'}, {'-', '-', '-'}};
  shared_ptr<GameTreeNode> root = make_shared<GameTreeNode>();
  root->board = emptyBoard;
  this->root = root;

  // enumerate all the possibilities of moves
  buildTree(root, 'X');
}

// FIXME: generate a subtree for all possible game moves from a certain starting Board
// The Board is inside the subtreeRoot, and it's player's turn to move
void GameTree::buildTree(shared_ptr<GameTreeNode> subtreeRoot, char player) {
  // FIXME: from the current game board at the subtreeRoot, get all the moves for the
  // player (using generateNextMoves)
  set<Board> nextMovesBoards = ???;

  // make shared_ptr<GameTreeNode>s for each of the next moves--
  // they will be the children of subtreeRoot
  set<shared_ptr<GameTreeNode>, CompareGameTreeNodeSharedPtr> nextMoves;
  for (const Board& b : nextMovesBoards) {
    // FIXME: make a new shared_ptr<GameTreeNode> for this child
    // FIXME: set the board for the child
    // FIXME: recursively build the tree at the child (and remember to 
    // swap the player for the next round!)
    // FIXME: add this child to the nextMoves
  }

  // FIXME: set the nextMoves (i.e., the children) for the current subtreeRoot
}

// It's player's turn--generate a list of all the possible next board states
// for the player.
set<Board> GameTree::generateNextMoves(const Board& currentBoard,
                                        char player) const {
  set<Board> nextMoves;

  // Return an empty set if the game is already over (i.e., the board
  // is filled or someone has won.)
  if (winner(currentBoard) != '?') return nextMoves;

  for (int row = 0; row < 3; row++) {
    for (int col = 0; col < 3; col++) {
      if (currentBoard.at(row).at(col) == '-') {
        // make a copy of the board
        Board boardCopy = currentBoard;
        // mark the player in this empty space
        boardCopy.at(row).at(col) = player;
        // add this new board to the nextMoves list
        nextMoves.insert(boardCopy);
      }
    }
  }

  return nextMoves;
}

// FIXME: if the winner is X, return 'X'
//        if the winner is O, return 'O'
//        if there is no winner yet/it's a tie, return '?'
char GameTree::winner(const Board& currentBoard) const {
  return '?';
}

int GameTree::score(std::shared_ptr<GameTreeNode> subtreeRoot,
                    char originalPlayer) const {
  return score(subtreeRoot, originalPlayer, originalPlayer);
}

// The algorithm implemented in this method is from artificial
// intelligence and is called "minimax". Lawton would be happy to talk
// to you about it in office hours!
int GameTree::score(shared_ptr<GameTreeNode> subtreeRoot, char currentPlayer,
                    char originalPlayer) const {
  // base case: subtreeRoot is a leaf
  if (subtreeRoot->nextMoves.size() == 0) {
    char whoWon = winner(subtreeRoot->board);
    if (whoWon == '?')
      return 0;
    else if (whoWon == originalPlayer)
      return 1;
    else
      return -1;
  } else {
    // recursive case: this is not a leaf (and therefore there are
    // multiple possible moves from here)
    vector<int> childScores;
    char nextPlayer = currentPlayer == 'X' ? 'O' : 'X';
    for (shared_ptr<GameTreeNode> child : subtreeRoot->nextMoves) {
      int childScore = score(child, nextPlayer, originalPlayer);
      childScores.push_back(childScore);
    }
    int minScore, maxScore;
    auto p = minmax_element(childScores.begin(), childScores.end());
    tie(minScore, maxScore) = make_tuple(*p.first, *p.second);
    int minScoreCount = count(childScores.begin(), childScores.end(), minScore);
    int maxScoreCount = count(childScores.begin(), childScores.end(), maxScore);
    if (nextPlayer == originalPlayer) {
      // maximize
      return maxScore * maxScoreCount;
    } else {
      // minimize
      return minScore * minScoreCount;
    }
  }
}

// checks if possibility *partially* matches currentBoard
// there may be more -s in possibility, but all Xs and Os match
bool GameTree::matches(const Board& possibility,
                       const Board& currentBoard) const {
  for (int row = 0; row < 3; row++) {
    for (int col = 0; col < 3; col++) {
      // a mismatch occurs if the possibility isn't '-' and the board disagree
      // on the X/O in that spot
      if (possibility.at(row).at(col) != '-' &&
          possibility.at(row).at(col) != currentBoard.at(row).at(col))
        return false;
    }
  }

  return true;
}

set<Board> GameTree::bestNextMoves(const Board& currentBoard,
                                   char player) const {
  // find the current board in the tree, starting from the root
  shared_ptr<GameTreeNode> n = root;

  while (n->board != currentBoard) {
    // match one of the children
    for (auto child : n->nextMoves) {
      if (matches(child->board, currentBoard)) {
        n = child;
        break;
      }
    }
  }

  // n now holds the currentBoard and has all the possibilities as its children

  // if this is a final state (i.e., there are no no next moves,
  // return an empty set)
  if (n->nextMoves.size() == 0) return set<Board>();

  // score each possibility for the given player, and find the max score
  double maxScore = score(*n->nextMoves.begin(), player);
  for (auto child : n->nextMoves) {
    double scoreForChild = score(child, player);
    if (scoreForChild > maxScore) maxScore = scoreForChild;
  }

  // save all boards with the max score
  set<Board> bestScoringMoves;
  for (auto child : n->nextMoves) {
    double scoreForChild = score(child, player);
    if (scoreForChild == maxScore) bestScoringMoves.insert(child->board);
  }

  return bestScoringMoves;
}

// FIXME: perform a breadth-first search on every GameTreeNode and remember the Boards
// Return a list of Boards in the order in which you saw them.
std::list<Board> GameTree::bfs() const {
  list<Board> ret;

  // FIXME: implement the BFS traversal

  return ret;
}
