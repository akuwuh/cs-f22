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
// login ID: Ei3nguyen
//////////////////////////////////////////////////////////////////////////////////////////

// bubble_sort.c [IMPLEMENTATION]

#include "cs136-trace.h"
#include "bubble_sort.h"
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>

// swap(a, b) swaps the value in a and b.
// requires a and b to be valid pointers
// effect: modifies the location of pointers a and b
// Efficiency: O(1)
static void swap(int *a, int *b) {
  assert(a && b);
  int tmp = *a;
  *a = *b;
  *b = tmp;
}

// see bubble_sort.h
int bubble_sort(int a[], int len) {
    assert(len > 0);
    
    int counter = 0;

    for( int i = 0; i < len - 1; i++) {
        for(int j = 0; j < len - 1 - i; j++) {
            if(a[j] > a[j+1]){
                swap(&a[j], &a[j+1]);
                counter++;
            }
        }
    }

    return counter;
}