#ifndef GAME_BOARD_H
#define GAME_BOARD_H

#include "cell.h"

// a class for the game board
class TBoard
{
private:
	// the array of all cells on the board.
    TCell* cellsList[6][7];
	// if true then the player is red, blue if false
    bool playerRed;    	
	// insert a "coin" at the respective position with the given color
	bool insertAt(int row, int col, int color);
	// checks whether the given column has an empty position, yes if true
	int checkEmptyPosition(int col);
	// private methods to check whether the game reached a win
	// these methods are called by the method checkForWin()
	bool checkForRowWin();
	bool checkForColumnWin();
	bool checkForDiagonalWin();
	// true if red has won, otherwise the winner is blue 
	bool winnerRed; 
public:
    TBoard();
    ~TBoard();

    bool checkForWin();
	// whether the board is full, yes if true
    bool isFull();
	// a public method inserts a position into a given column with a given color
    void insertAtColumn(int col, int color);    
	// outputs the color state of the board cells
	void currentBoardState(int board[6][7]);
	// player is either red or blue.
	inline bool isPlayerRed() const { return playerRed; }
	// switch the player turn, if player red played it switches to blue
	inline void switchPlayer() { playerRed = !playerRed; }
	// who is the winner? red if true, blue otherwise.
	inline bool isWinnerRed() const { return winnerRed; }
};


#endif
