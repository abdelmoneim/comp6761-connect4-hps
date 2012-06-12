// COMP 6761, Summer 2012
// Term Project, a Connect 4 game.
// Name: Hadi Karesli, h_karesli@yahoo.com
// Concordia Student ID: 9317201

#include "point3d.h"

TPoint::TPoint(const TPoint& rhs)
{
	X = rhs.X;
	Y = rhs.Y;
	Z = rhs.Z;
}

TPoint& TPoint::operator=(const TPoint& rhs)
{
	if(this == &rhs)
	{
	}
	else
	{
        X = rhs.X;
	    Y = rhs.Y;
	    Z = rhs.Z; 
	}

	return *this;
}