
#include "application.h"
#include "gl_operations.h"

#include <iostream>

using namespace std;


int main(int argc, char* argv[])
{
	// TApplication theApp;
	GLOperations scene;
	try
	{
		// theApp.setActive(true);
		// theApp.execute(argc, argv);
		scene.initGLUT(argc, argv);
		scene.init(0.0, 800.0, 0.0, 600.0);
		scene.initLighting();
		scene.initQuadrics();
		scene.enterMainLoop();
	}
	catch(exception& e)
	{
		cout << e.what() << endl;
	}

	return 0;
}