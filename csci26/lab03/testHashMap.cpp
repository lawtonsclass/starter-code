#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

#include "hashMap.h"
#include "testing.h"

void testHashMap1();
void testHashMap2();

int main() {
  srand(time(0));

  testHashMap1();
  testHashMap2();

  return 0;
}

void testHashMap1() {
  // make a HashMap of size 101
  HashMap hm(101);

  // insert 3 elements
  hm.insert(8675309, "Lawton");
  hm.insert(1234567, "Lonzo");
  hm.insert(9876543, "Lawton's mom");

  bool isCorrect = true;

  // make sure they all exist in the correct places
  if (!hm.exists(8675309) || hm.at(8675309) != "Lawton") isCorrect = false;
  if (!hm.exists(1234567) || hm.at(1234567) != "Lonzo") isCorrect = false;
  if (!hm.exists(9876543) || hm.at(9876543) != "Lawton's mom")
    isCorrect = false;

  // test update
  hm.at(8675309) = "LAWTON";
  if (!hm.exists(8675309) || hm.at(8675309) != "LAWTON") isCorrect = false;

  // test remove
  hm.remove(8675309);
  if (hm.exists(8675309)) isCorrect = false;

  assertTrue(isCorrect, "simple HashMap tests");
}

void testHashMap2() {
  HashMap hm(101);
  bool isCorrect = true;

  // insert a bunch of values
  for (int i = 0; i < 101; i++) {
    int key = (i + 1) * 1234;
    string val = to_string(key + 1);
    hm.insert(key, val);
  }

  // check that they're all there
  for (int i = 0; i < 101; i++) {
    int key = (i + 1) * 1234;
    string val = to_string(key + 1);
    if (!hm.exists(key) || hm.at(key) != val) isCorrect = false;
  }

  // delete half of them
  for (int i = 0; i < 101 / 2; i++) {
    int key = (i + 1) * 1234;
    hm.remove(key);
  }

  // insert/overwrite them
  for (int i = 0; i < 101; i++) {
    int key = (i + 1) * 1234;
    string val = to_string(key + 2);
    if (i >= 101 / 2 && rand() % 2 == 0) {
      hm.at(key) = val;  
    } else {
      hm.insert(key, val);  
    }
  }

  // check that they've all been updated
  for (int i = 0; i < 101; i++) {
    int key = (i + 1) * 1234;
    string val = to_string(key + 2);
    if (!hm.exists(key) || hm.at(key) != val) isCorrect = false;
  }

  // search for something that's not there
  if (hm.exists(987654321)) isCorrect = false;

  // delete half of them
  for (int i = 0; i < 101 / 2; i++) {
    int key = (i + 1) * 1234;
    hm.remove(key);
  }

  // make sure they got deleted, and that the rest are still there
  for (int i = 0; i < 101; i++) {
    int key = (i + 1) * 1234;
    string val = to_string(key + 2);
    if (i < 101 / 2) {
      if (hm.exists(key)) isCorrect = false;
    } else {
      if (!hm.exists(key) || hm.at(key) != val) isCorrect = false;
    }
  }

  assertTrue(isCorrect, "complicated HashMap tests");
}
