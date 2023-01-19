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

//arithmetics-ptr.c [IMPLEMENTATION]

#include <assert.h>
#include "arithmetics-ptr.h"

//see arithmetics-ptr.h for documentation
void stats(const int *a, int len, struct statistics *s) {
    assert(a);
    assert(len > 0);
    assert(s);

    int sum = 0;

    for(int i = 0; i < len; i++) {
        const int *x = a + i;

        if (*x < s->min) {
            s->min = *x;

        }

        if (*x > s->max) {
            s->max = *x;
        }

        sum += *x;

    }

    s->sum = sum;
}