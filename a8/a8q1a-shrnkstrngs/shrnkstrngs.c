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

// shrnkstrngs.c [IMPLEMENTATION]

#include "shrnkstrngs.h"
#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>


// see shrnkstrng.h for documentation
// time: O(n)
void remove_whitespace(char *s) {
    assert(s);
    int i =0;
    int j = 0;

    while(s[i] != '\0') {
        if (s[i] != ' ' && s[i] != '\t' && s[i] != '\n') {
            s[j] = s[i];
            j++;

        }
        i++;
    }

    s[j] = '\0';
}


// see shrnkstrng.h for documentation
// time: O(n)
void remove_char(char *s, char c) {
    int i =0;
    int j = 0;

    while(s[i] != '\0') {
        if (s[i] != c) {
            s[j] = s[i];
            j++;
        }
        i++;
    }
    s[j] = '\0';
}

// see shrnkstrng.h for documentation
// time: O(n^2 * k) where k is the amount of character shifts

void remove_chars(char *s, const char *remove) {
    int i = 0;
    while (s[i] != '\0') {
        int j = 0;
        bool removed = false;
        while (remove[j] != '\0') {
            if (s[i] == remove[j]) {
                int k = i;
                while (s[k] != '\0') {
                    s[k] = s[k + 1];
                    k++;
                }
                removed = true;
            }
            if (removed == true) {
                break;
            }
            j++;
        }
        if(removed == false) {
            i++;
        }
    }
}