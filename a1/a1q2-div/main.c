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

int abs(int n){
   return n*((2*n+1)%2); 
}

int away_div(int num, int denom) {
  assert(denom != 0);

  
  if(denom < 0 && num < 0) {
      int n = num * (-1);
      int d = denom * (-1);
      int x = (n + (d - 1)) / d;
      return x;
  }
  
  if (num < 0 || denom < 0) {
      int n = abs(num);
      int d = abs(denom);
      int x = (n + (d - 1)) / d;
      return -1 * x;
  }
  
  
  int x = (num + (denom - 1)) / denom;
  return x;
  
  
}

int num_pizzas(int num_people, int slices_per_pizza, int slices_each) {
  assert(slices_per_pizza > 0);
  assert(num_people >= 0);
  assert(slices_each >= 0);
  
  int total_slices = num_people * slices_each;
  
  return away_div(total_slices, slices_per_pizza);
}

int plus_one_total(int p1, int n, int size) {
    

    if (n == 0) {
        return 0;
    } 
    
    int packets = away_div(p1, size);
    
    return packets + plus_one_total(p1, n - 1, size);
    
}

int necklace(int packet_size, int colours, int length, int beads_per_inch) {
  assert(packet_size > 0); 
  assert(colours > 0);
  
  int total_beads = beads_per_inch * length; //total beads
  
  int plus_one = total_beads%colours; //number of +1
  int per_colour_base = total_beads/colours; //base amount for each colour
  
  int base_amount = colours - plus_one;
  
  int base_num_packet = away_div(per_colour_base, packet_size) * base_amount;
  
  int total_packets = base_num_packet + plus_one_total(per_colour_base + 1, plus_one, packet_size);
  
  return total_packets;
  
  
  
  
  
  
  
  
}

int main(void) {
  assert(away_div(39, 10) == 4);
  assert(away_div(-39, 10) == -4);
  assert(away_div(39, -10) == -4);
  assert(away_div(-39, -10) == 4);
  assert(away_div(0, 10) == 0);
  assert(away_div(41, 10) == 5);
  
  assert(num_pizzas(39, 10, 1) == 4);
  assert(necklace(50, 4, 7, 10) == 4);
  assert(necklace(26, 3, 4, 20) == 5);
  // add more asserts below to test your code
}