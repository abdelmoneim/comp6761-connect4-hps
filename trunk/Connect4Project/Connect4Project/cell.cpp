
#include "cell.h"
#include "state.h"

#include <iostream>

using namespace std;

TCell::TCell()
{	
    currentState = (TState*)0;
	empty = false;	
}

TCell::~TCell()
{	 
    if(currentState)
	{
	    delete currentState;
		currentState = (TState*)0;
	}	
}

void TCell::setCurrent(TState* s)
{
    if(s)
	{
        currentState = s;
	}
}

void TCell::goEmpty()
{
    currentState->goEmpty(this);
}

void TCell::goRed()
{
    currentState->goRed(this);
}

void TCell::goBlue()
{
    currentState->goBlue(this);
}

int TCell::getColor() const
{
	return currentState->getColor();
}