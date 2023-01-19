/////////////////////////////////////////////////////////////////////////////
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

bool is_prime(int n, int i) {
    
    if (n == 1) {
        return false;
    }
    
    if (n <= 2) {
        if (n == 2) {
            return true;
        } else {
            false;
        }
    }
    
    if (n % i == 0) {
        return false;
    }
    
    if (i * i > n) {
        return true;
    }
    
    return is_prime(n, i + 1);
}

void print_primes(void) {
  int n = read_int();
  if (n == READ_INT_FAIL) {
    return;
  } else {
    if (is_prime(n, 2) == true) {
        printf("%d\n", n);
    }
    print_primes();
  }
}

int main(void) {
    print_primes();
}