.global darkenNEON
.func darkenNEON
.type darkenNEON, %function
darkenNEON:
  push {r4-r11, lr}
  
  // FIXME: implement the void darkenNEON(char* pixelsStart, int numPixels)
  // function to darken numPixels pixels starting at pixelsStart. Do
  // this by halving the value in each color channel. numPixels is
  // guaranteed to be a multiple of 8 so that you can use 64-bit NEON
  // registers.

  pop {r4-r11, pc}

