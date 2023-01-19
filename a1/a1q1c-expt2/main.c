/////////////////////////////////////////////////////////////////////////////////////////
// INTEGRITY STATEMENT (v4)
//
// By signing your name and ID below you are stating that you have agreed
// to the online academic integrity statement posted on edX:
// (Course > Assignments > Assignment Information & Policies > Academic Integrity Policy)
/////////////////////////////////////////////////////////////////////////////////////////
// I received help from and/or collaborated with:

// No one
//
// Name: Isaac Nguyen
// login ID: i3nguyen
//////////////////////////////////////////////////////////////////////////////////////////

#include "cs136.h"

// expt2_simple(n) returns 2^n using simple recursion.
// requires: n must be non-negative
int expt2_simple(int n) {
  assert(n >= 0);
  
  if (n == 0) {
      return 1;
  }
  
  return 2 * expt2_simple(n-1);
}

int expt2_helper(int n, int acc) {
    
    if (n == 0) {
        return acc;
    }
    
    acc *= 2;
    
    return expt2_helper(n-1, acc);
}

// expt2_acc(n) returns 2^n using accumulative recursion.
// requires: n must be non-negative
int expt2_acc(int n) {
  assert(n >= 0);
  if ( n == 0) {
      return 1;
  }
  
  return expt2_helper(n, 1);
}

int main(void) {
  // public tests
  assert(expt2_simple(3) == 8);
  assert(expt2_acc(3) == 8);

  // add your own tests below

  return EXIT_SUCCESS;
}