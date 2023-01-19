// This program is a simple test client for the strnkstngs module

#include <assert.h>
#include <string.h>
#include "cs136-trace.h"
#include "shrnkstrngs.h"

int main(void){
  char test[] = "rick and morty";
  remove_whitespace(test);
  assert(!strcmp(test, "rickandmorty"));
  remove_char(test, 'r');
  assert(!strcmp(test, "ickandmoty"));
  remove_chars(test, "dikmnoy");
  assert(!strcmp(test, "cat"));
}