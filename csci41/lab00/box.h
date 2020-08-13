#ifndef BOX_H
#define BOX_H

#include <iostream>

class Box {
 public:
  // constructor to set the width and the box-drawing character
  Box(int width = 0, char boxChar = '*');

  // gets the current width
  int getWidth() const;
  // gets the current box-drawing character
  char getBoxChar() const;
  // sets the current box-drawing character
  void setBoxChar(char newChar);

  // increases the current width by offset
  void operator+=(int offset);

  // decreases the current width by offset
  friend void operator-=(Box& b, int offset);
  // draws the Box using width rows of width boxChar to the output
  // stream (e.g., cout)
  friend std::ostream& operator<<(std::ostream& out, const Box& b);

 private:
  int width;
  char boxChar;
};

#endif /* BOX_H */
