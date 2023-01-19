// clock.h [INTERFACE]

// clock represents a 24-hour clock with hours and minutes
struct clock {
  int hours;   // hours must be between 0 and 23 (inclusive)
  int minutes; // minutes must be between 0 and 59 (inclusive)
  int seconds; // seconds must be between 0 and 59 (inclusive)
};

// clock_make_hm(hours, minutes) creates a new clock with set hours and minutes.
// requires: hours must be between 0 and 23 (inclusive)
//           minutes must be between 0 and 59 (inclusive)
struct clock clock_make_hm(int hours, int minutes);

// clock_add_hrs(clk, hours) adds hours to clk and enforces the requirements for
//   clock.
void clock_add_hrs(struct clock *clk, int hours);

// clock_add_min(clk, minutes) adds minutes to clk and enforces the requirements
//   for clock.
void clock_add_min(struct clock *clk, int minutes);

// clock_get_hrs(clk) retrieves the hours on clk.
int clock_get_hrs(const struct clock *clk);

// clock_get_min(clk) retrieves the minutes on clk.
int clock_get_min(const struct clock *clk);

// clock_get_min_total(clk) retrieves the total minutes on clk.
int clock_get_min_total(const struct clock *clk);

// clock_print_hm(clk) prints the clk.
// effects: writes to console.
void clock_print_hm(const struct clock *clk);

// Extended functions:

// clock_make_hms(hours, minutes, seconds) creates a new clock with set hours,
//   minutes, and seconds.
// requires: hours must be between 0 and 23 (inclusive)
//           minutes must be between 0 and 59 (inclusive)
//           seconds must be between 0 and 59 (inclusive)
struct clock clock_make_hms(int hours, int minutes, int seconds);

// clock_add_sec(clk, seconds) adds seconds to clk and enforces the requirements
//   for clock.
// requires: seconds must be non-negative
// effects:  modifies clk
void clock_add_sec(struct clock *clk, int seconds);

// clock_get_sec(clk) retrieves the seconds on clk.
int clock_get_sec(const struct clock *clk);

// clock_get_sec_total(clk) retrieves the total seconds on clk.
int clock_get_sec_total(const struct clock *clk);

// clock_print_hms(clk) prints the clk.
// effects: writes to console.
void clock_print_hms(const struct clock *clk);