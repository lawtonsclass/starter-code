// All praise Professor Kerney, the inventor of this lab. I have
// stolen it from him.

#include <unistd.h>
#include <sys/utsname.h>

#include <algorithm>
#include <cctype>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

int lineNumber = 0;

// called when a syntax error is found
void error() {
  cout << "Syntax error on line " << lineNumber << endl;
  exit(1);
}

string variableToRegister(const string& var) {
  // We can't use R0-R3, R14, or R15, but we have plenty other
  // registers left!
  if (var == "A")
    return "R4";
  else if (var == "B")
    return "R5";
  else if (var == "C")
    return "R6";
  else if (var == "I")
    return "R7";
  else if (var == "J")
    return "R8";
  else if (var == "X")
    return "R9";
  else if (var == "Y")
    return "R10";
  else if (var == "Z")
    return "R11";
  else
    error();  // Invalid variable

  return var;  // we'll never get here--this is just to appease the compiler
}

int main(int argc, char* argv[]) {
  ofstream assembly("assembly.s");
  if (!assembly) {
    cout << "Error opening the output file." << endl;
    return 1;
  }

  // start off the program
  assembly << ".global main" << endl;
  assembly << "main:" << endl;
  assembly << "  push {lr}" << endl;
  assembly << "  push {r4-r11}" << endl;
  // Initialize all variables to 0
  for (int i = 4; i <= 11; i++) assembly << "  mov R" << i << ", #0" << endl;

  // The following data vector will hold all the lines that need to go
  // in the .data segment after the code.
  vector<string> data;

  // the previous label (user-provided line number) that we saw
  int lastLabel = 0;

  // get lines from cin until the end of file (that is, cin becomes
  // false)
  string line;
  while (getline(cin, line)) {
    // we're on a new line
    lineNumber++;
    // make the line uppercase if it wasn't already
    transform(line.begin(), line.end(), line.begin(), ::toupper);

    // put the line into a stringstream so that we can extract bits of
    // it easily
    stringstream ss(line);

    // get the label (i.e., the user-provided line number)
    int label;
    ss >> label;
    if (!ss) error();
    if (label < lastLabel) error();  // labels must be ascending
    // output an *assembly* label for this line so that we can branch
    // to it if necessary
    assembly << "line_" << label << ":" << endl;  // example: "line_20:"
    lastLabel = label;

    // figure out what operation was on this line
    string operation;
    ss >> operation;
    if (!ss) error();

    if (operation == "REM") {
      continue;
    } else if (operation == "GOTO") {
      int target;
      ss >> target;
      if (!ss) error();
      assembly << "  BAL line_" << target << endl;
      continue;
    } else if (operation == "END") {
      assembly << "  BAL end" << endl;
      continue;
    }
    // FIXME: Insert code here to handle all the remaining operations
    //        (That is, PRINT, LET, and IF)
    // Remember to add lines to the data vector if you want things to
    // be added to the .data section.
    // printing.c will be linked with your compiled assembly, so make
    // use of the functions there.
  }

  // finish the main function
  assembly << "end:" << endl;
  assembly << "  mov r0, #0" << endl;
  assembly << "  pop {r4-r11}" << endl;
  assembly << "  pop {pc}" << endl;
  assembly << endl;

  // add the data section
  assembly << ".data" << endl;
  for (const string& s : data) {
    assembly << s << endl;
  }
  assembly.close();  // That's the end of the program!

  // Now, let's get ready to compile it
  cout << "Compiling program." << endl;

  // figure out if we're on ARM32 or if we need to use QEMU
  struct utsname u;
  uname(&u);
  string terminal_command_to_compile = "";
  if (string(u.machine) == "aarch64")
    terminal_command_to_compile = "gcc -g assembly.s printing.c";
  else
    terminal_command_to_compile = "aarch64-linux-gnu-gcc -g -static assembly.s printing.c";

  // Compile
  if (system(terminal_command_to_compile.c_str()) != 0) {
    cout << "Assembling failed--there's something wrong with the assembly you "
            "generated.\n";
    return 1;
  }

  // And run it
  cout << "Executing program:" << endl;
  char* empty[] = {nullptr};
  execve("a.out", empty, empty);

  return 0;
}
