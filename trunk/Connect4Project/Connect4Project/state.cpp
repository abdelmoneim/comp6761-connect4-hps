
#include "state.h"
#include "cell.h"

void TEmpty::goRed(TCell* cell)
{
    cell->setCurrent(new TRed);
    cell->setEmpty(false);
    delete this;
}

void TEmpty::goBlue(TCell* cell)
{
    cell->setCurrent(new TBlue);
    cell->setEmpty(false);
}   

int TEmpty::getColor() const
{
	return 0;
}

void TRed::goEmpty(TCell* cell)
{
    cell->setCurrent(new TEmpty);
	cell->setEmpty(true);
	delete this;
}	

int TRed::getColor() const
{
	return 1;
}


void TBlue::goEmpty(TCell* cell)
{
    cell->setCurrent(new TEmpty);
    cell->setEmpty(true);
    delete this;
}

int TBlue::getColor() const
{
	return 2;
}

