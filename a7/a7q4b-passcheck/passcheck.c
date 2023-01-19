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

// passcheck.c [IMPLEMENTATION]

const int MIN_PASSWORD_LENGTH = 8;


#include "passcheck.h"
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>

bool is_valid_password(const char *s) {
    assert(s);

    int len = strlen(s);

    if (len < MIN_PASSWORD_LENGTH) {
        return false;
    }

    bool upper = false;
    bool lower = false;
    bool digit = false;
    bool special = false;
    
    for (int i = 0; i < len; i++) {
        char c = s[i];
        if (c >= 'A' && c <= 'Z') {
            upper = true;
        } else if (c >= 'a' && c <= 'z') {
            lower = true;
        } else if (c >= '0' && c <= '9') {
            digit = true;
        } else if (c == ' ' || c == ' ' || c == '\t' || c == ' ') {
            return false;
        } else {
            special = true;
        }
    }
    return upper && lower && digit && special;
}