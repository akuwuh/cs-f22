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

// intseq-pa.c [IMPLEMENTATION]

#include <stdbool.h>
#include <assert.h>
#include <stdlib.h>
#include <limits.h>

// See intsec.h
int number_sum(int *seq, int len){
	assert(seq);
    assert(len > 0);

    int sum = 0;

    for (int i = 0; i < len; i++) {
        int *x = seq + i;
        sum += *x;
    }

    return sum;

}

// See intsec.h
int max_number(int *seq, int len){
	assert(seq);
    assert(len > 0);
    int max = INT_MIN;

    for(int i = 0; i < len; i++) {
        int *x = seq + i;
        if(*x > max) {
            max = *x;
        }
    }

    return max;


}

// See intsec.h
int min_number(int *seq, int len){
	assert(seq);
    assert(len > 0);
    int min= INT_MAX;

    for(int i = 0; i < len; i++) {
        int *x = seq + i;
        if(*x < min) {
            min= *x;
        }
    }

    return min;
}

// See intsec.h
int minmax_dist(int *seq, int len){
	assert(seq);
    assert(len > 0);
    int min= INT_MAX;
    int max = INT_MIN;
    int max_i = 0;
    int min_i = 0;

    if( len == 1) {
        return 0;
    }

    if (len == 2) {
        return 1;
    }

    for(int i = 0; i < len; i++) {
        int *x = seq + i;
        if(*x < min) {
            min = *x;
            min_i = i;
        }

        if(*x > max) {
            max = *x;
            max_i = i;
        }
    }

    if (max_i > min_i) {
        return max_i - min_i;
    } else if (max_i < min_i){
        return min_i - max_i;
    } else {
        return 0;
    }
}

// See intsec.h
float seq_avg(int *seq, int len){
	assert(seq);
    assert(len >0);

    int sum= 0;

    for(int i = 0; i < len; i++ ) {
        int *x = seq + i;
        sum += *x;
    }

    return sum/len;

}

// See intsec.h
bool seq_has_duplicates(int *seq, int len){
	assert(seq);
    assert(len >0);

    for (int i = 0; i < len - 1; i++) {
        
        int *x = seq + i;
        for (int j = i + 1; j < len; j++) {
            int *y = seq + j;
            if (*x == *y) {
                return true;
            }
        }
    }

    return false;
}

// See intsec.h


// swap(xp, yp) swap the values of pointer xp and yp
// requires xp and yp to be valid
// effects: modifies the values of xp and yp
// efficiency: O(1)
void swap(int *xp, int *yp) {
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

// insertion_sort(a, len) sorts the elements of a
//   in increasing order
// requires: a is a valid array with given len [not asserted]
// effects: modifies a
// efficiency: O(n^2)


void insertion_sort(int a[], int len) {
  assert(a);
  assert(len > 0); 
  for (int i = 1; i < len; ++i) {
    for (int j = i; j > 0 && a[j - 1] > a[j]; --j) {
      swap(&a[j], &a[j - 1]);
    }
  }
}

int seq_most_occurrences(int *seq, int len){
    assert(seq);
    assert(len > 0);

    insertion_sort(seq, len);

    int count = 1;
    int max = *seq; // first element in array
    int temp = 1;

    for(int i =1; i < len; i++) {
        int *x = seq + i;
        int *y = seq +i -1;
        if (*x  == *y) {
            temp++;
        } else {
            if (temp > count) {
                count = temp;
                max = *(x-1);
            }
            temp = 1;
        }
    }

    if (temp > count) {
        count = temp; 
        max = *(seq + len - 1);
    }

    return max;

}
