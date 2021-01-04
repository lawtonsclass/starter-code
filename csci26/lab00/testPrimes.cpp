#include <iostream>

#include "primes.h"
#include "testing.h"
using namespace std;

void testPrimes();

int main() {
  testPrimes();

  return 0;
}

void testPrimes() {
  assertTrue(isPrime(1993), "1993 is prime");
  assertTrue(isPrime(1997), "1997 is prime");
  assertTrue(isPrime(1999), "1999 is prime");
  assertTrue(isPrime(2003), "2003 is prime");
  assertTrue(isPrime(2011), "2011 is prime");
  assertTrue(isPrime(2017), "2017 is prime");
  assertTrue(isPrime(2027), "2027 is prime");
  assertTrue(isPrime(2029), "2029 is prime");
  assertTrue(isPrime(2039), "2039 is prime");
  assertTrue(isPrime(2053), "2053 is prime");
  assertTrue(isPrime(2063), "2063 is prime");
  assertTrue(isPrime(2069), "2069 is prime");
  assertTrue(isPrime(2081), "2081 is prime");

  assertTrue(!isPrime(1992), "1992 is not prime");
  assertTrue(!isPrime(1994), "1994 is not prime");
  assertTrue(!isPrime(2001), "2001 is not prime");
  assertTrue(!isPrime(2005), "2005 is not prime");
  assertTrue(!isPrime(2013), "2013 is not prime");
  assertTrue(!isPrime(2019), "2019 is not prime");
  assertTrue(!isPrime(2023), "2023 is not prime");
  assertTrue(!isPrime(2031), "2031 is not prime");
  assertTrue(!isPrime(2033), "2033 is not prime");
  assertTrue(!isPrime(2035), "2035 is not prime");
  assertTrue(!isPrime(2037), "2037 is not prime");
}
