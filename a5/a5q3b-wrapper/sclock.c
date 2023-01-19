// sclock.c [IMPLEMENTATION]

#include <assert.h>
#include <stdio.h>
#include "sclock.h"
#include "clock.h"

// === CORE FUNCTIONS =========================================================

// see sclock.h for documentation
struct sclock sclock_make_hm(int hours, int minutes) {
  // your implementation goes here
  assert(0 <= hours);
  assert(0 <= minutes);
  struct sclock clk = { .clk = clock_make_hm(hours, minutes) };
  return clk;
}

// see sclock.h for documentation
void sclock_add_hrs(struct sclock *clk, int hrs) {
  // your implementation goes here
  assert(0 <= hrs);
  assert(clk);
  clock_add_hrs(clk->clk, hrs);
}

// see sclock.h for documentation
void sclock_add_min(struct sclock *clk, int min) {
  // your implementation goes here
  assert(clk);
  assert(0 <= min);
  clock_add_min(clk->clk, min);
}

// see sclock.h for documentation
int sclock_get_hrs(const struct sclock *clk) {
  // your implementation goes here
  assert(clk);
  return clock_get_hrs(clk->clk);
}

// see sclock.h for documentation
int sclock_get_min(const struct sclock *clk) {
  // your implementation goes here
  assert(clk);
  return clock_get_min(clk->clk);
}

// see sclock.h for documentation
int sclock_get_min_total(const struct sclock *clk) {
  // your implementation goes here
  assert(clk);
  return clock_get_min_total(clk->clk);
}

// see sclock.h for documentation
void sclock_print_hm(const struct sclock *clk) {
  // your implementation goes here
  // use "Current time is %d:%02d.\n" as printf-format string.
  assert(clk);
  printf("Current time is %d:%02d.\n", sclock_get_hrs(clk), sclock_get_min(clk)); 
}

// === ADDITIONAL FUNCTIONS ===================================================
// add additional functions here

// see sclock.h for documenation
struct sclock sclock_make_hms(int hours, int minutes, int seconds) {
    assert(0 <= hours);
    assert(0 <= minutes);
    assert(0 <= seconds);
    struct sclock clk = { .clk = clock_make_hm(hours, minutes), .seconds = seconds};
    return clk;
}

// sclock_add_sec(clk, seconds) adds seconds to clk and enforces the
//   requirements for sclock.
// requires: seconds must be non-negative
// effects:  modifies clk
void sclock_add_sec(struct sclock *clk, int seconds) {
    assert(clk);
    assert(seconds >= 0);
    clk->seconds += seconds;
    sclock_add_min(clk, clk->seconds / 60);
    clk->seconds %= 60;
}

// sclock_get_sec(clk) retrieves the seconds on clk.
int sclock_get_sec(const struct sclock *clk) {
    assert(clk);
    return clk->seconds;
}

// sclock_get_sec_total(clk) retrieves the total seconds on clk.
int sclock_get_sec_total(const struct sclock *clk) {
    assert(clk);
    return (sclock_get_min_total(clk)*60) + clk->seconds;
}

// clock_print_hms(clk) prints the clk.
// effects: writes to console.
void sclock_print_hms(const struct sclock *clk) {
    assert(clk);
    printf("Current time is %d:%02d:%02d.\n", sclock_get_hrs(clk), sclock_get_min(clk), sclock_get_sec(clk));
}