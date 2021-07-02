.global _start
_start:
  mov r0, #2
  mov r1, #3
  mov r2, #4

  // Don't worry about the following chunk of instructions. You're not
  // supposed to understand them yet.
  add r3, r0, r1
  sub r3, r3, r2
  mul r4, r3, r1
  mov r3, r4
  mul r4, r3, r0
  mov r3, r4
  lsl r3, r3, #4

  // TODO: set a breakpoint at _start and step through all the
  // instructions. What is the final value of r3 at this line? By
  // watching how the register values change, can you guess what the
  // previous lines are doing?

  mov r0, #0
  mov r7, #1
  swi 0

