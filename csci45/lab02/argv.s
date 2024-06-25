.global main
.type main, %function
main:
  sub sp, sp, #16
  str lr, [sp]
  str x19, [sp, #8] // you'll need to use at least one saved register
  // argc is in r0
  // argv is in r1

  // FIXME: iterate through argv and print every element in order, each on a
  // separate line


  // return 0
  mov w0, #0
  ldr lr, [sp]
  ldr x19, [sp, #8]
  add sp, sp, #16
  ret

// FIXME: you'll probably want to add a .data section
