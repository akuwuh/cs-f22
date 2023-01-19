/////////////////////////////////////////////////////////////////////////////////////////
// INTEGRITY STATEMENT (v4)
//
// By signing your name and ID below you are stating that you have agreed
// to the online academic integrity statement posted on edX:
// (Course > Assignments > Assignment Information & Policies > Academic Integrity Policy)
/////////////////////////////////////////////////////////////////////////////////////////
// I received help from and/or collaborated with:

// No One
//
// Name: Isaac Nguyen
// login ID: i3nguyen
//////////////////////////////////////////////////////////////////////////////////////////

// This program implements functions to order four fields in a structure
// and to see if they are ordered

#include "cs136.h"

// Used to specify the order we want
// DO NOT CHANGE THESE VALUES
const int LOW_TO_HIGH = 1;
const int HIGH_TO_LOW = 2;

// This is the structure to use
// DO NOT CHANGE THIS
struct four_nums {
  int first;
  int second;
  int third;
  int fourth;
};

// is_ordered_four(direction, f) checks the fields of the structure f
//   to see if they are ordered in the specify direction.
//   If they are return true, otherwise return false.
// requires: f points to a valid structure
bool is_ordered_four(int direction, struct four_nums *f) {
  // Add the PART A implementation
  assert(f);
  assert(direction == 1 || direction == 2);
  int first = f->first;
  int second = f->second;
  int third = f->third;
  int fourth = f->fourth;
  
  if(direction == 1) {
    if (first <= second && second <= third && third <= fourth) {
        return true;
    } else {
        return false;
    }
  } else if(direction == 2) {
    if (first >= second && second >= third && third >= fourth) {
        return true;
    } else {
        return false;
    }
  } else {
    return false; 
  }

}

// is_ordered_four_broken1(direction, f) same as is_ordered_four except
//    it must not work correctly in some cases
//    (i.e., it has one or more bugs)
bool is_ordered_four_broken1(int direction, struct four_nums *f) {
  return false; // REMOVE OR CHANGE
}

// test_is_ordered(fp) uses the function pointed to by fp
//   to test if that function is working correctly.
//   Returns true if all of the test are successful,
//   otherwise it returns false
// requires: fp must point to a valid function 
bool test_is_ordered(bool (*fp)(int, struct four_nums *)) {
  // Add the PART B implementation
  assert(fp);
  struct four_nums f1 = {1,2,3,4}; //check for low to high
  struct four_nums f2 = {4,3,2,1}; //check for high to low 
  struct four_nums f3 = {1,1,2,2}; //checks low to high with similar values
  struct four_nums f4 = {3,2,2,1}; //checks for high to low with similar values
  struct four_nums f5 = {2,3,3,1}; //wrong
  
  int counter = 0;
  
  if(fp(LOW_TO_HIGH, &f1) == 1) {
      counter++;
  }
  
  if(fp(HIGH_TO_LOW, &f2) == 1) {
      counter++;
  }
  
  if(fp(LOW_TO_HIGH, &f3) == 1) {
      counter++;
  }
  
  if(fp(HIGH_TO_LOW, &f4) == 1) {
      counter++;
  }
  
  if(fp(HIGH_TO_LOW, &f5) == 0 && fp(LOW_TO_HIGH, &f5) == 0) {
      counter++;
  }
  
  if(counter == 5) {
      return true;
  }
  
  return false; // REMOVE OR CHANGE
}

