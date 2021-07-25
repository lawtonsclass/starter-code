.global main
.type main, %function
.func main
main:
  push {r4-r11, lr}

  sub sp, sp, #8 // make room for two ints
  ldr r0, =int_scanf
  mov r1, sp
  add r2, sp, #4
  bl scanf // get the ints

  // FIXME: call pow using the two ints on the stack as parameters
  //        the first parameter is at sp and the second is at sp+4

  // FIXME: print out the result using the int_printf format string

  // clean up stack and return 0
  add sp, sp, #8
  mov r0, #0
  pop {r4-r11, pc}
.endfunc

.global pow
.type pow, %function
.func pow
pow:
  // FIXME: implement the recursive function `int pow(int n, int m)`
  // that returns n^m.

.data
int_scanf: .asciz "%d %d"
int_printf: .asciz "%d\n"
