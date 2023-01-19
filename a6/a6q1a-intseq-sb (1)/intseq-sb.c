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

// intseq-sb.c [IMPLEMENTATION]

#include <stdbool.h>
#include <assert.h>
#include <stdlib.h>

// See intsec.h
int number_sum(int seq[], int len){
    assert(seq);
    assert(len > 0);
	int sum = 0;
    for (int i = 0; i < len; i++ ) {
        sum+=seq[i];

    }
    return sum;
}

// See intsec.h
int max_number(int seq[], int len){
    assert(seq);
    assert(len > 0);
	int max = seq[0];
    for (int i = 1; i < len; i++) {
        if (seq[i] > max) {
            max = seq[i];
        }
        
    }   
    return max;
}

// See intsec.h
int min_number(int seq[], int len){
    assert(seq);
    assert(len > 0);
	int min = seq[0];
    for (int i = 1; i < len; i++) {
        if (seq[i] < min) {
            min = seq[i];
        }
        
    }
    return min;
}

// See intsec.h
int minmax_dist(int seq[], int len){
    assert(seq);
    assert(len > 0);
	int max = max_number(seq,len);
    int min= min_number(seq,len);
    int max_i = 0;
    int min_i = 0;

    for ( int i = 0; i < len; i++) {
        if (seq[i] == max) {
            max_i = i;
        }

        if (seq[i] == min) {
            min_i = i;
        }
    }

    return abs(max_i - min_i);
}

// See intsec.h
float seq_avg(int seq[], int len){
    assert(seq);
    assert(len > 0);
	int sum = number_sum(seq, len);
    return sum/len;
}

// See intsec.h
bool seq_has_duplicates(int seq[], int len){
    assert(seq);
    assert(len > 0);
    for (int i = 0; i < len - 1; i++) {
        
        for (int j = i + 1; j < len; j++) {
            if (seq[i] == seq[j]) {
                return true;
            }
        }
    }

    return false;
	
}

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

// See intsec.h
int seq_most_occurrences(int seq[], int len){
    assert(seq);
    assert(len > 0);

    insertion_sort(seq, len);

    int count = 1;
    int max = seq[0]; // first element in array
    int temp = 1;

    for(int i =1; i < len; i++) {
        if (seq[i]  == seq[i-1]) {
            temp++;
        } else {
            if (temp > count) {
                count = temp;
                max = seq[i-1];
            }
            temp = 1;
        }
    }

    if (temp > count) {
        count = temp; 
        max = seq[len-1];
    }

    return max;



}