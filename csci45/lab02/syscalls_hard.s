.global main
.type main, %function
main:
  sub sp, sp, #16
  str lr, [sp]

  // List of arm64 syscalls: https://gpages.juszkiewicz.com.pl/syscalls-table/syscalls.html

  // FIXME: call the "gettimeofday" syscall to get the current number of
  // seconds since January 1, 1970 (it's a long story) and print it out. 

  /*
  Use the "man gettimeofday" terminal command to look up what the
  syscall needs. It takes two parameters--tv and tz. 

  You should call the syscall with tz set to nullptr. tv, though,
  needs to be a pointer to a timeval struct. So, we have to make an
  address that has just enough room to hold the struct.

  First, you need to figure out how many bytes a timeval struct takes
  up. Write a scratch program and use sizeof to get the answer. Then,
  make that many consecutive bytes in the .data section for your
  timeval, and pass the address of those bytes along as the tv
  parameter of the syscall.

  The syscall will set sizeof(struct timeval) bytes at the address you
  gave it. The time is hidden in there!

  Next, you need to extract the time_t (tv_sec) part of the timeval
  struct (see the man page for more info) that is now saved in the
  data section. time_t is an unsigned number, but again you need to
  figure out how big it is in order to extract it.  Go into the
  struct, get the time_t part out, and save it in a register.

  Finally, print the time_t value as an unsigned long value using
  printf and the %lu specifier (since it's more than 4 bytes). 
  Print a newline too. Now you're done!

  For fun, you can confirm that the number you print is correct by
  calculating 1970 + ([printed number] / 60 / 60 / 24 / 365.25) and
  seeing if you get the correct year.
  */


  // return 0
  mov w0, #0
  ldr lr, [sp]
  add sp, sp, #16
  ret
