.global _start
_start:
  // output prompt
  mov r7, #4
  mov r0, #1
  ldr r1, =prompt
  mov r2, #34
  swi 0

  // get the sub-board
  mov r7, #3
  mov r0, #0
  ldr r1, =board_piece
  mov r2, #4
  swi 0

  // FIXME: using the input row/column/diagonal (stored in the
  // `board_piece` string), see if there is a winner. If there is one,
  // print the winner followed by a newline. If there is no winner,
  // print a question mark followed by a newline.

  // exit
  mov r0, #0
  mov r7, #1
  swi 0


.data
prompt: .ascii "Enter a row, column, or diagonal:\n"
board_piece: .ascii "???\n"
