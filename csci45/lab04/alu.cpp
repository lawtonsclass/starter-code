#include "alu.h"

#include <algorithm>
#include <iostream>
using namespace std;

EightBitALU::EightBitALU() {
  // zero out operands
  for (int i = 0; i < 8; i++) {
    operand1[i] = operand2[i] = false;
  }

  // zero out flags too
  N = Z = C = V = false;
}

bool EightBitALU::getN() const { return N; }
bool EightBitALU::getZ() const { return Z; }
bool EightBitALU::getC() const { return C; }
bool EightBitALU::getV() const { return V; }

void EightBitALU::loadOperand1(const bool x[8]) {
  // FIXME: copy x into operand1
}

void EightBitALU::loadOperand2(const bool y[8]) {
  // FIXME: copy y into operand2
}

void EightBitALU::AND(bool res[8]) {
  // FIXME: perform AND on operand1 and operand2
  // FIXME: store the result into res
  // FIXME: set flags to their appropriate values
}

void EightBitALU::OR(bool res[8]) {
  // FIXME: perform OR on operand1 and operand2
  // FIXME: store the result into res
  // FIXME: set flags to their appropriate values
}

void EightBitALU::ADD(bool res[8], bool shouldSetFlags) {
  // FIXME: perform ADD on operand1 and operand2
  // FIXME: store the result into res
  // FIXME: set flags to their appropriate values ONLY if 
  //        shouldSetFlags is true. We want to use ADD
  //        during the negation phase inside SUB, so we 
  //        don't always want to set the flags.
  // Hint: for bools, != acts like xor
}

void EightBitALU::twosComplementOperand2() {
  // FIXME: overwrite operand2 with its two's complement
  //        (i.e., negate operand2 in place)
  // Hint: Probably the easiest way to do this is to re-use the ADD
  // circuitry. If you do it that way, remember to save the original
  // operand1 value so that you can restore it at the end!
}

void EightBitALU::compute(const bool selector[2], bool res[8]) {
  // FIXME: perform the appropriate operation on operand1 and operand2, 
  //        based on the value of the selector:
  //          00: operand1 AND operand2
  //          01: operand1 OR operand2
  //          10: operand1 ADD operand2
  //          11: operand1 SUB operand2
  // FIXME: save the result of the operation in res
  // Hint: use twosComplementOperand2 and ADD to implement SUB
}
