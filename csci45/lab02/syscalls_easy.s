.global main
.type main, %function
.func main
main:
  push {r4-r11, lr}

  // List of arm32 syscalls: https://chromium.googlesource.com/chromiumos/docs/+/master/constants/syscalls.md#arm-32_bit_EABI

  // FIXME: call the "getuid" syscall (not getuid32) to get your user
  // ID (every user account on a Linux system has an ID). The syscall
  // takes no parameters and returns the value in the r0 register.

  // FIXME: Print the user ID that you get back as an unsigned integer
  // value using printf and the %u specifier (instead of %d). Print a
  // newline too. That's all you need to do for this program--now
  // you're done!

  // You can use `echo $UID` or `id` on the terminal to confirm that
  // the number you print is correct.

  // return 0
  mov r0, #0
  pop {r4-r11, pc}
