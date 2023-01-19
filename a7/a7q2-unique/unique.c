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

// unique.c [IMPLEMENTATION]

#include <stdbool.h>
#include "unique.h"
#include <assert.h>
#include "mergesort.h"
bool distinct(int a[], int len) {
  assert(len > 0);
  merge_sort(a, len);
  for(int i=1; i<len; i++) {
    if(a[i]==a[i-1]) {
      return false;
    }
  }
	return true;
}
// see unique.h for documentation
bool distinct_range(const int a[], int len) {
  // ADDITIONAL CONSTRAINTS:
  //   * You may only loop through array a ONCE
  //   * You may define a local array of size 10000
  int seen[10000] = {0};
  for (int i = 0; i < len; i++) {
    int val = a[i];
    seen[val - 1]++;
  }

  for (int i = 0; i< 10000; i++) {
    if(seen[i] > 1) {
      return false;
    }
  }

	return true;
}


int missing(const int a[], int n) {
  // ADDITIONAL CONSTRAINTS:
  //   * You may only loop through array a ONCE
  //   * You may NOT define a local array

  int sum = 0;
  for(int i = 1; i <=n; i++) {
    sum+=i;
  }

  for(int i = 0; i < (n -1); i++) {
    sum-= a[i];
  }

	return sum;
}