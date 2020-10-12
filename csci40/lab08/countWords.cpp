#include <algorithm>
#include <cctype>
#include <fstream>
#include <iostream>
using namespace std;

// You'll want to make a function that will convert a string to lowercase
// and remove any non-alphabetic characters that exist around it!
// For example, "the.", "!the", "THE", and "0tHE" should all count as "the"
void fixString(string &s) {
  // FIXME: implement this function to transform s into a "cleaned-up" version of itself
  // lowercase it
}

int main(int argc, char *argv[]) {
  // FIXME: open the file whose name is in argv[1] into an ifstream object

  // FIXME: get the string to search for out of argv[2]
  string stringToSearchFor = "FIXME";
  int count = 0; // # of times the word appears

  // your implementation here (use stringToSearchFor and count)
  // FIXME: search for the stringToSearchFor in the file and keep track of the count
  
  cout << "\"" << stringToSearchFor << "\""
       << " appears " << count << " times." << endl;

  return 0;
}
