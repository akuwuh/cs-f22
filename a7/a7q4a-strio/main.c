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

#include <stdio.h>
#include <string.h>

int main(void) {

    char str[100] = "";

    char f[100] = "";
    char l[100] = "";

    int counter = 0;

    while (scanf("%s", str) == 1) {

        if (counter == 0) {
            strcpy(f, str);
            strcpy(l, str);
        }

        if (strcmp(str, f) < 0) {
            strcpy(f, str);
        }

        if (strcmp(str, l) > 0) {
            strcpy(l, str);
        }
        counter++;
    }

    if (counter == 0) {
        printf("NO STRINGS\n");
    } else {
        printf("%s %s\n", f, l);
    }
    return 0;
}
