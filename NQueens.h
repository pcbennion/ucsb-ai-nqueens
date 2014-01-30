/*
 * NQueens.h
 *    Peter Bennion
 */

#ifndef NQUEENS_H_
#define NQUEENS_H_

#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include <time.h>

static void clearBoard(int board[], int n)
{
  int squ = n*n;
  for(int i = 0; i<squ; i++)
    board[i] = 0;
}

// debug function. prints the threat levels of all squares on the board
static void printBoard(int board[], int n)
{
  int i, j;
  for(i = 0; i<n; i++)
    {
      for(j = 0; j<n; j++)
	{
	  std::cout<<board[j+i*n]<<" ";
	}
      std::cout<<std::endl;
    }
}

class Queen {
 public:
  Queen(int coord);
  void attack(int n, int board[]);
  int findMove(int n, int board[]);
  int getCoord();
  std::string print(int n);

 protected:

 private:
  int coord;
};

#endif /* NQUEENS_H_ */
