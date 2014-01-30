/*
 * main.cpp
 *   Peter Bennion
 */

#include "NQueens.h"

using namespace std;

int main()
{
  clock_t tStart = clock();
  //read input and initialize board
  int n, numMoves;
  cin>>n;
  cin>>numMoves;
  int board[n*n];
  clearBoard(board, n);
  Queen* queens[n];
  int i, j, x = -1, y = -1;
  i=0;
  string s;
  while(!cin.eof() && i<n)
    {
      getline(cin, s);
      istringstream iss(s);
      while(iss)
	{
	  iss>>x>>y;
	}
      if(x>0 && y>0)
	{
	  queens[i] = new Queen((x-1)+((y-1)*n));
	  queens[i]->attack(n, board);
	  i++;
	}
    }

  //printBoard(board, n);
  //cout<<endl;

  int conflicts = 0;
  for(i=0; i<n; i++)
    {
      if(board[queens[i]->getCoord()]>0)
	conflicts++;
    }

  // while there are still moves left, attempt to solve puzzle
  int max = 100000;
  int current, threat, move;
  vector<int> indexes;
  int counter = 0;
  while(numMoves>0 && conflicts>0)
    {
      // find the most threatened queen
      indexes.clear();
      current = 0, threat = 0;
      for(i=0; i<n; i++)
	{
	  threat = board[queens[i]->getCoord()];
	  //cout<<"threat at index "<<i<<" = "<<threat<<endl;
	  if(threat>current && threat<max)
	    {
	      current = threat;
	      indexes.clear();
	      indexes.push_back(i);
	    } else if(threat == current)
	    indexes.push_back(i);
	}
      //cout<<"priority = "<<current<<endl;
      //attempt to move that queen
      //if successful, update threats and conflicts
      move = 0, i = 0;
      while(move<1 && i<indexes.size())
	{
	  //cout<<"checking index "<<indexes[i]<<endl;
	  move = queens[indexes[i]]->findMove(n, board)>0;
	  if(move>0)
	    {
	      numMoves--;
	      max = 100000;
	      counter = 0;
	      clearBoard(board, n);
	      for(j=0; j<n; j++)
		queens[j]->attack(n, board);
	      conflicts = 0;
	      //cout<<"Moved queen "<<indexes[i]<<" to coord "<<queens[indexes[i]]->getCoord()<<endl;
	      for(j=0; j<n; j++)
		{
		  //cout<<"queen "<<j<<"'s threat: "<<board[queens[j]->getCoord()]<<endl;
		  if(board[queens[j]->getCoord()]>0)
		    {
		      //cout<<"\tincrementing conflicts"<<endl;
		      conflicts++;
		    }
		}
	      //cout<<conflicts<<" conflicts"<<endl;
	      //printBoard(board, n);
	      //cout<<endl;
	    }
	  i++;
	}
      if(move == 0)
	{
	  // if no successful moves, check next priority
	  // if no successful moves in a long time, give up
	  max = current;
	  if(counter > n)
	    break;
	  counter++;
	}
    }

  //print results
  cout<<conflicts<< " conflicts"<<endl;
  for(i=0; i<n; i++)
    cout<<queens[i]->print(n);
  cout<<(clock() - tStart)/CLOCKS_PER_SEC<<" seconds"<<endl;
  return 0;
}
