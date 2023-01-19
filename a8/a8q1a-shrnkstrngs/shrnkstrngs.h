// strnkstrngs.h [INTERFACE]
// A module that shrinks strings by removing particular characters 
//   or whitespace

// remove_whitespace(s) removes all white space characters from s
// effects: modifies s
void remove_whitespace(char *s);

// remove_char(s, c) removes all occurrences of c from s
// effects: modifies s
void remove_char(char *s, char c);

// remove_chars(s, remove) removes all occurrences of any character appearing
//   in remove from s
// effects: modifies s
void remove_chars(char *s, const char *remove);
