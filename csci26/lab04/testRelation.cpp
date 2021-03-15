#include <iostream>
using namespace std;

#include "relation.h"
#include "testing.h"

void testRelation1();
void testRelation2();
void testRelation3();
void testRelation4();
void testRelation5();
void testRelation6();

int main() {
  testRelation1();
  testRelation2();
  testRelation3();
  testRelation4();
  testRelation5();
  testRelation6();

  return 0;
}

void testRelation1() {
  // an injective function
  set<pair<int, int>> elems = {
    {0, 2},
    {1, 4},
    {2, 6},
    {3, 8},
    {4, 10},
    {5, 12},
    {6, 14},
    {7, 16},
    {8, 18},
    {9, 20},
    {10, 22}
  };
  
  Relation r(elems);

  assertTrue(r.isFunction() && r.isInjective(), "injective function");
}

void testRelation2() {
  // a non-injective function
  set<pair<int, int>> elems = {
    {-4, 16},
    {-3, 9},
    {-2, 4},
    {-1, 1},
    {0, 0},
    {1, 1},
    {2, 4},
    {3, 9},
    {4, 16}
  };
  
  Relation r(elems);

  assertTrue(r.isRelatedTo(1, 1) &&
             r.isRelatedTo(4, 16) &&
             !r.isRelatedTo(16, 4) &&
             r.isRelatedToLeft(16) == set<int>{-4, 4} &&
             r.isRelatedToRight(2) == set<int>{4},
             "isRelatedTo operations (non-injective function)");
  assertTrue(r.isFunction() && !r.isInjective(), "non-injective function");
}

void testRelation3() {
  // a symmetric and transitive relation
  set<pair<int, int>> elems = {
    {1, 1},
    {1, 4},
    {4, 4},
    {4, 1},

    {2, 2},
    {2, 3},
    {2, 6},
    {3, 2},
    {3, 3},
    {3, 6},
    {6, 2},
    {6, 3},
    {6, 6}
  };
  
  Relation r(elems);

  assertTrue(r.isRelatedTo(1, 4) &&
             r.isRelatedTo(6, 2) &&
             !r.isRelatedTo(4, 5) &&
             r.isRelatedToLeft(6) == set<int>{2, 3, 6} &&
             r.isRelatedToRight(1) == set<int>{1, 4},
             "isRelatedTo operations (symmetric and transitive)");
  assertTrue(r.isSymmetric() && r.isTransitive() && !r.isFunction(), "symmetric and transitive");
}

void testRelation4() {
  // a symmetric but not transitive relation
  set<pair<int, int>> elems = {
    {1, 1},
    {1, 2},
    {1, 5},
    {2, 1},
    {2, 2},
    {2, 5},
    {2, 6},
    {5, 1},
    {5, 2},
    {5, 5},
    {5, 6},
    {6, 2},
    {6, 5},
    {6, 6}
  };
  
  Relation r(elems);

  assertTrue(r.isSymmetric() && !r.isTransitive(), "symmetric but not transitive");
}

void testRelation5() {
  // a transitive but not symmetric relation
  set<pair<int, int>> elems = {
    {1, 2},
    {1, 3},
    {1, 5},
    {1, 6},
    {2, 3},
    {2, 5},
    {2, 6},
    {4, 4},
    {5, 5},
    {5, 6},
    {6, 5},
    {6, 6}
  };
  
  Relation r(elems);

  assertTrue(!r.isSymmetric() && r.isTransitive(), "transitive but not symmetric");
}

void testRelation6() {
  // a relation that is neither symmetric nor transitive
  set<pair<int, int>> elems = {
    {1, 4},
    {4, 4},
    {4, 1},

    {2, 2},
    {2, 3},
    {2, 6},
    {3, 2},
    {3, 3},
    {3, 6},
    {6, 3},
    {6, 6}
  };
  
  Relation r(elems);

  assertTrue(!r.isSymmetric() && !r.isTransitive(), "neither symmetric nor transitive");
}
