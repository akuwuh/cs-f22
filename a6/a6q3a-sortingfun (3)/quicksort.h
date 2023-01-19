// quicksort.h [IMPLEMENTATION]
// A module that performs quicksort on an array

#include <stdbool.h>

// quick_sort(arr, arr_len, pred) performes quicksort on arr using pred as
//   as sorting function.
// requires: arr_len must be positive
// effects:  might modify arr
// Efficiency: O(nlog(n))
void quick_sort(int *arr, int arr_len, bool(*pred)(int, int));
