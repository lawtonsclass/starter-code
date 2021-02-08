#include "rsa.h"

#include <cassert>
#include <cstdlib>
#include <iostream>
#include <tuple>
using namespace std;

// calculate RSA's N value from p and q
int computeN(int p, int q) { 
  // FIXME: implement this function
  return -42;
}

// calculate RSA's ϕ value from p and q
int computePhi(int p, int q) { 
  // FIXME: implement this function
  return -42;
}

// computes xʸ mod m
int powmod(int x, int y, int m) {
  // FIXME: implement this function
  return -42;
}

// computes the greatest common divisor of x and y
int gcd(int x, int y) {
  // FIXME: implement Euclid's algorithm
  return -42;
}

// find an integer e such that gcd(e, ϕ) = 1
// Hint: use rand() to find a number (in the correct range!) that works
int computeE(int phi) {
  // FIXME: implement this function
  return -42;
}

// returns a pair (a, b) such that ax + by = gcd(a, b)
std::pair<int, int> extended_gcd(int x, int y) {
  // FIXME: implement this function
  // See https://en.wikipedia.org/wiki/Extended_Euclidean_algorithm#Pseudocode
  // for an implementation that you can copy
  return make_pair(-42, -42);
}

// computes the multiplicative inverse of e mod ϕ
// That is: find inv such that (e * inv) % ϕ = 1
int multiplicativeInverse(int e, int phi) {
  // FIXME: implement this function
  // Use extended_gcd to do most of the work.
  // The multiplicative inverse you get from extended_gcd might be negative--
  // make sure to return a number between 0 and ϕ-1. (Hint: remember that 
  // adding multiples of ϕ do not change the result mod ϕ.)
  return -42;
}

// RSA encryption--given a message, return the ciphertext
// (messages are ints in this implementation)
int encrypt(int message, int e, int N) { 
  // FIXME: implement this function
  return -42;
}

// RSA decryption--given a ciphertext, return the decrypted message
// (messages are ints in this implementation)
int decrypt(int ciphertext, int d, int N) { 
  // FIXME: implement this function 
  return -42;
}
