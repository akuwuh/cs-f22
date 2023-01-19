/////////////////////////////////////////////////////////////////////////////////////////
// INTEGRITY STATEMENT (v4)
//
// By signing your name and ID below you are stating that you have agreed
// to the online academic integrity statement posted on edX:
// (Course > Assignments > Assignment Information & Policies > Academic Integrity Policy)
/////////////////////////////////////////////////////////////////////////////////////////
// I received help from and/or collaborated with:

// No One
//
// Name: Isaac Nguyen
// login ID: i3nguyen
//////////////////////////////////////////////////////////////////////////////////////////

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include "clock.h"
#include "sclock.h"
#include "cs136-trace.h"

int main(void) {

  // register all valid OLD commands
  const int CMD_MAKE_HM = lookup_symbol("make_hm");
  const int CMD_ADD_HRS = lookup_symbol("add_hrs");
  const int CMD_ADD_MIN = lookup_symbol("add_min");
  const int CMD_GET_HRS = lookup_symbol("get_hrs");
  const int CMD_GET_MIN = lookup_symbol("get_min");
  const int CMD_GET_MIN_TOTAL = lookup_symbol("get_min_total");
  const int CMD_PRINT_HM = lookup_symbol("print_hm");
  // register all valid NEW commands
  // uncomment as you add new commands
  const int CMD_MAKE_HMS = lookup_symbol("make_hms");
  const int CMD_ADD_SEC = lookup_symbol("add_sec");
  const int CMD_GET_SEC = lookup_symbol("get_sec");
  const int CMD_GET_SEC_TOTAL = lookup_symbol("get_sec_total");
  const int CMD_PRINT_HMS = lookup_symbol("print_hms");

  // variables for the one clock and all inputs
  
  //struct clock *clk = NULL; // REPLACE with the below code
  struct sclock clk = { NULL, 0 };
  int cmd = INT_MIN;
  int hrs = INT_MIN;
  int min = INT_MIN;
  int sec = INT_MIN;

  while ((cmd = read_symbol()) != INVALID_SYMBOL) {
    if (cmd == CMD_MAKE_HM) {                   // make new clock
      if (scanf("%d%d", &hrs, &min) != 2) {
        printf("ERROR: cannot read values for hours or minutes\n");
        break;
      }
      //clk = clock_make_hm(hrs, min);            // REPLACE with the below code
       clk = sclock_make_hm(hrs, min);
    } else if (cmd == CMD_ADD_HRS) {            // add hours
      if (scanf("%d", &hrs) != 1) {
        printf("ERROR: cannot read values for hours\n");
        break;
      }
      //clock_add_hrs(clk, hrs);                  // REPLACE with the below code
       sclock_add_hrs(&clk, hrs);
    } else if (cmd == CMD_ADD_MIN) {            // add minutes
      if (scanf("%d", &min) != 1) {
        printf("ERROR: cannot read values for minutes\n");
        break;
      }
      //clock_add_min(clk, min);                  // REPLACE with the below code
       sclock_add_min(&clk, min);
    } else if (cmd == CMD_GET_HRS) {            // get hours
      /*printf("Info: clock has %d hours\n",
             clock_get_hrs(clk)); */              // REPLACE with the below code
       printf("Info: clock has %d hours\n",
             sclock_get_hrs(&clk)); 
    } else if (cmd == CMD_GET_MIN) {            // get minutes
      /*printf("Info: clock has %d minutes\n",
             clock_get_min(clk));*/ // REPLACE with the below code
      printf("Info: clock has %d minutes\n",
             sclock_get_min(&clk)); 
    } else if (cmd == CMD_GET_MIN_TOTAL) {      // get total minutes
      /*printf("Info: clock has %d total minutes\n",
             clock_get_min_total(clk));  */       // REPLACE with the below code
       printf("Info: clock has %d total minutes\n",
             sclock_get_min_total(&clk));
    } else if (cmd == CMD_PRINT_HM) {           // print clock
      sclock_print_hm(&clk);
    // Uncomment and add to the below code as you implement the new functions:
    }  else if (cmd == CMD_MAKE_HMS) {          // make new clock with seconds
      // printf format string: "ERROR: cannot read values for hours, minutes, or seconds\n"
      
      if (scanf("%d%d%d", &hrs, &min, &sec) != 3) {
        printf("ERROR: cannot read values for hours, minutes, or seconds\n");
        break;
      }
      
       clk = sclock_make_hms(hrs, min, sec);
      
    } else if (cmd == CMD_ADD_SEC) {            // add seconds
      // printf format string: "ERROR: cannot read values for seconds\n"
      if (scanf("%d", &sec) != 1) {
        printf("ERROR: cannot read values for seconds\n");
        break;
      }
       sclock_add_sec(&clk, sec);
    } else if (cmd == CMD_GET_SEC) {            // get seconds
      // printf format string: "Info: clock has %d seconds\n"
      printf("Info: clock has %d seconds\n",
             sclock_get_sec(&clk)); 
    } else if (cmd == CMD_GET_SEC_TOTAL) {      // get total seconds
      // printf format string: "Info: clock has %d total seconds\n"
      printf("Info: clock has %d total seconds\n",
             sclock_get_sec_total(&clk));
    } else if (cmd == CMD_PRINT_HMS) { 
        // print clock with seconds*/
        sclock_print_hms(&clk);
    } else {                                    // ERROR: unknown command
      printf("ERROR: unknown command: ");
      print_symbol(cmd);
      break;
    }
  }

  clock_destroy();
}