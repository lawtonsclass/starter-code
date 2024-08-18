.global main
.type main, %function
main:
  sub sp, sp, #32
  str lr, [sp]
  str x19, [sp, #8] // you'll need to use a couple saved registers
  str x20, [sp, #16]
  // argc is in w0
  // argv is in x1

  // FIXME: iterate through argv and print every element in order, each on a
  // separate line

  // Hint: store argc in x19 and argv in x20 (because calling printf
  // will overwrite x0 & x1, you need to keep these values safe in a
  // *saved register*). Loop until x19 becomes 0, and keep advancing
  // argv to the next C-string.

  // return 0
  mov w0, #0
  ldr lr, [sp]
  ldr x19, [sp, #8]
  ldr x20, [sp, #16]
  add sp, sp, #32
  ret

// FIXME: you'll probably want to add a .data section
