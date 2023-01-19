// A program to test the largest-sum module

#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
#include <assert.h>
#include "largest-sum.h"

int main(void) {
  int array1[] = {0, 1, 2, 3, 4, 5, 6};
  int array2[] = {-6, -5, -4, -3, -2};
  int array3[] = {-6, -5, -4, -3, INT_MAX};
  int array4[] = {10, 10, 10, 10, 10};

  assert(largest_sum(array1, sizeof(array1)/sizeof(int), 1) == 6);
  assert(largest_sum(array1, sizeof(array1)/sizeof(int), 2) == 11);
  assert(largest_sum(array1, sizeof(array1)/sizeof(int), 3) == 15);
  assert(largest_sum(array1, sizeof(array1)/sizeof(int), sizeof(array1)/sizeof(int)) == 21);

  assert(largest_sum(array2, sizeof(array2)/sizeof(int), 1) == -2);
  assert(largest_sum(array2, sizeof(array2)/sizeof(int), 2) == -5);
  assert(largest_sum(array2, sizeof(array2)/sizeof(int), 3) == -9);

  assert(largest_sum(array3, sizeof(array3)/sizeof(int), 1) == INT_MAX);
  assert(largest_sum(array3, sizeof(array3)/sizeof(int), 2) == INT_MAX-3);
  assert(largest_sum(array3, sizeof(array3)/sizeof(int), 3) == INT_MAX-3-4);

  assert(largest_sum(array4, sizeof(array2)/sizeof(int), 1) == 10);
  assert(largest_sum(array4, sizeof(array2)/sizeof(int), 2) == 20);
  assert(largest_sum(array4, sizeof(array2)/sizeof(int), 3) == 30);
  assert(largest_sum(array4, sizeof(array2)/sizeof(int), 4) == 40);
  assert(largest_sum(array4, sizeof(array2)/sizeof(int), 5) == 50);
}