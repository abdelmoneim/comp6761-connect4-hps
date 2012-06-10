

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