// This program tests bubble sort

#include <assert.h>
#include "cs136-trace.h"
#include "array_tools.h"
#include "bubble_sort.h"

int main(void) {
  int input[5] = {5, 4, 3, 2, 1};
  int sorted[5] = {1, 2, 3, 4, 5};
  assert(bubble_sort(input,5) == 10);
  assert(array_equal(input,sorted,5));
}
