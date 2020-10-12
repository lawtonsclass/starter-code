#include "etchASketch.h"
using namespace std;

EtchASketch::EtchASketch(char markChar) {
  // start in the middle
  currentLocation = {25 / 2, 25 / 2};

  // set the mark to the value of the markChar parameter
  mark = markChar;

  // clear the grid with spaces
  // i.e., put a space in ever index of the grid
  for (int i = 0; i < 25; i++)
    for (int j = 0; j < 25; j++) 
      grid[i][j] = ' ';

  // put a mark in our current, starting location
  // Use the markCurrentLocation helper function for this!
  markCurrentLocation();
}

// put a mark in our current location in the grid
void EtchASketch::markCurrentLocation() {
  grid[currentLocation.row][currentLocation.col] = mark;
}

// move the current location to the left 
// (i.e., change the column to be one less)
void EtchASketch::left() {
  // don't allow the currentLocation's col to become negative--that's off the screen!
  currentLocation.col = max(currentLocation.col - 1, 0);
  markCurrentLocation();
}

// move the current location to the right  
// (i.e., change the column to be one greater)
void EtchASketch::right() {
  // don't allow the currentLocation's col to become >= 25--that's off the screen!
  currentLocation.col = min(currentLocation.col + 1, 24);
  markCurrentLocation();
}

// move the current location up 
// (i.e., change the column to be one less)
void EtchASketch::up() {
  // don't allow the currentLocation's row to become negative--that's off the screen!
  currentLocation.row = max(currentLocation.row - 1, 0);
  markCurrentLocation();
}

// move the current location up 
// (i.e., change the column to be one greater)
void EtchASketch::down() {
  // don't allow the currentLocation's row to become >= 25--that's off the screen!
  currentLocation.row = min(currentLocation.row + 1, 24);
  markCurrentLocation();
}

// convert our grid into a string, by iterating through it in order
// (top to bottom, left to right)
// place a newline at the end of each row
string EtchASketch::getArtwork() const {
  string result = "";
  for (int i = 0; i < 25; i++) {
    for (int j = 0; j < 25; j++) {
      result += grid[i][j];
    }
    result += '\n';
  }
  return result;
}