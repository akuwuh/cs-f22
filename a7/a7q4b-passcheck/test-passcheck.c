// A simple test program for the passcheck module

#include <assert.h>
#include "passcheck.h"

int main(void){
  assert(is_valid_password("Tru$tNo1"));
  assert(!is_valid_password("password123"));
}