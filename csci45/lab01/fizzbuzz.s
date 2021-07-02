.global fizzbuzz
.type fizzbuzz, %function
.func fizzbuzz
fizzbuzz:
  push {r4-r11, lr}
  // ===================================
  // DON'T TOUCH ANYTHING ABOVE THE LINE

  // FIXME: a nonnegative number has been placed in r0. Print:
  //   "fizz\n" if the number is divisible by 3
  //   "buzz\n" if the number is divisible by 5
  //   "fizzbuzz\n" if the number is divisible by 3 *and* 5
  // If none of the above apply, just do nothing.

  // There is no modulus (%) instruction in ARM assembly! How can you
  // get it using division, multiplication, and subtraction?

  // DON'T ADD ANY MORE CODE AFTER THIS LINE
  // (You'll still need to add .data)
  // =======================================
  pop {r4-r11, pc}

.data
// FIXME: include your strings to print here.
// Make sure not to use a label called `fizzbuzz`, since we already
// used that above.
