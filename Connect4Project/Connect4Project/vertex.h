// COMP 6761, Summer 2012
// Term Project, a Connect 4 game.
// Name: Hadi Karesli, h_karesli@yahoo.com
// Concordia Student ID: 9317201
#ifndef VERTEX_H
#define VERTEX_H

#include "point3d.h"
#include "vector3d.h"

const double EPS = 0.000001;

class Vertex
{
private:
	// vertex position
	TPoint position;
    // the vertex "normal", needed for lighting procedures
	TVector normal;

public:
	explicit Vertex(){}
	explicit Vertex(double xx, double yy, double zz): position(xx, yy, zz){}
	explicit Vertex(const Vertex&);
	~Vertex(){}

	Vertex& operator=(const Vertex&);
	// setters and getters for the position of the vertex
	inline void setX(double xx) { position.X = xx; }
	inline void setY(double yy) { position.Y = yy; }
	inline void setZ(double zz) { position.Z = zz; }
	inline double getX() const  { return position.X; }
	inline double getY() const  { return position.Y; }
	inline double getZ() const  { return position.Z; }
    // another way to set and get the position of the vertex
	inline void setPosition(double xx, double yy, double zz) { position.X = xx; position.Y = yy; position.Z = zz; }
	inline TPoint getPosition() const { return position; }
	// setting and getting the vertex normal
	inline void setNormal(double xx, double yy, double zz) { normal.X = xx; normal.Y = yy; normal.Z = zz; }
	inline TVector getNormal()  const { return normal; }
};


// Maybe I'll implement some "utility" functions, like the distance between two vertices, etc.


#endif
