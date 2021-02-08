#ifndef RSA_H
#define RSA_H

#include <utility>

// calculate N
int computeN(int p, int q);

// calcluate ϕ
int computePhi(int p, int q);

// computes xʸ mod m
int powmod(int x, int y, int m);

// computes the greatest common divisor of x and y
int gcd(int x, int y);

// find an integer e such that gcd(e, ϕ) = 1
int computeE(int phi);

// returns a pair (a, b) such that ax + by = gcd(a, b)
std::pair<int, int> extended_gcd(int x, int y);

// computes the multiplicative inverse of e mod ϕ
int multiplicativeInverse(int e, int phi);

// RSA encryption
int encrypt(int message, int e, int N);

// RSA decryption
int decrypt(int ciphertext, int d, int N);

#endif /* RSA_H */
