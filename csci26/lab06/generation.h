#ifndef GENERATION_H
#define GENERATION_H

#include <algorithm>
#include <iterator>
#include <stdexcept>
#include <utility>
#include <vector>

// FIXME: implement the NextPerm function from the book.
// Instead of taking n separate arguments, it takes a vector of n elements.
// Example: nextPerm({1, 5, 4, 2, 3, 6}) should return {1, 5, 4, 2, 6, 3}.
// The tests will never call nextPerm on the last permutation, so you
// can handle that case however you want.
template <class T>
std::vector<T> nextPerm(const std::vector<T>& items) {

}

// FIXME: Implement GenLexPermutations from the book.
// Instead of permuting {1, 2, 3, ..., n}, we will permute a vector of
// elements of type T (as long as Ts can be compared/sorted).
// Instead of outputting each permutation: add them all to a vector in
// order, and return that vector as the result.
// Precondition (you can assume this): items contains no duplicates.
template <class T>
std::vector<std::vector<T>> generatePermutations(const std::vector<T>& items) {
  // Hint: the first permutation is the *sorted* items vector, and the
  // last permutation is the *reverse sorted* items vector
}

// FIXME: Implement the NextSubset function from the book.
// The tests will never call nextSubset on the last subset, so you
// can handle that case however you want.
std::vector<int> nextSubset(int n, const std::vector<int>& S) {

}

// FIXME: Implement the GenLexSubsets function from the book.
// Instead of outputting each subset: add them to a vector in order
// and return that vector as the result.
std::vector<std::vector<int>> genLexSubsets(int r, int n) {

}

// Creates all subsets of size `size` from a given vector of items.
// Precondition: items contains no duplicates.
template <class T>
std::vector<std::vector<T>> generateCombinations(const std::vector<T>& items,
                                                 int size) {
  std::vector<std::vector<T>> combs;

  std::vector<std::vector<int>> indices = genLexSubsets(size, items.size());
  for (auto v : indices) {
    std::vector<T> comb;
    std::transform(v.begin(), v.end(), back_inserter(comb),
                   [&](int idx) { return items.at(idx - 1); });
    combs.push_back(comb);
  }

  return combs;
}

#endif /* GENERATION_H */
