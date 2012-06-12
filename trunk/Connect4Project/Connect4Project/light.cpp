// COMP 6761, Summer 2012
// Term Project, a Connect 4 game.
// Name: Hadi Karesli, h_karesli@yahoo.com
// Concordia Student ID: 9317201

#include "light.h"

RGBA_Values::RGBA_Values(const RGBA_Values& rhs)
{
	R = rhs.R;
	G = rhs.G;
	B = rhs.B;
	A = rhs.A;
}

RGBA_Values& RGBA_Values::operator=(const RGBA_Values& rhs)
{
	if(this == &rhs)
	{
		// jump to the end
	}
	else
	{
		// copy rhs appropriately
		R = rhs.R;
	    G = rhs.G;
	    B = rhs.B;
	    A = rhs.A;
	}
	// return the copy
	return *this;
}


TLight::TLight(const TLight& rhs)
{
	x = rhs.x;
	y = rhs.y;
	z = rhs.z;

	shininess = rhs.shininess;

	ambient  = rhs.ambient;
	diffuse  = rhs.diffuse;
	specular = rhs.specular;

	spotlight_exponent = rhs.spotlight_exponent;
}

TLight& TLight::operator=(const TLight& rhs)
{
	if(this == &rhs)
	{
	}
	else
	{
		x = rhs.x;
	    y = rhs.y;
    	z = rhs.z;

	    shininess = rhs.shininess;

	    ambient  = rhs.ambient;
	    diffuse  = rhs.diffuse;
	    specular = rhs.specular;

	    spotlight_exponent = rhs.spotlight_exponent;
	}

	return *this;
}

RGBA_Values TLight::getAmbient() const
{
    return ambient;
}

RGBA_Values TLight::getDiffuse() const
{
	return diffuse;
}

void TLight::getPosition(double& posX, double& posY, double& posZ) const
{
	posX = x;
	posY = y;
	posZ = z;
}

double TLight::getShininess() const
{
	return shininess;
}

RGBA_Values TLight::getSpecular() const
{
	return specular;
}

double TLight::getSpotlightExponent() const
{
	return spotlight_exponent;
}

void TLight::setAmbient(double rr, double gg, double bb, double aa)
{
	ambient.R = rr;
	ambient.G = gg;
	ambient.B = bb;
	ambient.A = aa;
}

void TLight::setDiffuse(double rr, double gg, double bb, double aa)
{
	diffuse.R = rr;
	diffuse.G = gg;
	diffuse.B = bb;
	diffuse.A = aa;
}

void TLight::setPosition(double xx, double yy, double zz)
{
	x = xx;
	y = yy;
	z = zz;
}

void TLight::setShininess(double s)
{
	shininess = s;
}

void TLight::setSpecular(double rr, double gg, double bb, double aa)
{
	specular.R = rr;
	specular.G = gg;
	specular.B = bb;
	specular.A = aa;
}

void TLight::setSpotlightExponent(double exp)
{
	spotlight_exponent = exp;
}


