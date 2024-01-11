#include <iostream>
using namespace std;

#include "logic.h"
#include "testing.h"

void testEval();
void testSAT0();
void testSAT1();
void testSAT2();
void testSAT3();

int main() {
  testEval();
  testSAT0();
  testSAT1();
  testSAT2();
  testSAT3();

  return 0;
}

// helper functions to make Formulas
shared_ptr<And> _And(shared_ptr<Formula> lhs, shared_ptr<Formula> rhs) {
  return make_shared<And>(lhs, rhs);
}

shared_ptr<Or> _Or(shared_ptr<Formula> lhs, shared_ptr<Formula> rhs) {
  return make_shared<Or>(lhs, rhs);
}

shared_ptr<Not> _Not(shared_ptr<Formula> inside) {
  return make_shared<Not>(inside);
}

shared_ptr<Var> _Var(const string& s) { return make_shared<Var>(s); }

// helper function to print all the solutions our satSolve function finds
void printSolutions(set<map<Var, bool>>& solutions) {
  int i = 1;
  for (auto m : solutions) {
    cout << "Solution " << i << ":\n";

    for (auto varValPair : m) {
      cout << "  " << varValPair.first << " -> " << varValPair.second << endl;
    }

    i++;
  }
  cout << endl;
}

// the actual tests:

void testEval() {
  // p_or_q_and_not_r represents (p ∨ (q ∧ ¬r))
  shared_ptr<Var> p = make_shared<Var>("p");
  shared_ptr<Var> q = make_shared<Var>("q");
  shared_ptr<Var> r = make_shared<Var>("r");
  shared_ptr<Not> not_r = make_shared<Not>(r);
  shared_ptr<And> q_and_not_r = make_shared<And>(q, not_r);
  shared_ptr<Or> p_or_q_and_not_r = make_shared<Or>(p, q_and_not_r);

  map<Var, bool> var2Val1 = {{*p, false}, {*q, true}, {*r, false}};
  // try evaluating the formula with p = false, q = true, and r = false
  assertTrue(p_or_q_and_not_r->evaluate(var2Val1) == true, "false || (true && !false)");

  map<Var, bool> var2Val2 = {{*p, false}, {*q, false}, {*r, false}};
  // try evaluating the formula with p = false, q = false, and r = false
  assertTrue(p_or_q_and_not_r->evaluate(var2Val2) == false, "false || (false && !false)");
  
  cout << endl;
}

//  p
void testSAT0() {
  cout << "Test 0" << endl;
  cout << "======" << endl;

  shared_ptr<Formula> f = _Var("p");
  set<map<Var, bool>> solutions = satSolve(*f);

  printSolutions(solutions);
}

// ¬p ∨ q
void testSAT1() {
  cout << "Test 1" << endl;
  cout << "======" << endl;

  shared_ptr<Formula> f = _Or(_Not(_Var("p")), _Var("q"));
  set<map<Var, bool>> solutions = satSolve(*f);

  printSolutions(solutions);
}

// (p ∧ (q ∧ ¬r)) ∨ (p ∧ (¬q ∧ ¬r))
void testSAT2() {
  cout << "Test 2" << endl;
  cout << "======" << endl;

  shared_ptr<Formula> f =
      _Or(_And(_Var("p"), _And(_Var("q"), _Not(_Var("r")))),
          _And(_Var("p"), _And(_Not(_Var("q")), _Not(_Var("r")))));
  set<map<Var, bool>> solutions = satSolve(*f);

  printSolutions(solutions);
}

// (p ∨ q) ∨ ((¬r ∨ s) ∨ (t ∧ ¬u))
void testSAT3() {
  cout << "Test 3" << endl;
  cout << "======" << endl;

  shared_ptr<Formula> f = _Or(
      _Or(_Var("p"), _Var("q")),
      _Or(_Or(_Not(_Var("r")), _Var("s")), _And(_Var("t"), _Not(_Var("u")))));
  set<map<Var, bool>> solutions = satSolve(*f);

  printSolutions(solutions);
}
