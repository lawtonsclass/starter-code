#ifndef ETCHASKETCH_H
#define ETCHASKETCH_H

#include <string>

// This is the library that you'll use in this lab!
// It draws pretty pictures by moving its "brush" up, down, left, and right
// starting from the center.
class EtchASketch {
 public:
  // constructor--creates an EtchASketch object using a given mark character 
  // (* is the default)
  EtchASketch(char markChar = '*');

  // move the etch-a-sketch in a given direction
  void left();
  void right();
  void up();
  void down();

  // convert the built-up image to a string for printing
  std::string getArtwork() const;

 private:
  void markCurrentLocation();

  struct Point {
    int row;
    int col;
  };

  // the current coordinates where we're drawing
  Point currentLocation;
  // the character to draw with
  char mark;
  // the "screen" that we'll draw on
  char grid[25][25];
};

#endif