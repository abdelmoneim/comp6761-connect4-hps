

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

