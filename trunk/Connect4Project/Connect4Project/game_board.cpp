
#include "game_board.h"


TBoard::TBoard()
{
	for(int i = 0; i < 6; ++i)
	{
	    for(int j = 0; j < 7; ++j)
		{
		    // initialize all cells
		    cellsList[i][j].goEmpty();
		}
	}

	playerRed = true;
}	

// returns -1 if full
int TBoard::checkEmptyPosition(int col)
{
    for(int i = 5; i > -1; --i)
	{
	    if(cellsList[i][col].isEmpty())
		{
		    return i;
		}
	}
	return -1;
}

bool TBoard::isFull()
{
    for(int col = 0; col < 7; ++col)
	{
	    if(-1 != checkEmptyPosition(col))
		{
		    return false;
		}
	}
	// otherwise the board is full
	return true;
}

void TBoard::insertAtColumn(int col, int color)
{
    if(0 <= col && 6 >= col)
	{
	    int i = checkEmptyPosition(col);
	    if(-1 != i)
		{
		    if(1 == color)  // suppose 1 = Red, 2 = Blue
			{
		        cellsList[i][col].goRed();
			}
			else
			{
			    cellsList[i][col].goBlue();
			}
		}
		else if(isFull())
		{
		    // do something, end game or go main menu
		}		
	}
}

bool TBoard::checkForWin()
{
    if(checkForRowWin())
	{
	    return true;
	}
	else if(checkForColumnWin())
	{
	    return true;
	}
	else if(checkForDiagonalWin())
	{
	    return true;
	}
	else
	{
	    return false;
	}
}

bool TBoard::checkForRowWin()
{
    for(int i = 0; i < 6; ++i)
	{
	    for(int j = 0; j < 5; ++j)
		{

		}
	}
	return false;
}

bool TBoard::checkForColumnWin()
{
	return false;
}

bool TBoard::checkForDiagonalWin()
{
	return false;
}

void TBoard::currentBoardState(int board[6][7])
{
	for(int i = 0; i < 5; ++i)
	{
		for(int j = 0; j < 6; ++j)
		{
			board[i][j] = cellsList[i][j].getColor();
		}
	}
}