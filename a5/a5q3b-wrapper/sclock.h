// sclock.h [INTERFACE]
// A module that models a 24-hour clock with hours and minutes

#include "clock.h"

struct sclock {
  struct clock *clk;
  int seconds;
};

// sclock_make_hm(hours, minutes) creates a new sclock with set hours and
//   minutes.
// requires: hours must be between 0 and 23 (inclusive)
//           minutes must be between 0 and 59 (inclusive)
struct sclock sclock_make_hm(int hours, int minutes);

// sclock_add_hrs(clk, hours) adds hours to clk and enforces the requirements
//   for sclock.
// requires: hours must be non-negative
// effects:  modifies clk
void sclock_add_hrs(struct sclock *clk, int hours);

// sclock_add_min(clk, minutes) adds minutes to clk and enforces the
//   requirements for sclock.
// requires: minutes must be non-negative
// effects:  modifies clk
void sclock_add_min(struct sclock *clk, int minutes);

// sclock_get_hrs(clk) retrieves the hours on clk.
int sclock_get_hrs(const struct sclock *clk);

// sclock_get_min(clk) retrieves the minutes on clk.
int sclock_get_min(const struct sclock *clk);

// sclock_get_min_total(clk) retrieves the total minutes on clk.
int sclock_get_min_total(const struct sclock *clk);

// sclock_print_hm(clk) prints the clk.
// effects: writes to console.
void sclock_print_hm(const struct sclock *clk);

// sclock_make_hm(hours, minutes, seconds) creates a new sclock with set hours,
//   minutes, and seconds.
// requires: hours must be between 0 and 23 (inclusive)
//           minutes must be between 0 and 59 (inclusive)
//           seconds must be between 0 and 59 (inclusive)
struct sclock sclock_make_hms(int hours, int minutes, int seconds);

// sclock_add_sec(clk, seconds) adds seconds to clk and enforces the
//   requirements for sclock.
// requires: seconds must be non-negative
// effects:  modifies clk
void sclock_add_sec(struct sclock *clk, int seconds);

// sclock_get_sec(clk) retrieves the seconds on clk.
int sclock_get_sec(const struct sclock *clk);

// sclock_get_sec_total(clk) retrieves the total seconds on clk.
int sclock_get_sec_total(const struct sclock *clk);

// clock_print_hms(clk) prints the clk.
// effects: writes to console.
void sclock_print_hms(const struct sclock *clk);
