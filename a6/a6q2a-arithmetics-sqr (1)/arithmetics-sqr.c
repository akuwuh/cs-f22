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

//arithmetics-sqr.c [IMPLEMENTATION]

#include "cs136-trace.h"
#include "arithmetics-sqr.h"
#include <assert.h>

// see arithmetics-sqr.h for documentation
double mean(const int a[], int len) {
    assert(a);
    assert(len > 0);

    int sum =0; 
    for( int i = 0; i < len; ++i) {
        sum+= a[i];
    }

    return sum/len;
}




// see arithmetics-sqr.h for documentation
double var(const int a[], int len) {
    int sum = 0;
    int ex = mean(a, len);

    for( int i =0; i < len; ++i) {
        int sd = (a[i] - ex);
        sum += sd * sd;
    }

    return sum/len;
    
}


