/////////////////////////////////////////////////////////////////////////////////////////
// INTEGRITY STATEMENT (v4)
//
// By signing your name and ID below you are stating that you have agreed
// to the online academic integrity statement posted on edX:
// (Course > Assignments > Assignment Information & Policies > Academic Integrity Policy)
/////////////////////////////////////////////////////////////////////////////////////////
// I received help from and/or collaborated with:

// Office Hours
//
// Name: Isaac Nguyen
// login ID: i3nguyen
//////////////////////////////////////////////////////////////////////////////////////////

#include "cs136.h"

//sums up all the digits
int every_other_sum(int n, int counter) {
    
    int dig = n % 10;
    int new = n / 10;

    //doubles and add eveyr other number
    if(counter % 2 == 0) {
        dig *= 2;
    }
    
    int new_dig = (dig % 10) + (dig / 10);
    
    if(new == 0) {
        return new_dig;
    }
    
    return new_dig + every_other_sum(new, counter+1);
}

// validate_checksum(n) returns true if the last digit of n is the correct
//                      checksum as calculated by the Luhn algorithm and
//                      false otherwise.
// requires: n >= 10
bool validate_checksum(int n) {
  assert(n >= 10);
  
  int check_digit = n%10;
  
  int payload = n/10;
  
  int check_sum = every_other_sum(payload, 0);
  
  if (10 - (check_sum % 10) == check_digit) {
      return true;
  }
  
  
  return false;
}

int main(void) {
  // public tests
  assert(validate_checksum(640754297));
  assert(!validate_checksum(640754291));
  

  // add your own tests below

  return EXIT_SUCCESS;
}