.global main
.type main, %function
main:
  sub sp, sp, #16
  str lr, [sp]

  // List of arm64 syscalls: https://gpages.juszkiewicz.com.pl/syscalls-table/syscalls.html

  // FIXME: call the "getuid" syscall (not getuid32) to get your user
  // ID (every user account on a Linux system has an ID). The syscall
  // takes no parameters and returns a 4-byte value in the w0 register.

  // FIXME: Print the user ID that you get back as an unsigned integer
  // value using printf and the %u specifier (instead of %d). Print a
  // newline too. That's all you need to do for this program--now
  // you're done!

  // You can use `echo $UID` or `id` on the terminal to confirm that
  // the number you print is correct.

  // return 0
  mov w0, #0
  ldr lr, [sp]
  add sp, sp, #16
  ret
