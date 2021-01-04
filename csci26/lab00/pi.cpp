#include "pi.h"

#include <cmath>
#include <cstdlib>

Point::Point(double x, double y) : x(x), y(y) {}

double Point::distanceFromOrigin() { return sqrt(x * x + y * y); }

Point Point::uniformRandomPoint() {
  double x = static_cast<double>(random()) / RAND_MAX;
  double y = static_cast<double>(random()) / RAND_MAX;
  return Point(x, y);
}

// FIXME: implement this function
double approximatePi(int numDarts) {
  int numInside = 0;  // count how many darts landed inside the unit circle

  // The ratio of the area of the unit circle to the area of the enclosing
  // square is π/4. That means numInside / numDarts is an
  // approximation of π/4. Use this fact to return an approximation of
  // π.
  // FIXME: this is just a stub return statement
  return -42;
}
