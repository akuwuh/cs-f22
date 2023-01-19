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
// Name:Isaac Nguyen
// login ID: i3nguyen
//////////////////////////////////////////////////////////////////////////////////////////

//seq-tools.c [IMPLEMENTATION]

#include <stdio.h>
#include "sequence.h"
#include "seq-tools.h"
#include <assert.h>
#include <stdlib.h>


struct Sequence *Sequence_build(int n) {
  struct Sequence *seq = Sequence_create();
  for (int i = 0; i < n; i++) {
      Sequence_insert_at(seq, i, i);
  }
  return seq;
}


void Sequence_map(int (*fp)(int), struct Sequence *seq) {
    assert(fp);
    assert(seq);
    
    int len = Sequence_length(seq);
    
    int item = 0;
    int val=0;
    for(int i = 0; i < len; i++) {
        item = Sequence_item_at(seq, i);
        val = fp(item);
        Sequence_remove_at(seq, i);
        Sequence_insert_at(seq, i, val);
    }
}


bool Sequence_equal(const struct Sequence *seq1, const struct Sequence *seq2) {
    assert(seq2);
    assert(seq1);
    
    int len1 = Sequence_length(seq1);
    int len2 = Sequence_length(seq2);
    
    if (len1 != len2) {
        return false;
    }
    
    for(int i = 0; i < len1; i++) {
         int item1 = Sequence_item_at(seq1, i);
         int item2 = Sequence_item_at(seq2, i);
         if (item1 == item2) {
             continue;
         } else {
             return false;
         }
    }
    
    return true;
}


void Sequence_add_sum(struct Sequence *seq) {
    assert(seq);
    int sum = 0;
    int len = Sequence_length(seq);
    
    
    for(int i = 0; i < len; i++) {
        int item = Sequence_item_at(seq, i);
        sum+=item;
        Sequence_remove_at(seq, i);
        Sequence_insert_at(seq, i, sum);
        
    }
    
    
    
}


void Sequence_avg_and_variance(const struct Sequence *seq, 
                               int *avg, int *var) {
    
    assert(seq);
    assert(avg);
    assert(var);
    int len = Sequence_length(seq);
    assert(len > 0);
    
    int sum = 0;
    
    for (int i = 0; i < len; i++) {
        int item = Sequence_item_at(seq, i);
        sum+= item;
    }
    
    *avg = sum/len;
    
    int var_sum = 0;
    
    for (int i = 0; i < len; i++) {
        int item = Sequence_item_at(seq, i);
        int num = (item - *avg);
        num*=num;
        var_sum+=num;
    }
    
    *var = var_sum/len;
}


void Sequence_filter(bool (*fp)(int), struct Sequence *seq) {
    assert(fp);
    assert(seq);
    
    int len = Sequence_length(seq);
    
    for(int i = 0; i < len; i++) {
        int item = Sequence_item_at(seq, i); 
        bool val = fp(item);
        if(val != true) {
            Sequence_remove_at(seq, i);
            len--;
            i--;
        }
    }
    

}


int Sequence_foldl(int (*fp)(int, int), int base, 
                   const struct Sequence *seq) {
    assert(fp);
    
    int len = Sequence_length(seq);
    
    if (len == 0) {
        return base;
    }
    
    int item = Sequence_item_at(seq, len-1);
    struct Sequence *new_seq = Sequence_create();
    for (int i = 0; i < len-1; i++) {
        Sequence_insert_at(new_seq, i, Sequence_item_at(seq, i));
    }
    
    return fp(item, Sequence_foldl(fp, base, new_seq));

    
}

struct Sequence *Sequence_collatz(int n) { 
    assert(n > 0);
    struct Sequence *seq = Sequence_create();
    
    int current = n;
    int counter = 0;
    Sequence_insert_at(seq, counter, current);
    counter++;
    while(1) {
        if (current == 1) {
            break;
        }
        
        if(current%2 == 0) {
            current = current/2;
            Sequence_insert_at(seq, counter, current);
            counter++;
            
        } else {
            current = (current *3) + 1;
            Sequence_insert_at(seq, counter, current);
            counter++;
            
        }
    }
    
    return seq;
  
    
  return Sequence_create();
}