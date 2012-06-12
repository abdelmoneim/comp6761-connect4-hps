// COMP 6761, Summer 2012
// Term Project, a Connect 4 game.
// Name: Hadi Karesli, h_karesli@yahoo.com
// Concordia Student ID: 9317201

#ifndef STATE_H
#define STATE_H

class TCell;

class TState
{
public:
    TState(){}
    virtual ~TState(){}	
		
    virtual void goRed(TCell*){}
    virtual void goBlue(TCell*){}
    virtual void goEmpty(TCell*){}
	virtual int getColor() const { return 0; }
};
	
class TEmpty : public TState
{
public:
   TEmpty(){}
   ~TEmpty(){}
   void goEmpty(TCell*){} // the cell is already empty
   void goRed(TCell* cell);
   void goBlue(TCell* cell);
   int getColor() const;
};

class TRed : public TState
{
private:
      
public:
	TRed(){}
	~TRed(){}
	// main state change
    void goEmpty(TCell* cell);
	// nothing here to implement
	void goRed(TCell*){}
	void goBlue(TCell*){}
	int getColor() const;
};

class TBlue : public TState
{
private:
   
public:
	TBlue(){}
	~TBlue(){}
	// nothing to implement
	void goRed(TCell*){}
	// the cell is already blue
    void goBlue(TCell*){} 
	// main change of state from Blue to Empty
    void goEmpty(TCell* cell);
	int getColor() const;
};




#endif
