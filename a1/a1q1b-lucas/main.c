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

// lucas(n) returns the n-th Lucas number
// requires: n >= 0
int lucas(int n) {
  assert(n >= 0);
  
  if (n == 0) {
      return 2;
  }
  
  if (n == 1) {
      return 1;
  }
  
  return lucas(n - 1) + lucas(n - 2);
}

int main(void) {
  // public tests
  assert(lucas(0) == 2);
  assert(lucas(3) == 4);
  assert(lucas(9) == 76);
  

  // add your own tests below

  return EXIT_SUCCESS;
}