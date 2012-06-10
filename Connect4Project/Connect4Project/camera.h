#ifndef CAMERA_H
#define CAMERA_H

#include "point3d.h"
#include "vector3d.h"

class TCamera
{
private:
	TPoint* position;
	TPoint* look_at;
	TVector* up_vector;

	double aspect_ratio;
	
	// disallow
	TCamera(const TCamera&);
	TCamera& operator=(const TCamera&);
public:

	explicit TCamera();
	explicit TCamera(TPoint*, TPoint*, TVector*, double);
	virtual ~TCamera();

	// set/get camera position/look_at
	void setPosition(double, double, double);
	TPoint* getPosition() const;
	// set/get look_at
	void setLookat(double, double, double);
	TPoint* getLookat() const;
	// set/get the up vector
	void setUpVector(double, double, double);
	TVector* getUpVector() const;
	// set/get aspect_ratio
	void setAspectRatio(double);
	double getAspectRatio() const;
};

#endif
