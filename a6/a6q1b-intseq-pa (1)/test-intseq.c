// A test program for the intseq module

#include <assert.h>
#include <stdbool.h>
#include "intseq.h"

// fequals(a, b) determines if two floats a and b within 0.00001 of one another
int fequals(float a, float b) {
   return (-0.00001 <= (a-b)) && ((a-b) <= 0.00001);
}

int main(){
   int a[] = {1, 2, 3};
   assert(number_sum(a, 3) == 6);
   assert(max_number(a,3) == 3);
   assert(min_number(a,3) == 1);
   assert(minmax_dist(a,3) == 2);
   assert(fequals(seq_avg(a,3), 2.0));
   assert(seq_has_duplicates(a,3) == false);
   assert(seq_most_occurrences(a,3) == 1);
}
