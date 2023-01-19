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
// login ID: i3gnuyen
//////////////////////////////////////////////////////////////////////////////////////////

// quicksort.c [IMPLEMENTATION]

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include "quicksort.h"
#include "array_tools.h"

// === HELPER FUNCTIONS =======================================================

// swap(a, b) swaps the value in a and b.
// requires: a and b to be valid pointers
// effect: modifies the values at the location of a and b
// Efficiency: O(1)
static void swap(int *a, int *b) {
  assert(a && b);
  int tmp = *a;
  *a = *b;
  *b = tmp;
}

// === QUICK SORT =============================================================

// quick_sort_worker(first, last, pred, arr, arr_len) sorts the elements between
//   first and last by pred using quick sort. arr and arr_len are used for debug
//   output only.
// requires first, last, pred, and arr to be valid pointers and arr_len > 0
// effect: might modify arr
// Efficiency: O(nlog(n))
static void quick_sort_worker(int *first, int *last, bool(*pred)(int, int),
                              int *arr, int arr_len) {
  // your implementation goes here
  assert(first);
  assert(last);
  assert(arr);
  assert(arr_len >= 1);
  assert(pred);

  int f = *first;
  int l = *last;
  
  if (f < l) {                    // if there are still some elements to sort
    int pivot = *(arr + f);              // pick pivot element
    int swapper = l;   // set the swapper to the last element in arr

    for (int i = l; i > f; --i) { // going backwards through arr
      int arr_i = *(arr  + i);
      if (pred(arr_i, pivot)) {         // if arr[i] should be "right of" pivot
        swap(arr + swapper, arr + i);    // swap arr[i] and swapper
        --swapper;                       // move the swapper to the next "unswapped" element
      }
    }

    swap(arr + f, arr + swapper);    // swap the pivot element into the right spot
    array_print(arr, arr_len);

    *last = swapper - 1;

    quick_sort_worker(first, last, pred, arr, arr_len); //  recursive call on the "left" sub-array

    *first = swapper +1;
    *last = l;
    quick_sort_worker(first, last, pred, arr, arr_len);  // recursive call on the "right" sub-array
  }

}

// see quicksort.h for documentation
void quick_sort(int *arr, int arr_len, bool(*pred)(int, int)) {
  assert(arr_len >= 1);
  assert(pred);
  // your implementation goes here
  int first = 0;
  int last = arr_len -1;
  quick_sort_worker(&first, &last, pred, arr, arr_len);
}
