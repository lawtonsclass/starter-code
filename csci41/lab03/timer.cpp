#include "timer.h"

#include <iostream>
using namespace std;

Timer::Timer(std::string description): description(description) {}

void Timer::start() {
  // FIXME: set begin appropriately
}

void Timer::stop() {
  // FIXME: set end appropriately
}

double Timer::getSecondsElapsed() const {
  // FIXME: calculate the number of seconds between start() and stop()
  return 0;
}

void Timer::printData() const {
  cout << description << ": " << getSecondsElapsed() << " seconds" << endl;
}
