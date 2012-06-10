#ifndef GAME_BOARD_H
#define GAME_BOARD_H

#include "cell.h"

class TBoard
{
private:
    TCell cellsList[6][7];
    bool playerRed;    
	bool insertAt(int row, int col, int color);
	int checkEmptyPosition(int col);
	
	bool checkForRowWin();
	bool checkForColumnWin();
	bool checkForDiagonalWin();
	
public:
    TBoard();
    ~TBoard(){}

    bool checkForWin();
    bool isFull();
    void insertAtColumn(int col, int color);    
	// outputs the color state of the board cells
	void currentBoardState(int board[6][7]);
	// player is either red or blue.
	inline bool isPlayerRed() const { return playerRed; }
	inline void switchPlayer() { playerRed = !playerRed; }
};


#endif
