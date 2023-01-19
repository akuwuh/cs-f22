// clock.c [IMPLEMENTATION]

#include <assert.h>
#include <stdio.h>
#include "clock.h"

// === CORE FUNCTIONS =========================================================

// see clock.h for documentation
struct clock clock_make_hm(int hours, int minutes) {
  assert(0 <= hours && hours <= 23);
  assert(0 <= minutes && minutes <= 59);
  struct clock clk = { .hours = hours, .minutes = minutes };
  return clk;
}

// see clock.h for documentation
void clock_add_hrs(struct clock *clk, int hrs) {
  assert(clk);
  assert(hrs >= 0);
  clk->hours += hrs;
  clk->hours %= 24;
}

// see clock.h for documentation
void clock_add_min(struct clock *clk, int min) {
  assert(clk);
  assert(min >= 0);
  clk->minutes += min;
  clock_add_hrs(clk, clk->minutes / 60);
  clk->minutes %= 60;
}

// see clock.h for documentation
int clock_get_hrs(const struct clock *clk) {
  assert(clk);
  return clk->hours;
}

// see clock.h for documentation
int clock_get_min(const struct clock *clk) {
  assert(clk);
  return clk->minutes;
}

// see clock.h for documentation
int clock_get_min_total(const struct clock *clk) {
  assert(clk);
  return clock_get_hrs(clk) * 60 + clock_get_min(clk);
}

// see clock.h for documentation
void clock_print_hm(const struct clock *clk) {
  assert(clk);
  printf("Current time is %d:%02d.\n", clock_get_hrs(clk), clock_get_min(clk));
}

// Add extended functions

// see clock.h for documentation
struct clock clock_make_hms(int hours, int minutes, int seconds) {
  assert(0 <= hours && hours <= 23);
  assert(0 <= minutes && minutes <= 59);
  assert(0 <= seconds && seconds <= 59);
  struct clock clk = { .hours = hours, .minutes = minutes , .seconds = seconds};
  return clk;
}

// see clock.h for documentation
int clock_get_sec(const struct clock *clk) {
  assert(clk);
  return clk->seconds;
}

// see clock.h for documentation
int clock_get_sec_total(const struct clock *clk) {
  assert(clk);
  return clock_get_hrs(clk) * 360 + clock_get_min(clk) * 60 + clock_get_sec(clk);
}

// see clock.h for documentation
void clock_add_sec(struct clock *clk, int sec) {
  assert(clk);
  assert(sec >= 0);
  clk->seconds += sec;
  clock_add_min(clk, clk->seconds / 60);
  clk->seconds %= 60;
}

void clock_print_hms(const struct clock *clk) {
  assert(clk);
  //printf("hi");
  printf("Current time is %d:%02d:%02d.\n", clock_get_hrs(clk), clock_get_min(clk), clock_get_sec(clk));
}
