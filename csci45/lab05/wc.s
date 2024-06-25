.global main
.type main, %function
main:
  // FIXME: print out the number of words that are input to stdin 
  // before the end of file character is reached. Create new
  // functions and add to the .data section as needed. Print the
  // number of words to stdout followed by a newline. 
  //
  // Hint: use getchar and isspace.
  // 
  // Things to watch out for:
  // - isspace is necessary because are more word separators than just ' '
  //   - isspace returns 0 for false, but it DOES NOT return 1 for
  //     true! You must compare against 0 or you will have a bad time.
  // - EOF is -1. That is: an entire, 32-bit, sign extended -1.
  //   getchar is supposed to return characters, so you might expect to 
  //   get an 8-bit -1 in a 32-bit register (i.e. 0x000000FF), but you don't!
  //
  // To test your code, you can use the `wc -w filename` terminal
  // command to get the correct word count for any file.
