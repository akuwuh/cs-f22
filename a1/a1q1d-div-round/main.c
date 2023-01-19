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
// Name: i3nguyen
// login ID: Isaac Nguyen
//////////////////////////////////////////////////////////////////////////////////////////

#include "cs136.h"

// div_half_away(num, denom) returns the fraction of numerator num divided by
//   denominator denom, rounded towards the next integer:
//   Remainder of [0.0 ... 0.5) is rounded towards 0.
//   Remainder of [0.5 ... 1.0) is rounded away from 0.
// requires: denom must not be zero
int div_half_away(int num, int denom) {
  assert(denom != 0);
  
  int i = 0; //numerator place holder
  int r = 0; //denominator place holder
  int x =0; // will be return output
  
  
  //case for both num and denom are negative
  if (num < 0 && denom < 0) {
    
    i = -1 * num;
    r = -1 * denom;
    x = (i + (r / 2)) / r;
    return x;
  }
  
  //case for either num or denom is positive
  
  if (num < 0 || denom < 0) {
      i =  -1 * num;
      x = (i + (denom / 2)) / denom;
      return -1 * x;
  }
  
  //standard case of both positive
  i = num;
  r = denom;
  x = (i + (r / 2)) / r;
  
  return x;
  
  
}

// div_instructor(num, denom) returns the fraction of numerator num divided by
//   denominator denom, rounded towards the next integer:
//   Remainder of [0.0 ... 0.333...) is rounded towards 0.
//   Remainder of [0.333... ... 1.0) is rounded away from 0.
// requires: denom must not be zero
int div_instructor(int num, int denom) {
  assert(denom != 0);
  
  int i = 0; //numerator place holder
  int r = 0; //denominator place holder
  int x =0; // will be return output
  
  
  //case for both num and denom are negative
  if (num < 0 && denom < 0) {
    
    i = -1 * num;
    r = -1 * denom;
    x = (i + ((2*r) / 3)) / r;
    return x;
  }
  
  //case for either num or denom is positive
  
  if (num < 0 || denom < 0) {
      i =  -1 * num;
      x = (i + ((2*denom) / 3)) / denom;
      return -1 * x;
  }
  
  //standard case of both positive
  i = num;
  r = denom;
  x = (i + ((2*r) / 3)) / r;
  
  return x;
 
}

int main(void) {
  // public tests
  assert(div_half_away(10, 4) == 3);     //  10 /  4 =  2.5      =>  3
  assert(div_half_away(-10, 3) == -3);   // -10 /  3 = -3.333... => -3
  assert(div_half_away(10, -3) == -3);
  assert(div_half_away(10, -4) == -3);
  assert(div_half_away(-10, -4) == 3);
  assert(div_half_away(0, -4) == 0);
  
  assert(div_instructor(10, 3) == 4);    //  10 /  3 =  3.333... =>  4
  assert(div_instructor(-43, 10) == -4); // -43 / 10 = -4.3      => -4
  
  // add your own tests below
  
  return EXIT_SUCCESS;
}