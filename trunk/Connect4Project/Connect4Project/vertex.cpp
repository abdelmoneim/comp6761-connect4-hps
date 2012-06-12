// COMP 6761, Summer 2012
// Term Project, a Connect 4 game.
// Name: Hadi Karesli, h_karesli@yahoo.com
// Concordia Student ID: 9317201

#include "vertex.h"

Vertex::Vertex(const Vertex& rhs)
{
	position = rhs.position;
	normal   = rhs.normal;
}

Vertex& Vertex::operator=(const Vertex& rhs)
{
	if(this == &rhs)
	{
	    // jump to last statement     
	}
	else
	{
		position = rhs.position;
		normal   = rhs.normal;
	}

	return *this;
}

