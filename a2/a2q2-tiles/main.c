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

#include "cs136.h"

int min_tiles(int w_tile, int h_tile, int w_room, int h_room) {
    assert(w_tile > 0);
    assert(h_tile > 0);
    assert(w_room > 0);
    assert(h_room > 0);
    
    // case 1: square tiles
    int height_amount = 0;
    int width_amount = 0;
    
    if (w_tile == h_tile) {
        height_amount = (h_room + (h_tile - 1)) / h_tile; // round up
        width_amount = (w_room + (w_tile - 1)) / w_tile;
        
        return  width_amount * height_amount;
    }
    
    //case 2: non-square tiles
    
    // w_room with w_tile, h_room w h_tile
    
    int height_amount1 = (h_room + (h_tile - 1)) / h_tile; // round up
    int width_amount1 = (w_room + (w_tile - 1)) / w_tile; 
    
    int total1 = height_amount1 * width_amount1;
    
    //h_room with w_tile, w_room with h_tile
    int height_amount2 = (h_room + (w_tile - 1)) / w_tile; // round up
    int width_amount2 = (w_room + (h_tile - 1)) / h_tile;
    
    int total2 = height_amount2 * width_amount2;
    
    if(total1 > total2) {
        return total2;
    }  else {
        return total1;
    }
}

void tile_test(int counter, int w_tile, int h_tile, int w_room, int h_room) {
    int n = read_int();
    
    if(n == READ_INT_FAIL) {
        return;
    }
    
    if(counter == 0) {
        tile_test(counter+1, n, 0, 0, 0);
    }
    if(counter == 1) {
        tile_test(counter+1, w_tile, n, 0, 0);
    }
    if(counter == 2) {
        tile_test(counter+1, w_tile, h_tile, n, 0);
    }
    if(counter == 3) {
        printf("%d\n", min_tiles(w_tile, h_tile, w_room, n));
        tile_test(0, 0, 0, 0, 0);
    }
    
}

int main(void) {
    tile_test(0, 0, 0, 0, 0);
}