// order_four(direction, f) orders fields of the structure f
//   according to the specified direction
//   E.g., after calling this function with the direction LOW_TO_HIGH
//   the values of the fields of f will be ordered as
//   first <= second <= third <= fourth
// effect: may modify the structure f
// requires: f points to a valid structure
//           direction must be LOW_TO_HIGH or HIGH_TO_LOW
void order_four(int direction, struct four_nums *f) {
  // Add the PART C implementation
  assert(f);
  assert(direction == 1 || direction == 2);
  if (is_ordered_four(direction, f) == 1 ) {
      return;
  } 
  
  int n1 = f->first;
  int n2 = f->second;
  int n3 = f->third;
  int n4 = f->fourth;
  
  int one = 0; //lowest
  int two = 0;
  int three = 0;
  int four = 0; //highest
  
  //n1 is the lowest number
  if (n1 <= n2 && n1 <= n3 && n1 <= n4) {
    one = n1;
    // n2 is second lowest (2,3,4)
    if (n2 <= n3 && n2 <= n4) {
        two = n2;
        if (n3 <= n4) {
            three = n3;
            four = n4;
        } else {
            three = n4;
            four = n3;
        }
    }
    
    // n3 is second lowest
    if (n3 <= n2 && n3 <= n4) {
        two = n3;
        if (n2 <= n4) {
            three = n2;
            four = n4;
        } else {
            three = n4;
            four = n2;
        }
    }
    
    // n4 is second lowest
    if (n4 <= n2 && n4 <= n3) {
        two = n4;
        if (n2 <= n4) {
            three = n2;
            four = n3;
        } else {
            three = n3;
            four = n2;
        }
    }
  }
  
  
  //n2 is the lowest number
  if (n2 <= n1 && n2 <= n3 && n2 <= n4) {
    one = n2;
    // n1 is second lowest (1,34)
    if (n1 <= n3 && n1 <= n4) {
        two = n1;
        if (n3 <= n4) {
            three = n3;
            four = n4;
        } else {
            three = n4;
            four = n3;
        }
    }
    
    // n3 is second lowest
    if (n3 <= n1 && n3 <= n4) {
        two = n3;
        if (n1 <= n4) {
            three = n1;
            four = n4;
        } else {
            three = n4;
            four = n1;
        }
    }
    
    // n4 is second lowest
    if (n4 <= n1 && n4 <= n3) {
        two = n4;
        if (n1 <= n3) {
            three = n1;
            four = n3;
        } else {
            three = n3;
            four = n1;
        }
    }
  }
  
  //n3 is the lowest number
  if (n3 <= n2 && n3 <= n1 && n3 <= n4) {
    one = n3;
    // n2 is second lowest (1,2,4)
    if (n2 <= n1 && n2 <= n4) {
        two = n2;
        if (n1 <= n4) {
            three = n1;
            four = n4;
        } else {
            three = n4;
            four = n1;
        }
    }
    
    // n1 is second lowest
    if (n1 <= n2 && n1 <= n4) {
        two = n1;
        if (n2 <= n4) {
            three = n2;
            four = n4;
        } else {
            three = n4;
            four = n2;
        }
    }
    
    // n4 is second lowest
    if (n4 <= n2 && n4 <= n1) {
        two = n4;
        if (n2 <= n1) {
            three = n2;
            four = n1;
        } else {
            three = n1;
            four = n2;
        }
    }
  }
  
  //n4 is the lowest number
  if (n4 <= n2 && n4 <= n3 && n4 <= n1) {
    one = n4;
    // n2 is second lowest (1,2,3)
    if (n2 <= n3 && n2 <= n1) {
        two = n2;
        if (n3 <= n1) {
            three = n3;
            four = n1;
        } else {
            three = n1;
            four = n3;
        }
    }
    
    // n3 is second lowest
    if (n3 <= n2 && n3 <= n1) {
        two = n3;
        if (n2 <= n1) {
            three = n2;
            four = n1;
        } else {
            three = n1;
            four = n2;
        }
    }
    
    // n1 is second lowest
    if (n1 <= n2 && n1 <= n3) {
        two = n1;
        if (n2 <= n3) {
            three = n2;
            four = n3;
        } else {
            three = n3;
            four = n2;
        }
    }
  }

  if (direction == 1) {
        f->first = one;
        f->second = two;
        f->third = three;
        f->fourth = four;
  } else if (direction == 2) {
        f->first = four;
        f->second = three;
        f->third = two;
        f->fourth = one;
  }

  return; // REMOVE OR CHANGE
}

// order_four_broken1(direction, f) same as order_four except
//    it must not work correctly in some cases
//    (i.e., it has one or more bugs)
void order_four_broken1(int direction, struct four_nums *f) {
  return; // REMOVE OR CHANGE
}

// test_order(fp) uses the function pointed to by fp
//   to test if that function is working correctly
//   Returns true if all of the test are successful,
//   otherwise it returns false
// requires: fp must point to a valid function 
bool test_order(void (*fp)(int, struct four_nums *)) {
  // Add the PART D implementation
  assert(fp);
  
  //random structs:
  
  struct four_nums f1 = {3,2,7,4}; 
  struct four_nums f2 = {4,5,2,1}; 
  struct four_nums f3 = {1,3,2,6}; 
  struct four_nums f4 = {3,9,2,4}; 
  struct four_nums f5 = {2,7,3,8}; 
  
  int counter = 0;
  
  fp(HIGH_TO_LOW, &f1);
  if(is_ordered_four(HIGH_TO_LOW, &f1) == 1) {
      counter++;
  }
  fp(LOW_TO_HIGH, &f1);
  if(is_ordered_four(LOW_TO_HIGH, &f1) == 1) {
      counter++;
  }
  
  fp(HIGH_TO_LOW, &f2);
  if(is_ordered_four(HIGH_TO_LOW, &f2) == 1) {
      counter++;
  }
  fp(LOW_TO_HIGH, &f2);
  if(is_ordered_four(LOW_TO_HIGH, &f2) == 1) {
      counter++;
  }
  
  
  fp(HIGH_TO_LOW, &f3);
  if(is_ordered_four(HIGH_TO_LOW, &f3) == 1) {
      counter++;
  }
  fp(LOW_TO_HIGH, &f3);
  if(is_ordered_four(LOW_TO_HIGH, &f3) == 1) {
      counter++;
  }
  
  
  fp(HIGH_TO_LOW, &f4);
  if(is_ordered_four(HIGH_TO_LOW, &f4) == 1) {
      counter++;
  }
  fp(LOW_TO_HIGH, &f4);
  if(is_ordered_four(LOW_TO_HIGH, &f4) == 1) {
      counter++;
  }
  
  fp(HIGH_TO_LOW, &f5);
  if(is_ordered_four(HIGH_TO_LOW, &f5) == 1) {
      counter++;
  }
  fp(LOW_TO_HIGH, &f5);
  if(is_ordered_four(LOW_TO_HIGH, &f5) == 1) {
      counter++;
  }
  
  if(counter == 10) {
      return true;
  }
  
  return false; // REMOVE OR CHANGE
}

int main(void) {
  // NOTE THAT THIS PROGRAM WILL NOT RUN CORRECTLY
  // UNTIL ALL PARTS ARE IMPLEMENTED PROPERLY

  // Run tests with a version that works
  assert(test_is_ordered(is_ordered_four) == true);
  // Run tests with versions that don't work 
  assert(test_is_ordered(is_ordered_four_broken1) == false);

  // Run tests with a version that works
  assert(test_order(order_four) == true);
  // Run tests with versions that don't work 
  assert(test_order(order_four_broken1) == false);

}