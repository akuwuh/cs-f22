//arithmetics-ptr.h [INTERFACE]
// This module performs some basic statistics on an array

struct statistics{
  int min;
  int max;
  int sum;
};

// stats(a, len, s) mutates the fields of the s such that the maximum,
//   minimum and sum fields are the maximum, minimum and sum of the
//   array elements in a respectively.
// Requires: a valid, len > 0, s valid
// Efficiency: O(n)
void stats(const int *a, int len, struct statistics *s);