#include "History.h"
#include "globals.h"
//#include "Mesa.h" //guess it doesnt need lol

History::History(int nRows, int nCols)
	: rows(nRows) , cols(nCols)
{ 
	for (int i = 0; i < nRows; i++)
	{
		for (int k = 0; k < nCols; k++)
		{
			hGrid[i][k] = '.';
		}
	}
}

/*
for n in rows
	for m in cols
		history[n,m]= '.'
*/

bool History::record(int r, int c)
//notify the History object that a gark was at row r, column c when
//the player attacked it without its dying
{
	//checking stuff:
	if (r > MAXROWS || c > MAXCOLS)
	{
		return false;
	}
	if (r < 1 || c < 1)
	{
		return false;
	}


	//recording:
	//go to spot and check whats there
	char ch = this->hGrid[r-1][c-1];
	//if it has '.'
	if (ch == '.')
	{
		this->hGrid[r-1][c-1] = 'A';
	}
	else if (ch != '.') //if it has letter
		//should also check to make sure it A-Z
	{
		//check if its Z
		if (ch == 'Z')
		{
			return true;//leave early
		}//else: increase by 1
		this->hGrid[r-1][c-1]++;
	}
	else
	{
		std::cout << "something is very wrong";
		return false; //idk, something went rly wrong
	}
	// returns true after recording what it needs to
	return true;
}


void History::display() const
{ // display method
	clearScreen();
	int width = cols, height = rows;
	for (int i = 0; i < height; ++i)
	{
		for (int j = 0; j < width; ++j)
		{
			cout << hGrid[i][j];
		}
		cout << endl;
	}
	cout << endl; //shouldnt need bc
	//last iteration of loop has
	//an extra call to endl
	// but idk
}