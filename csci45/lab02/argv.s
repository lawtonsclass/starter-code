.global main
.type main, %function
.func main
main:
  push {r4-r11, lr} // an easy way to save all the required registers
  // argc is in r0
  // argv is in r1

  // FIXME: iterate through argv and print every element in order, each on a
  // separate line


  // return 0
  mov r0, #0
  pop {r4-r11, pc}

// FIXME: you'll probably want to add a .data section