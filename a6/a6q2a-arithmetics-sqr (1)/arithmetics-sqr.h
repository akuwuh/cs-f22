// arithmetics-sqr.h [INTERFACE]
// This module performs some basic statistics on an array

// mean(a, len) computes the mean of the array elements in a
// Requires: a valid, len > 0
// Efficiency: O(n)
double mean(const int a[], int len);

// var(a, len) computes the variance of the array elements in a
// Requires: a valid, len > 0
// Efficiency: O(n)
double var(const int a[], int len);