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

// largest-sum.c [IMPLEMENTATION]

#include "largest-sum.h"
#include <limits.h>
#include <assert.h>


// See largest-sum.h
// time: O(n^2)
int largest_sum(const int array[], int len, int n) {
    assert(n>=0);
    int prev = -1;
    int ans = 0;

    while (n > 0 ) {
        int cur =INT_MIN;
        int occ = 0;
        if(prev == -1) {
            for(int i=0;i<len;i++) {
                if(array[i] > cur){
                    cur = array[i];
                }
            }
        }
        else{
            for (int i = 0; i < len; i++) {
                if (array[i] > cur && array[i] < prev) {
                    cur = array[i];
                }
            }
        }

        for (int i = 0; i < len; i++) {
            if (array[i] == cur) {
                occ++;
            }
        }

        if (occ > n) {
            ans += (n * cur);
            break;
        } else {
            n-= occ;
            ans += (occ * cur);
        }

        prev = cur;
    }

    return ans;
}