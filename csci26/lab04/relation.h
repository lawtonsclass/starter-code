#ifndef RELATION_H
#define RELATION_H

#include <set>
#include <utility>

// represents a binary relation on two (potentially different) subsets of ℤ
class Relation {
 public:
  Relation(const std::set<std::pair<int, int>>& elements);

  // returns true if xRy
  bool isRelatedTo(int x, int y);

  // find all y such that yRx
  std::set<int> isRelatedToLeft(int x);
  // find all y such that xRy
  std::set<int> isRelatedToRight(int x);

  // returns true if the relation is a function
  bool isFunction();
  // returns true if the relation is an injective function
  bool isInjective();
  // (we can't test for surjectivity unless we save the codomain in
  // another member variable)

  // returns true if the relation is symmetric
  bool isSymmetric();
  // returns true if the relation is transitive
  bool isTransitive();
  // (we can't test for reflexivity unless we save both sets in
  // another member variable)

 private:
  // Each pair (x, y) means xRy
  std::set<std::pair<int, int>> elements;
};

#endif /* end of include guard: RELATION_H */
