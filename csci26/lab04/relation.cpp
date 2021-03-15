#include "relation.h"

// look into the following header--you can "pick apart" std::pairs using std::tie!
#include <tuple>
using namespace std;

Relation::Relation(const std::set<std::pair<int, int>>& elements)
    : elements(elements) {}

// FIXME: implement the isRelatedTo method
// return true if xRy
bool Relation::isRelatedTo(int x, int y) {
  return true;
}

// FIXME: implement the isRelatedToLeft method
// Return all y such that yRx


// FIXME: implement the isRelatedToRight method
// Return all y such that xRy


// FIXME: implement the isFunction method
// Return true if the relation is a function
// xRy means that f(x) = y
// Make sure that for every x, there is *exactly one* y for which xRy


// FIXME: implement the isInjective method
// returns true if the relation is an injective function
// xRy means that f(x) = y
// Make sure that no two x values are sharing the same y value


// FIXME: implement the isSymmetric method
// Return true if the relation is symmetric


// FIXME: implement the isTransitive method
// Return true if the relation is transitive


