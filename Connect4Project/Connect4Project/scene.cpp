// COMP 6761, Summer 2012
// Term Project, a Connect 4 game.
// Name: Hadi Karesli, h_karesli@yahoo.com
// Concordia Student ID: 9317201

#include "scene.h"

#include "gl_operations.h"

using namespace std;


TScene::TScene() : camera(0), light(0), gl_impl(0)
{
	
}

TScene::TScene(TCamera* cam, TLight* lght, int argc, char* argv[]): camera(cam), light(lght)
{
	gl_impl = new GLOperations(0, 800, 0, 600);
	gl_impl->initGLUT(argc, argv);
}

TScene::~TScene()
{
	if(camera)
	{
		delete camera;
		camera = (TCamera*) 0;
	}

	if(light)
	{
		delete light;
		light = (TLight*) 0;
	}

	if(0 < gameEntityList.size())
	{
		vector<TGameEntity*>::iterator it;
		for(it = gameEntityList.begin(); it != gameEntityList.end(); it++)
		{
			delete (*it);
			*it = (TGameEntity*) 0;
		}
	}
}

void TScene::setCamera(TCamera* cam)
{   
	// checks if the pointer is valid then if yes sets the camera to the new pointer
	if(cam)
	{
		camera = cam;
	}
}


TCamera* TScene::getCamera() const
{
	return camera;
}

void TScene::setLight(TLight* lght)
{
	// checks if "lght" is valid then sets "light" pointer to new value
	if(lght)
	{
		light = lght;
	}
}

TLight* TScene::getLight() const
{
	return light;
}


void TScene::initialize()
{
	gl_impl->init(0.0, 800.0, 0.0, 600.0);
}

void TScene::drawScene(int argc, char* argv[])
{
    // I don't know yet what should go here
	// setup the scene somewhere
	// Suggestion:
	vector<TGameEntity*>::iterator it;
	for(it = gameEntityList.begin(); it != gameEntityList.end(); it++)
	{
		// (*it)->draw();
	}

	gl_impl->enterMainLoop();
}

