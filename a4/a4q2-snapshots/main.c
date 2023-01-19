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

// This code doesn't do anything special.
// We just wanted some fun names (identifiers)

#include "cs136.h"

struct arthur {
  int truth;
  int lies;
};

void mordred(struct arthur *a1, struct arthur *a2) {
  a1->truth *= 10;
  a2->truth += 30;
  a2->lies = a1->truth / 20;
  a1->lies = a2->lies - 4; 
  // Point B
}

void merlin(int *good, int *evil) {
  *good = 30;
  good = evil;
  *evil = *good / 10;
  // Point A
}

int main(void) {
  int good = 10;
  int evil = 20;
  merlin(&good, &evil);

  struct arthur a1 = {50, 20};
  struct arthur a2 = {30, 40};
  mordred(&a1, &a2);
  // Point C
}