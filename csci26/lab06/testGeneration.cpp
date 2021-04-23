#include <iostream>
#include <sstream>
#include <string>
using namespace std;

#include "generation.h"
#include "testing.h"

void testGeneratePermutations1();
void testGeneratePermutations2();
void testGenLexSubsets();
void testGenerateCombinations();

int main() {
  testGeneratePermutations1();
  testGeneratePermutations2();
  testGenLexSubsets();
  testGenerateCombinations();

  return 0;
}

void testGeneratePermutations1() {
  stringstream ss;
  vector<int> v = {1, 2, 3, 4, 5};

  vector<vector<int>> perms = generatePermutations(v);

  for (const auto& v : perms) {
    for (int i : v) {
      ss << i << " ";
    }
    ss << endl;
  }

  string reference =
      "1 2 3 4 5 \n"
      "1 2 3 5 4 \n"
      "1 2 4 3 5 \n"
      "1 2 4 5 3 \n"
      "1 2 5 3 4 \n"
      "1 2 5 4 3 \n"
      "1 3 2 4 5 \n"
      "1 3 2 5 4 \n"
      "1 3 4 2 5 \n"
      "1 3 4 5 2 \n"
      "1 3 5 2 4 \n"
      "1 3 5 4 2 \n"
      "1 4 2 3 5 \n"
      "1 4 2 5 3 \n"
      "1 4 3 2 5 \n"
      "1 4 3 5 2 \n"
      "1 4 5 2 3 \n"
      "1 4 5 3 2 \n"
      "1 5 2 3 4 \n"
      "1 5 2 4 3 \n"
      "1 5 3 2 4 \n"
      "1 5 3 4 2 \n"
      "1 5 4 2 3 \n"
      "1 5 4 3 2 \n"
      "2 1 3 4 5 \n"
      "2 1 3 5 4 \n"
      "2 1 4 3 5 \n"
      "2 1 4 5 3 \n"
      "2 1 5 3 4 \n"
      "2 1 5 4 3 \n"
      "2 3 1 4 5 \n"
      "2 3 1 5 4 \n"
      "2 3 4 1 5 \n"
      "2 3 4 5 1 \n"
      "2 3 5 1 4 \n"
      "2 3 5 4 1 \n"
      "2 4 1 3 5 \n"
      "2 4 1 5 3 \n"
      "2 4 3 1 5 \n"
      "2 4 3 5 1 \n"
      "2 4 5 1 3 \n"
      "2 4 5 3 1 \n"
      "2 5 1 3 4 \n"
      "2 5 1 4 3 \n"
      "2 5 3 1 4 \n"
      "2 5 3 4 1 \n"
      "2 5 4 1 3 \n"
      "2 5 4 3 1 \n"
      "3 1 2 4 5 \n"
      "3 1 2 5 4 \n"
      "3 1 4 2 5 \n"
      "3 1 4 5 2 \n"
      "3 1 5 2 4 \n"
      "3 1 5 4 2 \n"
      "3 2 1 4 5 \n"
      "3 2 1 5 4 \n"
      "3 2 4 1 5 \n"
      "3 2 4 5 1 \n"
      "3 2 5 1 4 \n"
      "3 2 5 4 1 \n"
      "3 4 1 2 5 \n"
      "3 4 1 5 2 \n"
      "3 4 2 1 5 \n"
      "3 4 2 5 1 \n"
      "3 4 5 1 2 \n"
      "3 4 5 2 1 \n"
      "3 5 1 2 4 \n"
      "3 5 1 4 2 \n"
      "3 5 2 1 4 \n"
      "3 5 2 4 1 \n"
      "3 5 4 1 2 \n"
      "3 5 4 2 1 \n"
      "4 1 2 3 5 \n"
      "4 1 2 5 3 \n"
      "4 1 3 2 5 \n"
      "4 1 3 5 2 \n"
      "4 1 5 2 3 \n"
      "4 1 5 3 2 \n"
      "4 2 1 3 5 \n"
      "4 2 1 5 3 \n"
      "4 2 3 1 5 \n"
      "4 2 3 5 1 \n"
      "4 2 5 1 3 \n"
      "4 2 5 3 1 \n"
      "4 3 1 2 5 \n"
      "4 3 1 5 2 \n"
      "4 3 2 1 5 \n"
      "4 3 2 5 1 \n"
      "4 3 5 1 2 \n"
      "4 3 5 2 1 \n"
      "4 5 1 2 3 \n"
      "4 5 1 3 2 \n"
      "4 5 2 1 3 \n"
      "4 5 2 3 1 \n"
      "4 5 3 1 2 \n"
      "4 5 3 2 1 \n"
      "5 1 2 3 4 \n"
      "5 1 2 4 3 \n"
      "5 1 3 2 4 \n"
      "5 1 3 4 2 \n"
      "5 1 4 2 3 \n"
      "5 1 4 3 2 \n"
      "5 2 1 3 4 \n"
      "5 2 1 4 3 \n"
      "5 2 3 1 4 \n"
      "5 2 3 4 1 \n"
      "5 2 4 1 3 \n"
      "5 2 4 3 1 \n"
      "5 3 1 2 4 \n"
      "5 3 1 4 2 \n"
      "5 3 2 1 4 \n"
      "5 3 2 4 1 \n"
      "5 3 4 1 2 \n"
      "5 3 4 2 1 \n"
      "5 4 1 2 3 \n"
      "5 4 1 3 2 \n"
      "5 4 2 1 3 \n"
      "5 4 2 3 1 \n"
      "5 4 3 1 2 \n"
      "5 4 3 2 1 \n";

  assertEquals(reference, ss.str(), "generatePermutations with numbers");
}

