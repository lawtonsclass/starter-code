#ifndef LOGIC_H
#define LOGIC_H

#include <algorithm>
#include <iostream>
#include <iterator>
#include <map>
#include <memory>
#include <set>

// combine the elements of two sets into a new set
template <class T>
std::set<T> operator+(const std::set<T>& a, const std::set<T>& b) {
  std::set<T> res;
  std::set_union(a.begin(), a.end(), b.begin(), b.end(),
                 std::inserter(res, res.begin()));
  return res;
}

class Var;

// Base class for logical formulae
class Formula {
 public:
  // evaluates the Formula with a given assignment of Vars to values
  virtual bool evaluate(std::map<Var, bool> var2Val) = 0;
  // returns all the variables that exist in the Formula
  virtual std::set<Var> extractVarNames() = 0;
  virtual ~Formula() = default;
};

// You can And together two logical formulae
class And : public Formula {
 public:
  And(std::shared_ptr<Formula> lhs, std::shared_ptr<Formula> rhs);
  bool evaluate(std::map<Var, bool> var2Val) override;
  std::set<Var> extractVarNames() override;

 private:
  // you can And together two formulae and produce a bigger Formula!
  // lhs: left-hand side
  std::shared_ptr<Formula> lhs;
  std::shared_ptr<Formula> rhs;
};

// You can Or together two logical formulae
class Or : public Formula {
 public:
  Or(std::shared_ptr<Formula> lhs, std::shared_ptr<Formula> rhs);
  bool evaluate(std::map<Var, bool> var2Val) override;
  std::set<Var> extractVarNames() override;

 private:
  std::shared_ptr<Formula> lhs;
  std::shared_ptr<Formula> rhs;
};

// You can negate any logical formula
class Not : public Formula {
 public:
  Not(std::shared_ptr<Formula> inside);
  bool evaluate(std::map<Var, bool> var2Val) override;
  std::set<Var> extractVarNames() override;

 private:
  std::shared_ptr<Formula> inside;
};

// A single propositional variable by itself is a logical formula
// You can use Vars inside of bigger formulae
class Var : public Formula {
 public:
  Var(std::string name);
  bool evaluate(std::map<Var, bool> var2Val) override;
  std::set<Var> extractVarNames() override;

  bool operator<(const Var& other) const;
  friend std::ostream& operator<<(std::ostream& os, const Var& v);

 private:
  std::string name;
};

// Given a formula f, compute all the ways to make it true
// each map in the set is an assignment of variables to values
std::set<std::map<Var, bool>> satSolve(Formula& f);

// Helper function for satSolve that does the heavy lifting
void satSolveHelper(Formula& f, std::set<Var> remainingVars,
                    std::map<Var, bool> choicesForVars,
                    std::set<std::map<Var, bool>>& satisfyingSolutions);

#endif /* LOGIC_H */
