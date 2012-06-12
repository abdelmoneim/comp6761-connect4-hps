// COMP 6761, Summer 2012
// Term Project, a Connect 4 game.
// Name: Hadi Karesli, h_karesli@yahoo.com
// Concordia Student ID: 9317201

#ifndef POINT3D_H
#define POINT3D_H


struct TPoint
{
	double X;
	double Y;
	double Z;
	
	TPoint(): X(0.0), Y(0.0), Z(0.0) {}
	~TPoint(){}
	TPoint(double xx, double yy, double zz) : X(xx), Y(yy), Z(zz){}
	TPoint(const TPoint&);
	TPoint& operator=(const TPoint&);
};


#endif
