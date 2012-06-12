// COMP 6761, Summer 2012
// Term Project, a Connect 4 game.
// Name: Hadi Karesli, h_karesli@yahoo.com
// Concordia Student ID: 9317201
#include "camera.h"

#include <iostream>

using namespace std;


TCamera::TCamera(): position(0), look_at(0), up_vector(0), aspect_ratio(0.0)
{
}

// we'll change this to accept explicit values so we don't run into uninitialized pointers
TCamera::TCamera(TPoint* pos, TPoint* lookat, TVector* up, double ar): position(pos), look_at(lookat), up_vector(up), aspect_ratio(ar)
{
}

TCamera::~TCamera()
{
	if(position)
	{
		delete position;
		position = NULL;
	}

	if(look_at)
	{
		delete look_at;
		look_at = NULL;
	}

	if(up_vector)
	{
		delete up_vector;
		up_vector = NULL;
	}
}

void TCamera::setAspectRatio(double asr)
{
	aspect_ratio = asr;
}

double TCamera::getAspectRatio() const
{
	return aspect_ratio;
}

void TCamera::setLookat(double x, double y, double z)
{
	look_at->X = x;
	look_at->Y = y;
	look_at->Z = z;
}

TPoint* TCamera::getLookat() const
{
	return look_at;
}

void TCamera::setPosition(double x, double y, double z)
{
	position->X = x;
	position->Y = y;
	position->Z = z;
}

TPoint* TCamera::getPosition() const
{
	return position;
}




