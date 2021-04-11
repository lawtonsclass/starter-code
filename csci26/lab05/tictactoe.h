#ifndef TICTACTOE_H
#define TICTACTOE_H

#include <list>
#include <memory>
#include <set>
#include <vector>

// a game board is a 2d vector of characters (containing 'X', 'O', or '-')
typedef std::vector<std::vector<char>> Board;

struct GameTreeNode;

class CompareGameTreeNodeSharedPtr {
  public:
    bool operator()(const std::shared_ptr<GameTreeNode> a, const std::shared_ptr<GameTreeNode> b) const;
};

// GameTreeNode are vertices in GameTrees
struct GameTreeNode {
  // They hold the current state of the game board
  Board board;
  // and a set of children--each child is a "reachable" game state
  // a leaf GameTreeNode has an empty nextMoves set
  std::set<std::shared_ptr<GameTreeNode>, CompareGameTreeNodeSharedPtr> nextMoves;
};

class GameTree {
 public:
  GameTree();
  std::set<Board> bestNextMoves(const Board& currentBoard, char player) const;
  std::list<Board> bfs() const;

 private:
  char winner(const Board& currentBoard) const;
  void buildTree(std::shared_ptr<GameTreeNode> subtreeRoot, char player);
  int score(std::shared_ptr<GameTreeNode> subtreeRoot,
            char originalPlayer) const;
  int score(std::shared_ptr<GameTreeNode> subtreeRoot, char currentPlayer,
            char originalPlayer) const;
  bool matches(const Board& possibility, const Board& currentBoard) const;
  std::set<Board> generateNextMoves(const Board& currentBoard,
                                     char player) const;

  std::shared_ptr<GameTreeNode> root;
};

#endif /* TICTACTOE_H */
