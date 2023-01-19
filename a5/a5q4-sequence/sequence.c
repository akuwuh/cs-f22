// sequence.c [IMPLEMENTATION]

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "sequence.h"

#define MAX_SIZE 10000
//arbitrarily choosing this to be the max seq size

struct Sequence {
	int arr[MAX_SIZE];
	int length;
};

//hacking a max limit of 1000 sequences
#define MAX_SEQUENCES 1000
static struct Sequence *sequences[MAX_SEQUENCES];
static int sequences_created = 0;

void cleanup(){
	for(int i =0; i < sequences_created; ++i){
		free(sequences[i]);
	}
}

//Creates and returns a pointer to a new Sequence
struct Sequence *Sequence_create(void){
	if(sequences_created == MAX_SEQUENCES){
		printf("Unexpected error: only %d sequences can be created for this assignment", MAX_SEQUENCES);
		exit(1);
	}
	struct Sequence * newSeq = malloc(sizeof(struct Sequence));
	newSeq->length = 0;
	sequences[sequences_created] = newSeq;
	++sequences_created;
	if(sequences_created == 1) atexit(cleanup);
	
	return newSeq;
}

// See interface for documentation
int Sequence_length(const struct Sequence *seq){
	assert(seq);
	return seq->length;
}

//Clear the sequence
void Sequence_clear(struct Sequence *seq){
	assert(seq);
	seq->length=0;
}

// See interface for documentation
int Sequence_item_at(const struct Sequence *seq, int pos){
	assert(seq);
	assert(pos >= 0);
	assert(pos < Sequence_length(seq));
	return seq->arr[pos];
}

// See interface for documentation
void Sequence_insert_at(struct Sequence *seq, int pos, int val){
	assert(seq);
	assert(pos >= 0);
	assert(pos <= Sequence_length(seq));

	//if adding the item will reach MAX_SIZE
	if (seq->length + 1 == MAX_SIZE){
		printf("Unexpected error: maximum sequence length for this assignment is %d items", MAX_SIZE);
		exit(1);
	}
	for(int i = seq->length; i > pos; --i){
		seq->arr[i] = seq->arr[i-1];
	}
	seq->arr[pos] = val;
	++seq->length;
}

// See interface for documentation
int Sequence_remove_at(struct Sequence *seq, int pos){
	assert(seq);
	assert(pos >= 0);
	assert(pos < Sequence_length(seq));
	const int toRet = seq->arr[pos];
	for(int i = pos; i < seq->length - 1 ; ++i){
		seq->arr[i] = seq->arr[i+1];
	}
	--seq->length;
	return toRet;
}

// See interface for documentation
void Sequence_print(const struct Sequence *seq){
	assert(seq);
  if (!seq->length) {
    printf("[empty]\n");
    return;
  }
	printf("[%d]", seq->length);
	for(int i=0 ; i < seq->length; i++){
		printf(" %d",Sequence_item_at(seq,i));
	}
	printf("\n");
}
