#include <algorithm>
#include <cmath>
#include <ctime>
#include <iostream>
#include <vector>

#include "pi.h"
#include "testing.h"
using namespace std;

void testPi();

int main() {
  srand(time(0));

  cout << approximatePi(1'000'000) << endl;
  testPi();

  return 0;
}

void testPi() {
  vector<double> approximations;

  for (int i = 0; i < 10; i++) {
    approximations.push_back(approximatePi(1'000'000));
  }

  std::transform(approximations.begin(), approximations.end(),
                 approximations.begin(),
                 [](double d) { return fabs(M_PI - d); });

  bool differencesAreSmall =
      std::all_of(approximations.begin(), approximations.end(),
                  [](double d) { return d < 0.1; });

  bool answerIsntAlwaysTheSame =
      std::min(approximations.begin(), approximations.end()) !=
      std::max(approximations.begin(), approximations.end());

  assertTrue(differencesAreSmall && answerIsntAlwaysTheSame, "pi tests");
}
