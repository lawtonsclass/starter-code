#include <iostream>

#include "bitOps.h"
#include "testing.h"
using namespace std;

void testIsBitSet1();
void testIsBitSet2();
void testIsBitSet3();
void testIsBitSet4();
void testIsBitSet5();
void testIsBitSet6();
void testIsBitSet7();

void testCountBits1();
void testCountBits2();
void testCountBits3();

void testSetBit1();
void testSetBit2();

int main() {
  testIsBitSet1();
  testIsBitSet2();
  testIsBitSet3();
  testIsBitSet4();
  testIsBitSet5();
  testIsBitSet6();
  testIsBitSet7();

  testCountBits1();
  testCountBits2();
  testCountBits3();

  testSetBit1();
  testSetBit2();

  // FIXME: write two more tests

  return 0;
}

void testIsBitSet1() { assertTrue(isBitSet(15, 0) == true, "isBitSet(15, 0)"); }
void testIsBitSet2() { assertTrue(isBitSet(15, 1) == true, "isBitSet(15, 1)"); }
void testIsBitSet3() { assertTrue(isBitSet(15, 2) == true, "isBitSet(15, 2)"); }
void testIsBitSet4() { assertTrue(isBitSet(15, 3) == true, "isBitSet(15, 3)"); }
void testIsBitSet5() {
  assertTrue(isBitSet(15, 4) == false, "isBitSet(15, 4)");
}
void testIsBitSet6() { assertTrue(isBitSet(6, 0) == false, "isBitSet(6, 0)"); }
void testIsBitSet7() {
  assertTrue(isBitSet(-1, 15) == true, "isBitSet(-1, 15)");
}

void testCountBits1() { assertTrue(countBits(2) == 1, "countBits(2)"); }
void testCountBits2() { assertTrue(countBits(7) == 3, "countBits(7)"); }
void testCountBits3() { assertTrue(countBits(-1) == 32, "countBits(-1)"); }

void testSetBit1() {
  unsigned int i = 0;
  setBit(i, 3);
  setBit(i, 3);
  setBit(i, 4);
  setBit(i, 5);
  assertTrue(isBitSet(i, 3) && isBitSet(i, 4) && isBitSet(i, 5) &&
                 countBits(i) == 3 && i == 56,
             "setBit test 1");
}

void testSetBit2() {
  unsigned int i = 42;  // 42 in binary is 101010
  setBit(i, 0);
  setBit(i, 27);
  setBit(i, 1);

  assertTrue(i == 134217771, "setBit test 2");
}
