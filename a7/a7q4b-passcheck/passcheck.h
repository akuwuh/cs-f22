// passcheck.h [INTERFACE]
// A module to determine if a string is a valid password

#include <stdbool.h>

extern const int MIN_PASSWORD_LENGTH;

// is_valid_password(s) determines if s is a valid password
//   with the following criteria:
//   contains at leat MIN_PASSWORD_LENGTH characters
//   does not contain any whitespace characters (space or newline)
//   contain at least one of each of the following:
//     upper case letter (e.g., 'T')
//     lower case letter (e.g., 'r')
//     digit (e.g., '7')
//     special character (e.g., '$')
// requires: s is a null terminated string [not asserted]
// time: O(n) where n is the length of the string
bool is_valid_password(const char *s);