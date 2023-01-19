// clock.c [IMPLEMENTATION]

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "clock.h"

struct clock *the_clock = NULL;

struct clock {
  int hours;
  int minutes;
};

// === CORE FUNCTIONS =========================================================

// see clock.h for documentation
struct clock *clock_make_hm(int hrs, int min) {
  assert(0 <= hrs && hrs <= 23);
  assert(0 <= min && min <= 59);
  if (the_clock != NULL) {
    clock_destroy();
  }
  the_clock = malloc(sizeof(struct clock));
  assert(the_clock);
  the_clock->hours = hrs;
  the_clock->minutes = min;
  return the_clock;
}

// see clock.h for documentation
void clock_destroy(void) {
  if (the_clock != NULL) {
    free(the_clock);
    the_clock = NULL;
  }
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