#include <ctime>
#include <iostream>
#include <sstream>
using namespace std;

#include "rsa.h"
#include "testing.h"

void testPowmod();
void testExtendedGCD();
void testMultiplicativeInverse();

void testRSA(int p, int q);

int main() {
  srand(time(0));

  testPowmod();
  testExtendedGCD();
  testMultiplicativeInverse();

  testRSA(31, 59);
  testRSA(17, 41);
  testRSA(31, 47);
  testRSA(43, 79);

  return 0;
}

void testPowmod() {
  assertTrue(powmod(43, 127, 53) == 38, "43^127 (mod 53) = 38");
}

void testExtendedGCD() {
  auto res = extended_gcd(859, 1740);
  assertTrue(res.first * 859 + res.second * 1740 == 1,
             "extended_gcd(859, 1740)");
}

void testMultiplicativeInverse() {
  int inv = multiplicativeInverse(527, 640);
  assertTrue((527 * inv) % 640 == 1, "multiplicativeInverse(527, 640)");
}

void testRSA(int p, int q) {
  int N = computeN(p, q);
  int phi = computePhi(p, q);
  int e = computeE(phi);
  int d = multiplicativeInverse(e, phi);

  int message = rand() % N;
  int ciphertext = encrypt(message, e, N);
  int decrypted = decrypt(ciphertext, d, N);

  stringstream ss;
  ss << "p = " << p << ", q = " << q << ", N = " << N << ", phi = " << phi
     << ", e = " << e << ", d = " << d << ", message = " << message
     << ", ciphertext = " << ciphertext << ", decrypted = " << decrypted;

  assertTrue(message == decrypted, ss.str());
}
