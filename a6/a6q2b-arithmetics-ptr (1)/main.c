// This program tests the arithmetics module

#include <assert.h>
#include "arithmetics-ptr.h"

int main(void) {
  int a[2] = {2, 2};
  struct statistics s = {2, 2, 4};
  stats(a, 2, &s);
  assert(s.min == 2);
  assert(s.max == 2);
  assert(s.sum == 4);
}