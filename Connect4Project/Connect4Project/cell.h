#ifndef CELL_H
#define CELL_H

class TState;

class TCell
{
private:
    bool empty;

    TState* currentState;
	
public:
    TCell();
	~TCell();

	void setCurrent(TState*);
	inline void setEmpty(bool emp) { empty = emp; }
	inline bool isEmpty() const { return empty; }
	void goEmpty();
	void goRed();
	void goBlue();	
	int getColor() const;
};



#endif