void testGeneratePermutations2() {
  stringstream ss;
  vector<string> v = {"Bulbasaur", "Charmander", "Pikachu", "Squirtle"};

  vector<vector<string>> perms = generatePermutations(v);

  for (const auto& v : perms) {
    for (const string& s : v) {
      ss << s << " ";
    }
    ss << endl;
  }

  string reference =
      "Bulbasaur Charmander Pikachu Squirtle \n"
      "Bulbasaur Charmander Squirtle Pikachu \n"
      "Bulbasaur Pikachu Charmander Squirtle \n"
      "Bulbasaur Pikachu Squirtle Charmander \n"
      "Bulbasaur Squirtle Charmander Pikachu \n"
      "Bulbasaur Squirtle Pikachu Charmander \n"
      "Charmander Bulbasaur Pikachu Squirtle \n"
      "Charmander Bulbasaur Squirtle Pikachu \n"
      "Charmander Pikachu Bulbasaur Squirtle \n"
      "Charmander Pikachu Squirtle Bulbasaur \n"
      "Charmander Squirtle Bulbasaur Pikachu \n"
      "Charmander Squirtle Pikachu Bulbasaur \n"
      "Pikachu Bulbasaur Charmander Squirtle \n"
      "Pikachu Bulbasaur Squirtle Charmander \n"
      "Pikachu Charmander Bulbasaur Squirtle \n"
      "Pikachu Charmander Squirtle Bulbasaur \n"
      "Pikachu Squirtle Bulbasaur Charmander \n"
      "Pikachu Squirtle Charmander Bulbasaur \n"
      "Squirtle Bulbasaur Charmander Pikachu \n"
      "Squirtle Bulbasaur Pikachu Charmander \n"
      "Squirtle Charmander Bulbasaur Pikachu \n"
      "Squirtle Charmander Pikachu Bulbasaur \n"
      "Squirtle Pikachu Bulbasaur Charmander \n"
      "Squirtle Pikachu Charmander Bulbasaur \n";

  assertEquals(reference, ss.str(), "generatePermutations with strings");
}

void testGenLexSubsets() {
  stringstream ss;
  vector<vector<int>> subsets = genLexSubsets(3, 5);

  for (const auto& v : subsets) {
    for (int i : v) {
      ss << i << " ";
    }
    ss << endl;
  }

  string reference =
      "1 2 3 \n"
      "1 2 4 \n"
      "1 2 5 \n"
      "1 3 4 \n"
      "1 3 5 \n"
      "1 4 5 \n"
      "2 3 4 \n"
      "2 3 5 \n"
      "2 4 5 \n"
      "3 4 5 \n";

  assertEquals(reference, ss.str(), "genLexSubsets");
}

