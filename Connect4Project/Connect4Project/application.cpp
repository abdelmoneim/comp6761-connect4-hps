// COMP 6761, Summer 2012
// Term Project, a Connect 4 game.
// Name: Hadi Karesli, h_karesli@yahoo.com
// Concordia Student ID: 9317201

#include "application.h"
#include "scene.h"

#include <iostream>


using namespace std;


TApplication::TApplication(): active(false), scene(0)
{	

}

TApplication::TApplication(int argc, char* argv[]): active(false), scene(0)
{

}

TApplication::~TApplication()
{
	if(scene)
	{
		delete scene;
		scene = NULL;
	}
}

void TApplication::updateGameLogic()
{
	// suggestion:
	// gameImp->updateGame()
}

void TApplication::updateGraphics(int argc, char* argv[])
{
	// could be scene->draw();
	scene->drawScene(argc, argv);
}

void TApplication::updateUserInput()
{
	// we have to think this one
}

void TApplication::setScene(TScene* s)
{
	if(s)
	{
		scene = s;
	}
	else
	{
		throw new exception("Error: Invalid scene pointer!");
	}
}

TScene* TApplication::getScene() const
{
	return scene;
}

void TApplication::execute(int argc, char* argv[])
{
	// I'm not sure about the loop here as GLUT/FreeGLUT have their own main loop
	while(isActive())
	{
		// here goes the game loop:
		// first process user input
	    updateUserInput();
		// then update game status and logic
		updateGameLogic();
		// next render graphics
		updateGraphics(argc, argv);
	}
}