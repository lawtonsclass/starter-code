.global main
.type main, %function
main:
  sub sp, sp, #16
  str lr, [sp]

  // we'll store two ints at [sp, #8] and [sp, #12]
  ldr x0, =int_scanf
  add x1, sp, #8
  add x2, sp, #12
  bl scanf // get the ints

  // FIXME: call pow using the two ints on the stack as parameters
  //        the first parameter is at sp+8 and the second is at sp+12

  // FIXME: print out the result using the int_printf format string

  // clean up stack and return 0
  mov w0, #0
  ldr lr, [sp]
  add sp, sp, #16
  ret

.global pow
.type pow, %function
pow:
  // FIXME: implement the recursive function `int pow(int n, int m)`
  // that returns n^m.

.data
int_scanf: .asciz "%d %d"
int_printf: .asciz "%d\n"
