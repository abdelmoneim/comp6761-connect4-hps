#ifndef CELL_H
#define CELL_H

class TState;

// a class that represents a cell on the game board.
// it uses the State Design Pattern to change states from empty to either red or blue
// and goes back to empty
class TCell
{
private:
	// is the cell empty or not? yes if true
    bool empty;
	// the current state of the cell
    TState* currentState;
	
public:
    TCell();
	~TCell();
	// set the current state of the cell
	void setCurrent(TState*);
	// set the state of the cell
	inline void setEmpty(bool emp) { empty = emp; }
	// check the state of the cell, if true then it's empty
	inline bool isEmpty() const { return empty; }
	// change state, go into empty state
	void goEmpty();
	// change of state, go into red state
	void goRed();
	// change of state, go into blue state
	void goBlue();	
	// get the color of the cell
	int getColor() const;
};



#endif
