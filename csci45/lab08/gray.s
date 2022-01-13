.global grayVFP
.func grayVFP
.type grayVFP, %function
grayVFP:
  push {r4-r11, lr}

  // Set the rounding mode to make sure we're rounding to the nearest
  // whole number (since for some reason there are other options)
  vmrs r2, fpscr
  // we want to clear bits 22 and 23 of the fpscr
  mov r3, #3
  lsl r3, r3, #22
  bic r2, r2, r3
  vmsr fpscr, r2
  
  // FIXME: implement the void grayVFP(char* pixelsStart, int numPixels)
  // function to convert numPixels pixels starting at pixelsStart to
  // grayscale. Do this by calculating the value:
  //   grayscale_value = 0.2126*red + 0.7152*green + 0.0722*blue
  // and rounding the result to the nearest whole number. Use double
  // precision floating point numbers in all your calculations. Change
  // the red, green, and blue channels of the original pixel all to
  // grayscale_value.

  // Remember that VFP is *not* Neon--you can't work on multiple pixels at a time
  // Hint 1: So, read a single color at a time for a single pixel with ldrb
  // Hint 2: Put that color in a 32-bit VFP register with vmov
  // Hint 3: Use vcvt to widen/convert the 32-bit int into a 64-bit float
  // Hint 4: use the vcvtr instruction to do the rounding and conversion to a 32-bit int

  pop {r4-r11, pc}
