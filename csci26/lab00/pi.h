#ifndef PI_H
#define PI_H

class Point {
 public:
  // gets a random point with x and y between 0 and 1
  static Point uniformRandomPoint();
  // Point constructor
  Point(double x, double y);
  // gets the distance that a current point object is from (0, 0)
  double distanceFromOrigin();

 private:
  double x;
  double y;
};

// Approximates π by throwing numDarts darts
double approximatePi(int numDarts);

#endif /* PI_H */
