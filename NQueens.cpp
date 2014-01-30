/*
 * NQueens.cpp
 *     Peter Bennion
 */

#include "NQueens.h"

using namespace std;

/*
 * CLASS QUEEN
 * ===========
 */
Queen::Queen(int coord)
{
  this->coord = coord;
}

int Queen::findMove(int n, int board[])
{
  int min = board[coord];
  if(min == 0)
    return 0;

  // find minimum threat level among all squares
  int current;
  int adj = (coord/n) * n;
  //cout<<"adj = "<<adj<<endl;
  //cout<<"min = "<<min<<endl;
  vector<int> elems;
  elems.push_back(coord);
  for(int i=adj; i<adj+n; i++)
    {
      current = (int)board[i];
      if(current < min)
	{
	  min = current;
	  elems.clear();
	  elems.push_back(i);
	}
      else if(current==min && i!=coord)
	{
	  elems.push_back(i);
	}
    }
  //cout<<"min = "<<min<<endl;

  // if the current square is a min, don't move
  if(min == board[coord])
    return 0;

  // if the minimum threat level is unique, move to it
  if(elems.size() == 1)
    {
      coord = elems[0];
      return 1;
    }
  // if there is no unique minimum, move to one at random
  int rng = rand() % elems.size();
  coord = elems[rng];
  return 1;
}

void Queen::attack(int n, int board[])
{
  int i;
  int squ = n*n;
  //cout<<"this coord = "<<coord<<endl;
  // Diagonals
  int col = coord%n;
  int inc = -coord/n;
  int left, right;
  for(i=0; i<n; i++)
    {
      //cout<<"\tinc="<<inc<<endl;
      if(inc!=0)
	{
	  left = col+inc;
	  if(left>=0 && left<n)
	    {
	      board[left+(i*n)]++;
	      //cout<<"inc coord "<<left+(i*n)<<", threat: "<<board[left+(i*n)]<<endl;
	    }
	  right = col-inc;
	  if(right>=0 && right<n)
	    {
	      board[right+(i*n)]++;
	      //cout<<"inc coord "<<right+(i*n)<<", threat: "<<board[right+(i*n)]<<endl;
	    }
	}
      inc++;
    }
  // Y direction
  for(i=coord%n; i<squ; i+=n)
    {
      if(i!=coord)
	{
	  board[i]++;
	  //cout<<"inc coord "<<i<<", threat: "<<board[i]<<endl;
	}
    }
  // No need to threaten the X direction -- no other queens can be there
}

string Queen::print(int n)
{
  stringstream ss;
  ss<<coord%n + 1<<" "<<coord/n + 1<<endl;
  return ss.str();
}

int Queen::getCoord(){return coord;}
