/////////////////////////////////////////////////////////////////////////////////////////
// INTEGRITY STATEMENT (v4)
//
// By signing your name and ID below you are stating that you have agreed
// to the online academic integrity statement posted on edX:
// (Course > Assignments > Assignment Information & Policies > Academic Integrity Policy)
/////////////////////////////////////////////////////////////////////////////////////////
// I received help from and/or collaborated with:

// No one
//
// Name: Isaac Nguyen
// login ID: i3nguyen
//////////////////////////////////////////////////////////////////////////////////////////

#include "cs136.h"

void print_average_sofar(int counter, int sum) {
    int n = read_int();
    int average_sofar = 0;
    if (n == READ_INT_FAIL) {
        return;
    } else {
        sum += n;
        ++counter;
        average_sofar = sum/counter;
        printf("%d\n", average_sofar);
        
        print_average_sofar(counter, sum);
    }
}

int main(void) {
    print_average_sofar(0,0);
}