#ifndef GL_OPERATIONS_H
#define GL_OPERATIONS_H

#include <vector>
#include <gl\freeglut.h>

class TBoard;
//class GLUquadricObj;

class GLOperations
{
	static GLOperations* currentInstance;
	static TBoard* currentBoard;
	static std::vector<void*> quadricsList;
	static GLUquadricObj* s_qobj;
	// display lists for the disks that will represent the coins
	static GLuint s_disksList;

	// viewport boundaries
	static int XMIN;
	static int XMAX;
	static int YMIN;
	static int YMAX;

	static double max_x_view;
	static double min_x_view;
	static double max_y_view;
	static double min_y_view;

	// mouse coordinates
	static int previousX;
	static int previousY;

	// disallow
	GLOperations(const GLOperations&);
	GLOperations& operator=(const GLOperations&);
	// functions with static binding to interact with GLUT/FreeGLUT
	static void s_reshapeFunc(int w, int h);
	static void s_renderFunc();
	static void s_displayFunc();
	static void s_keyboardFunc(unsigned char key, int x, int y);
	static void s_mouseFunc(int button, int state, int x, int y);
	static void s_timerFunc(int value);
	static void s_idleFunc();

	static void s_drawBoard();	

	TBoard* theGameBoard;
	// the dynamic one
	GLuint disksList;
	GLUquadricObj* qobj;

public:
	explicit GLOperations(int xXMIN = 0, int xXMAX = 1, int yYMIN = 0, int yYMAX = 1);
	~GLOperations();
	// setup the static polygon list
	void init(double minX, double maxX, double minY, double maxY);
	void initGLUT(int argc, char* argv[]);
	// lighting will be hard-wired as there is no time to make it more general.
	void initLighting();
	// init some quadrics objects
	void initQuadrics();

    void reshapeSetup();
	void enterMainLoop();
    void renderSetup();
	
	void keyboardFuncSetup();
	void mouseFuncSetup();
	void timerFuncSetup();
	void idleFuncSetup();
	
};

#endif

