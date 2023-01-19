// clock.h [INTERFACE]
// A module that models a 24-hour clock with hours and minutes

// clock represents a clock
struct clock;

// clock_make_hm(hours, minutes) creates a new clock with set hours and minutes.
// requires: hours must be between 0 and 23 (inclusive)
//           minutes must be between 0 and 59 (inclusive)
struct clock *clock_make_hm(int hours, int minutes);

// clock_destroy(clk) releases all resources used by the clock-module.
void clock_destroy(void);

// clock_add_hrs(clk, hours) adds hours to clk and enforces the requirements for
//   clock.
// requires: hours must be non-negative
// effects:  modifies clk
void clock_add_hrs(struct clock *clk, int hours);

// clock_add_min(clk, minutes) adds minutes to clk and enforces the requirements
//   for clock.
// requires: minutes must be non-negative
// effects:  modifies clk
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