// A program to test the quicksort module

#include <stdlib.h>
#include "array_tools.h"
#include "quicksort.h"

// === PREDICATES =============================================================

// pred_lg(a, b) returns true if a is larger than b, and false otherwise.
bool pred_lg(int a, int b) {
  return a > b;
}

// pred_sm(a, b) returns true if a is smaller than b, and false otherwise.
bool pred_sm(int a, int b) {
  return a < b;
}

// pred_even_first(a, b) sorts small-to-large if both or neither a and b are
//   even. Otherwise, it sorts even values before odd values.
bool pred_even_first(int a, int b) {
  if (a % 2 == 0 && b % 2 != 0) {
    return false;
  } else if (a % 2 != 0 && b % 2 == 0) {
    return true;
  } else {
    return a > b;
  }
}

// === MAIN FUNCTION ==========================================================

int main(void) {
  int arr[100] = { 0 };
  int arr_len = array_read(arr, 100);

  quick_sort(arr, arr_len, pred_lg);
  quick_sort(arr, arr_len, pred_even_first);
  quick_sort(arr, arr_len, pred_sm);

  return EXIT_SUCCESS;
}