// COMP 6761, Summer 2012
// Term Project, a Connect 4 game.
// Name: Hadi Karesli, h_karesli@yahoo.com
// Concordia Student ID: 9317201
#ifndef SCENE_H
#define SCENE_H

#include <vector>

class TGameEntity;
class TCamera;
class TLight;
class GLOperations; 

// this class should have become the major class, 
// but I made a change in architecture to make every thing built around FreeGLUT
// because I needed a game-loop mechanism and FreeGLUT has that, while otherwise 
// I would have had to implement it myself. Which was impossible due to the narrow time interval.

class TScene
{
private:
	// the camera object
	TCamera* camera;
	// the light source
	TLight*   light;
	// OpenGL functionality
	GLOperations* gl_impl;	

	// all graphics objects should be stored in this list
	std::vector<TGameEntity*> gameEntityList;

	// disallow
	TScene(const TScene&);
	TScene& operator=(const TScene&);
public:
	// constructor is explicit to prevent conversions and casting
	explicit TScene();
	explicit TScene(TCamera*, TLight*, int argc, char* argv[]);
	// destructor is virtual to enable proper polymorphism
	virtual ~TScene();
	// initialize the scene, setup the light, camera, projection/modeling matrices etc.
	void initialize();
	// set the camera pointer
	void setCamera(TCamera*);
	// get the camera pointer
	TCamera* getCamera() const;
	// set the light source object pointer
	void setLight(TLight*);
	// get the light pointer
	TLight* getLight() const;
	// send draw command 
	void drawScene(int argc, char* argv[]);

};


#endif