void testGenerateCombinations() {
  stringstream ss;
  vector<string> v = {"Blastoise",  "Bulbasaur", "Charizard", "Charmander",
                      "Charmeleon", "Ivysaur",   "Pikachu",   "Squirtle",
                      "Venusaur",   "Wartortle"};

  vector<vector<string>> combs = generateCombinations(v, 4);

  for (const auto& v : combs) {
    for (const string& s : v) {
      ss << s << " ";
    }
    ss << endl;
  }

  string reference =
      "Blastoise Bulbasaur Charizard Charmander \n"
      "Blastoise Bulbasaur Charizard Charmeleon \n"
      "Blastoise Bulbasaur Charizard Ivysaur \n"
      "Blastoise Bulbasaur Charizard Pikachu \n"
      "Blastoise Bulbasaur Charizard Squirtle \n"
      "Blastoise Bulbasaur Charizard Venusaur \n"
      "Blastoise Bulbasaur Charizard Wartortle \n"
      "Blastoise Bulbasaur Charmander Charmeleon \n"
      "Blastoise Bulbasaur Charmander Ivysaur \n"
      "Blastoise Bulbasaur Charmander Pikachu \n"
      "Blastoise Bulbasaur Charmander Squirtle \n"
      "Blastoise Bulbasaur Charmander Venusaur \n"
      "Blastoise Bulbasaur Charmander Wartortle \n"
      "Blastoise Bulbasaur Charmeleon Ivysaur \n"
      "Blastoise Bulbasaur Charmeleon Pikachu \n"
      "Blastoise Bulbasaur Charmeleon Squirtle \n"
      "Blastoise Bulbasaur Charmeleon Venusaur \n"
      "Blastoise Bulbasaur Charmeleon Wartortle \n"
      "Blastoise Bulbasaur Ivysaur Pikachu \n"
      "Blastoise Bulbasaur Ivysaur Squirtle \n"
      "Blastoise Bulbasaur Ivysaur Venusaur \n"
      "Blastoise Bulbasaur Ivysaur Wartortle \n"
      "Blastoise Bulbasaur Pikachu Squirtle \n"
      "Blastoise Bulbasaur Pikachu Venusaur \n"
      "Blastoise Bulbasaur Pikachu Wartortle \n"
      "Blastoise Bulbasaur Squirtle Venusaur \n"
      "Blastoise Bulbasaur Squirtle Wartortle \n"
      "Blastoise Bulbasaur Venusaur Wartortle \n"
      "Blastoise Charizard Charmander Charmeleon \n"
      "Blastoise Charizard Charmander Ivysaur \n"
      "Blastoise Charizard Charmander Pikachu \n"
      "Blastoise Charizard Charmander Squirtle \n"
      "Blastoise Charizard Charmander Venusaur \n"
      "Blastoise Charizard Charmander Wartortle \n"
      "Blastoise Charizard Charmeleon Ivysaur \n"
      "Blastoise Charizard Charmeleon Pikachu \n"
      "Blastoise Charizard Charmeleon Squirtle \n"
      "Blastoise Charizard Charmeleon Venusaur \n"
      "Blastoise Charizard Charmeleon Wartortle \n"
      "Blastoise Charizard Ivysaur Pikachu \n"
      "Blastoise Charizard Ivysaur Squirtle \n"
      "Blastoise Charizard Ivysaur Venusaur \n"
      "Blastoise Charizard Ivysaur Wartortle \n"
      "Blastoise Charizard Pikachu Squirtle \n"
      "Blastoise Charizard Pikachu Venusaur \n"
      "Blastoise Charizard Pikachu Wartortle \n"
      "Blastoise Charizard Squirtle Venusaur \n"
      "Blastoise Charizard Squirtle Wartortle \n"
      "Blastoise Charizard Venusaur Wartortle \n"
      "Blastoise Charmander Charmeleon Ivysaur \n"
      "Blastoise Charmander Charmeleon Pikachu \n"
      "Blastoise Charmander Charmeleon Squirtle \n"
      "Blastoise Charmander Charmeleon Venusaur \n"
      "Blastoise Charmander Charmeleon Wartortle \n"
      "Blastoise Charmander Ivysaur Pikachu \n"
      "Blastoise Charmander Ivysaur Squirtle \n"
      "Blastoise Charmander Ivysaur Venusaur \n"
      "Blastoise Charmander Ivysaur Wartortle \n"
      "Blastoise Charmander Pikachu Squirtle \n"
      "Blastoise Charmander Pikachu Venusaur \n"
      "Blastoise Charmander Pikachu Wartortle \n"
      "Blastoise Charmander Squirtle Venusaur \n"
      "Blastoise Charmander Squirtle Wartortle \n"
      "Blastoise Charmander Venusaur Wartortle \n"
      "Blastoise Charmeleon Ivysaur Pikachu \n"
      "Blastoise Charmeleon Ivysaur Squirtle \n"
      "Blastoise Charmeleon Ivysaur Venusaur \n"
      "Blastoise Charmeleon Ivysaur Wartortle \n"
      "Blastoise Charmeleon Pikachu Squirtle \n"
      "Blastoise Charmeleon Pikachu Venusaur \n"
      "Blastoise Charmeleon Pikachu Wartortle \n"
      "Blastoise Charmeleon Squirtle Venusaur \n"
      "Blastoise Charmeleon Squirtle Wartortle \n"
      "Blastoise Charmeleon Venusaur Wartortle \n"
      "Blastoise Ivysaur Pikachu Squirtle \n"
      "Blastoise Ivysaur Pikachu Venusaur \n"
      "Blastoise Ivysaur Pikachu Wartortle \n"
      "Blastoise Ivysaur Squirtle Venusaur \n"
      "Blastoise Ivysaur Squirtle Wartortle \n"
      "Blastoise Ivysaur Venusaur Wartortle \n"
      "Blastoise Pikachu Squirtle Venusaur \n"
      "Blastoise Pikachu Squirtle Wartortle \n"
      "Blastoise Pikachu Venusaur Wartortle \n"
      "Blastoise Squirtle Venusaur Wartortle \n"
      "Bulbasaur Charizard Charmander Charmeleon \n"
      "Bulbasaur Charizard Charmander Ivysaur \n"
      "Bulbasaur Charizard Charmander Pikachu \n"
      "Bulbasaur Charizard Charmander Squirtle \n"
      "Bulbasaur Charizard Charmander Venusaur \n"
      "Bulbasaur Charizard Charmander Wartortle \n"
      "Bulbasaur Charizard Charmeleon Ivysaur \n"
      "Bulbasaur Charizard Charmeleon Pikachu \n"
      "Bulbasaur Charizard Charmeleon Squirtle \n"
      "Bulbasaur Charizard Charmeleon Venusaur \n"
      "Bulbasaur Charizard Charmeleon Wartortle \n"
      "Bulbasaur Charizard Ivysaur Pikachu \n"
      "Bulbasaur Charizard Ivysaur Squirtle \n"
      "Bulbasaur Charizard Ivysaur Venusaur \n"
      "Bulbasaur Charizard Ivysaur Wartortle \n"
      "Bulbasaur Charizard Pikachu Squirtle \n"
      "Bulbasaur Charizard Pikachu Venusaur \n"
      "Bulbasaur Charizard Pikachu Wartortle \n"
      "Bulbasaur Charizard Squirtle Venusaur \n"
      "Bulbasaur Charizard Squirtle Wartortle \n"
      "Bulbasaur Charizard Venusaur Wartortle \n"
      "Bulbasaur Charmander Charmeleon Ivysaur \n"
      "Bulbasaur Charmander Charmeleon Pikachu \n"
      "Bulbasaur Charmander Charmeleon Squirtle \n"
      "Bulbasaur Charmander Charmeleon Venusaur \n"
      "Bulbasaur Charmander Charmeleon Wartortle \n"
      "Bulbasaur Charmander Ivysaur Pikachu \n"
      "Bulbasaur Charmander Ivysaur Squirtle \n"
      "Bulbasaur Charmander Ivysaur Venusaur \n"
      "Bulbasaur Charmander Ivysaur Wartortle \n"
      "Bulbasaur Charmander Pikachu Squirtle \n"
      "Bulbasaur Charmander Pikachu Venusaur \n"
      "Bulbasaur Charmander Pikachu Wartortle \n"
      "Bulbasaur Charmander Squirtle Venusaur \n"
      "Bulbasaur Charmander Squirtle Wartortle \n"
      "Bulbasaur Charmander Venusaur Wartortle \n"
      "Bulbasaur Charmeleon Ivysaur Pikachu \n"
      "Bulbasaur Charmeleon Ivysaur Squirtle \n"
      "Bulbasaur Charmeleon Ivysaur Venusaur \n"
      "Bulbasaur Charmeleon Ivysaur Wartortle \n"
      "Bulbasaur Charmeleon Pikachu Squirtle \n"
      "Bulbasaur Charmeleon Pikachu Venusaur \n"
      "Bulbasaur Charmeleon Pikachu Wartortle \n"
      "Bulbasaur Charmeleon Squirtle Venusaur \n"
      "Bulbasaur Charmeleon Squirtle Wartortle \n"
      "Bulbasaur Charmeleon Venusaur Wartortle \n"
      "Bulbasaur Ivysaur Pikachu Squirtle \n"
      "Bulbasaur Ivysaur Pikachu Venusaur \n"
      "Bulbasaur Ivysaur Pikachu Wartortle \n"
      "Bulbasaur Ivysaur Squirtle Venusaur \n"
      "Bulbasaur Ivysaur Squirtle Wartortle \n"
      "Bulbasaur Ivysaur Venusaur Wartortle \n"
      "Bulbasaur Pikachu Squirtle Venusaur \n"
      "Bulbasaur Pikachu Squirtle Wartortle \n"
      "Bulbasaur Pikachu Venusaur Wartortle \n"
      "Bulbasaur Squirtle Venusaur Wartortle \n"
      "Charizard Charmander Charmeleon Ivysaur \n"
      "Charizard Charmander Charmeleon Pikachu \n"
      "Charizard Charmander Charmeleon Squirtle \n"
      "Charizard Charmander Charmeleon Venusaur \n"
      "Charizard Charmander Charmeleon Wartortle \n"
      "Charizard Charmander Ivysaur Pikachu \n"
      "Charizard Charmander Ivysaur Squirtle \n"
      "Charizard Charmander Ivysaur Venusaur \n"
      "Charizard Charmander Ivysaur Wartortle \n"
      "Charizard Charmander Pikachu Squirtle \n"
      "Charizard Charmander Pikachu Venusaur \n"
      "Charizard Charmander Pikachu Wartortle \n"
      "Charizard Charmander Squirtle Venusaur \n"
      "Charizard Charmander Squirtle Wartortle \n"
      "Charizard Charmander Venusaur Wartortle \n"
      "Charizard Charmeleon Ivysaur Pikachu \n"
      "Charizard Charmeleon Ivysaur Squirtle \n"
      "Charizard Charmeleon Ivysaur Venusaur \n"
      "Charizard Charmeleon Ivysaur Wartortle \n"
      "Charizard Charmeleon Pikachu Squirtle \n"
      "Charizard Charmeleon Pikachu Venusaur \n"
      "Charizard Charmeleon Pikachu Wartortle \n"
      "Charizard Charmeleon Squirtle Venusaur \n"
      "Charizard Charmeleon Squirtle Wartortle \n"
      "Charizard Charmeleon Venusaur Wartortle \n"
      "Charizard Ivysaur Pikachu Squirtle \n"
      "Charizard Ivysaur Pikachu Venusaur \n"
      "Charizard Ivysaur Pikachu Wartortle \n"
      "Charizard Ivysaur Squirtle Venusaur \n"
      "Charizard Ivysaur Squirtle Wartortle \n"
      "Charizard Ivysaur Venusaur Wartortle \n"
      "Charizard Pikachu Squirtle Venusaur \n"
      "Charizard Pikachu Squirtle Wartortle \n"
      "Charizard Pikachu Venusaur Wartortle \n"
      "Charizard Squirtle Venusaur Wartortle \n"
      "Charmander Charmeleon Ivysaur Pikachu \n"
      "Charmander Charmeleon Ivysaur Squirtle \n"
      "Charmander Charmeleon Ivysaur Venusaur \n"
      "Charmander Charmeleon Ivysaur Wartortle \n"
      "Charmander Charmeleon Pikachu Squirtle \n"
      "Charmander Charmeleon Pikachu Venusaur \n"
      "Charmander Charmeleon Pikachu Wartortle \n"
      "Charmander Charmeleon Squirtle Venusaur \n"
      "Charmander Charmeleon Squirtle Wartortle \n"
      "Charmander Charmeleon Venusaur Wartortle \n"
      "Charmander Ivysaur Pikachu Squirtle \n"
      "Charmander Ivysaur Pikachu Venusaur \n"
      "Charmander Ivysaur Pikachu Wartortle \n"
      "Charmander Ivysaur Squirtle Venusaur \n"
      "Charmander Ivysaur Squirtle Wartortle \n"
      "Charmander Ivysaur Venusaur Wartortle \n"
      "Charmander Pikachu Squirtle Venusaur \n"
      "Charmander Pikachu Squirtle Wartortle \n"
      "Charmander Pikachu Venusaur Wartortle \n"
      "Charmander Squirtle Venusaur Wartortle \n"
      "Charmeleon Ivysaur Pikachu Squirtle \n"
      "Charmeleon Ivysaur Pikachu Venusaur \n"
      "Charmeleon Ivysaur Pikachu Wartortle \n"
      "Charmeleon Ivysaur Squirtle Venusaur \n"
      "Charmeleon Ivysaur Squirtle Wartortle \n"
      "Charmeleon Ivysaur Venusaur Wartortle \n"
      "Charmeleon Pikachu Squirtle Venusaur \n"
      "Charmeleon Pikachu Squirtle Wartortle \n"
      "Charmeleon Pikachu Venusaur Wartortle \n"
      "Charmeleon Squirtle Venusaur Wartortle \n"
      "Ivysaur Pikachu Squirtle Venusaur \n"
      "Ivysaur Pikachu Squirtle Wartortle \n"
      "Ivysaur Pikachu Venusaur Wartortle \n"
      "Ivysaur Squirtle Venusaur Wartortle \n"
      "Pikachu Squirtle Venusaur Wartortle \n";

  assertEquals(reference, ss.str(), "generateCombinations");
}
