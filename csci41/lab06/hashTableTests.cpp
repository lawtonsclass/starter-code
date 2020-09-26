#include <string>
#include "testing.h"
#include "hashTable.h"
using namespace std;

void hashTableTest1();
void hashTableTest2();

int main() {
  hashTableTest1();
  hashTableTest2();

  // FIXME: add two more tests

  return 0;
}

void hashTableTest1() {
  HashTable<int, double> table(5);
  bool is_correct = true;

  table.insert(5, 3.14);
  table.insert(6, 5.67);
  if (table.search(5) == nullptr || *table.search(5) != 3.14) is_correct = false;
  if (table.search(6) == nullptr || *table.search(6) != 5.67) is_correct = false;
  if (table.search(10) != nullptr) is_correct = false;

  assertTrue(is_correct, "HashTable<int, double> test");
}

void hashTableTest2() {
  // make sure all the proper hash functions got made
  HashTable<int, int> tInt(42);
  HashTable<char, int> tChar(42);
  HashTable<double, int> tDouble(42);
  HashTable<string, int> tString(42);

  bool is_correct = true;

  // ensure that there will be collisions
  for (int i = 0; i < 128; i++) {
    tInt.insert(i, i+1);
    tChar.insert(static_cast<char>(i), i+1);
    tDouble.insert(static_cast<double>(i), i+1);
    tString.insert(to_string(i), i+1);
  }

  // search for what we inserted
  for (int i = 0; i < 128; i++) {
    if (tInt.search(i) == nullptr || *tInt.search(i) != i+1) is_correct = false;
    if (tChar.search(static_cast<char>(i)) == nullptr || *tChar.search(static_cast<char>(i)) != i+1) is_correct = false;
    if (tDouble.search(static_cast<double>(i)) == nullptr || *tDouble.search(static_cast<double>(i)) != i+1) is_correct = false;
    if (tString.search(to_string(i)) == nullptr || *tString.search(to_string(i)) != i+1) is_correct = false;
  }

  assertTrue(is_correct, "HashTable comprehensive test");
}
