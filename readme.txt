Peter Bennion
CS165A: Artificial Intelligence
Project 1: The N-Queens Puzzle

Code is designed to be run on the computers at UCSB's
CSIL tech lab. The program only uses C's std library,
so it should still be able to compile on non-Linux
machines.

This assignment was to implement an algorithm to
automatically solve the N-Queens problem in chess:
given an N by N chessboard and N queen pieces, it finds
a boardstate where no two queens threaten each other.

The program uses a greedy algorithm, and as such it
cannot find ALL successful boardstates for a value of
N, it will only return the first one it devises. It
takes a boardstate as an input and it outputs the
closest successful boardstate and the number of moves
it takes to achieve that state.