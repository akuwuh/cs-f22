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

#include "cs136.h"

void store_mem(int *mp, int value) {
    assert(value);
    *mp = value; 
}

void replace_current(int *mp, int *current) {
    assert(mp); 
    assert(current);
    *current = *mp;
} 

/*
if (c == 'p') {
            printf("%d", current);
        }
        
        if (c == 'c') {
            current = 0;
        }
        
        if (c == 'm') {
            store_mem(&mem, current);
        }
        
        if (c == 'q') {
            break;
        }
        
        if (c == 'r') {
            replace_current(&mem, &current);
        } */

int calculator(void) {
  int current = 0;
  int mem = 0;
  char c = '\0';
  while (scanf(" %c", &c) == 1) {
    if (c == 'p') {
        printf("%d\n" , current);
        continue;
    }
        
    if (c == 'c') {
        current = 0;
        continue;
    }
        
    if (c == 'm') {
        store_mem(&mem, current);
        continue;
    }
        
    if (c == 'q') {
        return 0;
    }
        
    if (c == 'r') {
        replace_current(&mem, &current);
        continue;
    }
    
    if (c == '+') {
        int val = 0;
        if (scanf(" %d", &val) == 1) {
            current += val;
        }
        
        continue;
    }
    
    if (c == '-') {
        int val = 0;
        if (scanf(" %d", &val) == 1) {
            current -= val;
        }
        
        continue;
    }
    
    if (c == '*') {
        int val = 0;
        if (scanf(" %d", &val) == 1) {
            current *= val;
        }
        
        continue;
    }
    
    if (c == '/') {
        int val = 0;
        if (scanf(" %d", &val) == 1) {
            if (val == 0) {
               printf("DIV0\n");
               return 0;
            }
            current /= val;
        }
        
        continue;
    }
    
    if (c == '%') {
        int val = 0;
        if (scanf(" %d", &val) == 1) {
            if (val == 0) {
               printf("DIV0\n");
               return 0;
            }
            current %= val;
        }
        
        continue;
    }
    printf("INVALID\n");
    return 0;
  }
  printf("INVALID\n");
  return 0;
}

int main(void) {
  calculator();
}
