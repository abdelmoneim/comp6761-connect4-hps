#ifndef LIGHT_H
#define LIGHT_H

struct RGBA_Values
{
	double R;
	double G;
	double B;
	double A;
	RGBA_Values(double r = 1.0, double g = 1.0, double b = 1.0, double a = 1.0){}
	RGBA_Values(const RGBA_Values&);
	RGBA_Values& operator=(const RGBA_Values&);
};

class TLight
{
private:
	// Light position
	double x;
	double y;
	double z;
	// Shininess factor
	double shininess;
	// Light color in RGBA format
	RGBA_Values ambient;
	RGBA_Values diffuse;
	RGBA_Values specular;
	
	double spotlight_exponent;

public:

	TLight(){}
	TLight(const TLight&);
	TLight& operator=(const TLight&);
	~TLight(){}

	void setPosition(double xx, double yy, double zz);
	void getPosition(double&, double&, double&) const;

	void setShininess(double);
	double getShininess() const;

	void setAmbient(double rr, double gg, double bb, double aa);
	RGBA_Values getAmbient() const;

	void setDiffuse(double rr, double gg, double bb, double aa);
	RGBA_Values getDiffuse() const;

	void setSpecular(double rr, double gg, double bb, double aa);
	RGBA_Values getSpecular() const;

	void setSpotlightExponent(double);
	double getSpotlightExponent() const;


};


#endif
