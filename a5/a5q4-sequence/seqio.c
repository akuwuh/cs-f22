// seqio.c [IMPLEMENTATION]

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "sequence.h"
#include "seq-tools.h"

#define MAX_CMD_LEN 1024
#define MAX_FUNC 1024
#define MAX_SEQ 26

static char cmd[MAX_CMD_LEN];
static char num[MAX_CMD_LEN];
static char readseq[MAX_CMD_LEN];

static char fname_map[MAX_FUNC][MAX_CMD_LEN];
static char fname_filter[MAX_FUNC][MAX_CMD_LEN];
static char fname_foldl[MAX_FUNC][MAX_CMD_LEN];

static int count_map;
static int count_filter;
static int count_foldl;

static int (*f_map[MAX_FUNC]) (int);
static bool (*f_filter[MAX_FUNC]) (int);
static int (*f_foldl[MAX_FUNC]) (int, int);

struct Sequence *seqs[MAX_SEQ];

int get_seq_id(void) {
  int retval = scanf("%s", readseq);
  if (retval != 1) {
    printf("Error: Could not read in sequence ID (e.g., a)\n");
    exit(0);
  }
  if ((strlen(readseq) == 1) && (readseq[0] >= 'a') && (readseq[0] < 'a' + MAX_SEQ)) {
    return readseq[0] - 'a';
  }
  printf("Error: Invalid sequence: [%s]\n", readseq);
  exit(0);
  return 0;
}


static struct Sequence *get_seq(void) {
  return seqs[get_seq_id()];
}

static int get_int(void) {
  int n;
  int retval = scanf("%d", &n);
  if (retval != 1) {
    printf("Error reading number\n");
    exit(0);
  }
  return n;
}

void add_map_fn(const char *name, int (*f)(int)) {
  if (count_map == MAX_FUNC) {
    printf("error: too many functions!\n");
    exit(0);
  }
  strcpy(fname_map[count_map], name);
  f_map[count_map] = f;
  ++count_map;
}

void add_filter_fn(const char *name, bool (*f)(int)) {
  if (count_filter == MAX_FUNC) {
    printf("error: too many functions!\n");
    exit(0);
  }
  strcpy(fname_filter[count_filter], name);
  f_filter[count_filter] = f;
  ++count_filter;
}

void add_foldl_fn(const char *name, int (*f)(int, int)) {
  if (count_foldl == MAX_FUNC) {
    printf("error: too many functions!\n");
    exit(0);
  }
  strcpy(fname_foldl[count_foldl], name);
  f_foldl[count_foldl] = f;
  ++count_foldl;
}

int getfunc(char names[MAX_FUNC][MAX_CMD_LEN], int count) {
  int retval = scanf("%s", num);
  if (retval != 1) {
    printf("error reading function name\n");
    exit(0);
  }
  for (int i=0; i < count; ++i) {
    if (strcmp(names[i], num) == 0) {
      return i;
    }
  }
  printf("invalid function: [%s]\n", num);
  exit(0);
  return -1;
}


void sequence_io_test(void) {
  struct Sequence *s;
  struct Sequence *s2;
  
  for (int i=0; i < MAX_SEQ; ++i) {
    seqs[i] = Sequence_create();
  }
 
  while (1) {
    int retval = scanf("%s", cmd);
    if (retval != 1) {
      return;
    }
   
    if (strcmp(cmd, "quit") == 0) return;
    
    if (strcmp(cmd, "read") == 0) {
      s = get_seq();
      Sequence_clear(s);
      while (1) {
        retval = scanf("%s", num);
        if (retval != 1) {
          printf("Error during read\n");
          exit(0);
        }
        if (strcmp(num, "end") == 0) break;
        int readnum;
        retval = sscanf(num, "%d", &readnum);
        if (retval != 1) {
          printf("Error during read [%s]\n", num);
          exit(0);
        }
        Sequence_insert_at(s, Sequence_length(s), readnum);
      }
    } else if (strcmp(cmd, "print") == 0) {
      s = get_seq();
      Sequence_print(s);
    } else if (strcmp(cmd, "equal") == 0) {
      s = get_seq();
      s2 = get_seq();
      if (Sequence_equal(s, s2)) {
        printf("true\n");
      } else {
        printf("false\n");        
      }
    } else if (strcmp(cmd, "addsum") == 0) {
      s = get_seq();
      Sequence_add_sum(s);
    } else if (strcmp(cmd, "avgvar") == 0) {
      int avg, var;
      s = get_seq();
      Sequence_avg_and_variance(s, &avg, &var);
      printf("average: %d, variance: %d\n", avg, var);
    } else if (strcmp(cmd, "map") == 0) {
      s = get_seq();
      Sequence_map(f_map[getfunc(fname_map, count_map)], s);
    } else if (strcmp(cmd, "filter") == 0) {
      s = get_seq();
      Sequence_filter(f_filter[getfunc(fname_filter, count_filter)], s);
    } else if (strcmp(cmd, "foldl") == 0) {
      s = get_seq();
      int func_id = getfunc(fname_foldl, count_foldl);
      int base = get_int();
      printf("%d\n", Sequence_foldl(f_foldl[func_id], base, s));
    } else if (strcmp(cmd, "build") == 0) {
      int id = get_seq_id();
      int n = get_int();
      seqs[id] = Sequence_build(n);
    } else if (strcmp(cmd, "collatz") == 0) {
      int id = get_seq_id();
      int n = get_int();
      seqs[id] = Sequence_collatz(n);
    } else {
      printf("Invalid command [%s]\n", cmd);
      exit(0);
    }
  }
}
