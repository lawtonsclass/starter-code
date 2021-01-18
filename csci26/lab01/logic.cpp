#include "logic.h"
using namespace std;

// Stuff I've implemented for you (don't touch pls)

And::And(shared_ptr<Formula> lhs, shared_ptr<Formula> rhs)
    : lhs(lhs), rhs(rhs) {}

set<Var> And::extractVarNames() {
  return lhs->extractVarNames() + rhs->extractVarNames();
}

Or::Or(shared_ptr<Formula> lhs, shared_ptr<Formula> rhs) : lhs(lhs), rhs(rhs) {}

set<Var> Or::extractVarNames() {
  return lhs->extractVarNames() + rhs->extractVarNames();
}

Not::Not(shared_ptr<Formula> inside) : inside(inside) {}

set<Var> Not::extractVarNames() { return inside->extractVarNames(); }

Var::Var(string name) : name(name) {}

set<Var> Var::extractVarNames() { return {name}; }

bool Var::operator<(const Var& other) const { return name < other.name; }

ostream& operator<<(ostream& os, const Var& v) {
  os << v.name;
  return os;
}

// Stuff for you to implement

// FIXME: implement And's evaluation method
// How can you use each piece of the And to determine
// if the whole thing is true or false?
// This will be a recursive method--first evaluate lhs & rhs
bool And::evaluate(map<Var, bool> var2Val) {
  return true;  // fix this
}

// FIXME: implement Or's evaluation method

// FIXME: implement Not's evaluation method

// FIXME: implement Var's evaluation method
// How can you turn a variable into a boolean?
// (This is the base case, so no recursive calls needed here)

// Given a formula f, try all the possibilities for the variables, and
// return all the ways to make it true.
set<map<Var, bool>> satSolve(Formula& f) {
  set<map<Var, bool>> solutions;

  // FIXME: call satSolveHelper with the proper values
  // use the solutions variable to store every solution you find

  return solutions;
}

// FIXME: implement this function to recursively find all the satisfying
// solutions for a Formula f. You will do this by trying both true and false for
// every variable in the formula.
//
// Explanations of the other parameters:
//   - remainingVars: the variables that you have not yet picked values for
//   - choicesForVars: the variables that you *have* picked values for (and
//   those values)
//   - satisfyingSolutions: a set of all the different variable choices
//   (represented as a map)
//                          that make the Formula f true. This is a reference,
//                          so you'll extend it each time you find a new
//                          solution.
void satSolveHelper(Formula& f, set<Var> remainingVars,
                    map<Var, bool> choicesForVars,
                    set<map<Var, bool>>& satisfyingSolutions) {
  // Base case: There are no remaining vars. This means you've made choices
  //            for everybody, and now it's time to see if those choices paid
  //            off. Check if f is true when evaluated using our current
  //            choicesForVars. If it is, add our current choicesForVars to
  //            the satisfyingSolutions.

  // Recursive case: There is at least one Var to pick a value for.
  //                 Try both true and false for it recursively.
  // Steps to follow in this case:
  //   - extract one Var (call it nextChoice) out of the remaing Vars
  //     (remainingVars.begin() is a good way to get a Var out of a set)
  //   - create a new set of remaining variables, removing the one you just
  //     chose for your nextChoice variable
  //   - recursively try to solve the Formula f using nextChoice set to true
  //   - recursively try to solve the Formula f using nextChoice set to false
}
