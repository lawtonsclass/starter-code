#ifndef BITOPS_H
#define BITOPS_H

// tests whether bit i is set (i.e., bit i is 1) in the number n
bool isBitSet(unsigned int n, int i);

// counts the number of bits set in n
int countBits(unsigned int n);

// sets bit i in the number n to 1
void setBit(unsigned int& n, int i);

#endif /* end of include guard: BITOPS_H */
