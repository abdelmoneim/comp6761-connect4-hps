
#include "application.h"
#include "gl_operations.h"

#include <iostream>

using namespace std;


int main(int argc, char* argv[])
{
	// TApplication theApp;
	GLOperations gl_scene(0, 800, 0, 600);
	try
	{
		// theApp.setActive(true);
		// theApp.execute(argc, argv);
		gl_scene.initGLUT(argc, argv);
		gl_scene.init(-20.0, 20.0, -20.0, 20.0);
		gl_scene.initLighting();
		gl_scene.initQuadrics();
		gl_scene.enterMainLoop();
	}
	catch(exception& e)
	{
		cout << e.what() << endl;
	}

	return 0;
}