/////////////////////////////////////////////////////////////////////////////////////////
// INTEGRITY STATEMENT (v4)
//
// By signing your name and ID below you are stating that you have agreed
// to the online academic integrity statement posted on edX:
// (Course > Assignments > Assignment Information & Policies > Academic Integrity Policy)
/////////////////////////////////////////////////////////////////////////////////////////
// I received help from and/or collaborated with:

// No Help
//
// Name: Isaac Nguyen
// login ID: i3nguyen
//////////////////////////////////////////////////////////////////////////////////////////

#include "cs136.h"

// sign(n) returns the signum (or sign) of n.
//             ┌  -1 if n < 0;
//   sign(n) = |   0 if n = 0;
//             └   1 if n > 0.
//requires: n is an int
int sign(int n) {
  
  if(n > 0) {
      return 1;
  }
  
  if(n < 0) {
      return -1;
  }
  
  return 0;
}

int main(void) {
  // public test
  assert(sign(136) == 1);
  assert(sign(-1) == -1);
  assert(sign(1) == 1);
  assert(sign(0) == 0);
  assert(sign(10) == 1);
  assert(sign(-10) == -1);

  return EXIT_SUCCESS;
}