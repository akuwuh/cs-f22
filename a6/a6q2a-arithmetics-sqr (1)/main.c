// This program tests the arithmetics-sqr module

#include <assert.h>
#include "arithmetics-sqr.h"
#include "cs136-trace.h"

const double EPSILON = 0.01;

// dabs(n) finds the absolute value of the double n
static double dabs(double n){
  if (n < 0) {
    return -n;
  }
  return n;
}

int main(void) {
  int a[] = {2,2};
  trace_int(2);
  assert(dabs((mean(a,2)-2.0)) < EPSILON);
  assert(dabs((var(a,2)-0.0)) < EPSILON);
}