Sequence I/O Command Guide:
==========================

SYNTAX:
------

<sequence id> - A character between 'a' and 'z', which specifies a Sequence

<number> - A single integer number

<list of numbers> - A space separated list of integer numbers

<fname> - A function name 
          added by one of: add_map_fn, add_filter_fn, add_foldl_fn
          (e.g., in test-seqtools.c)

COMMANDS:
--------

read <sequence id> <list of numbers> end
Resets the specified sequence to contain the list of numbers in the order they are listed.

print <sequence id>
Calls Sequence_print on the specified Sequence
[<number>] <list of numbers>

build <sequence id> <number>
Replaces the specified sequence with Sequence_build(n)

map <sequence id> <fname>
Calls Sequence_map on the specified Sequence using the specified function

equal <sequence id> <sequence id>
Prints true/false, the result of Sequence_equal on the specified Sequences

addsum <sequence id>
Calls Sequence_add_sum on the specified Sequence

avgvar <sequence id>
Prints the results from Sequence_avg_and_variance on the specified Sequence

collatz <sequence id> <number>
Replaces the specified sequence with Sequence_collatz(n)

filter <sequence id> <fname>
Calls Sequence_filter on the specified Sequence using the specified function

foldl <sequence id> <fname> <number>
Calls Sequence_foldl on the specified Sequence using the specified function 
  using the supplied function and initial value
