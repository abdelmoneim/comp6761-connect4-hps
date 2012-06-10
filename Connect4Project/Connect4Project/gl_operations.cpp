
#include <vector>

#include "gl_operations.h"
#include "game_board.h"

#include <gl\freeglut.h>

// initializing static data members
GLOperations* GLOperations::currentInstance = static_cast<GLOperations*>( 0 );
TBoard* GLOperations::currentBoard = static_cast<TBoard*>( 0 ); 

int GLOperations::XMIN = 0;
int GLOperations::XMAX = 1;
int GLOperations::YMIN = 0;
int GLOperations::YMAX = 1;

GLOperations::GLOperations(int xXMIN, int xXMAX, int yYMIN, int yYMAX)
{
	XMIN = xXMIN;
	XMAX = xXMAX;
	YMIN = yYMIN;
	YMAX = yYMAX;

	theGameBoard = new TBoard;
}

GLOperations::~GLOperations()
{
	if(currentInstance)
	{
		delete currentInstance;
		currentInstance = static_cast<GLOperations*>( 0 );
	}

	if(theGameBoard)
	{
		delete theGameBoard;
		theGameBoard = NULL;
	}
}

void GLOperations::init(double minX, double maxX, double minY, double maxY)
{		
	XMIN = static_cast<int>(minX);
	XMAX = static_cast<int>(maxX);
	YMIN = static_cast<int>(minY);
	YMAX = static_cast<int>(maxY);

	// set the clear color to be white
//	glClearColor(1.0, 1.0, 1.0, 1.0);
	// setup the viewing volume in 3D
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();		
	gluPerspective(60.0, (maxX - minX)/(maxY-minY), 1.0, 200.0);

	// prepare the model view
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}


void GLOperations::initGLUT(int argc, char* argv[])
{
	// initialization of winidow size, position, color format and animation support
    glutInitWindowSize(800, 600);
    glutInitWindowPosition ( 140, 140 );
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutInit(&argc, argv);	
	char* window_title = "COMP 6761 Connect4";
    int lab1_window = glutCreateWindow( window_title );		
	
	reshapeSetup();
	renderSetup();	
	keyboardFuncSetup();
	mouseFuncSetup();
	timerFuncSetup();
	idleFuncSetup();
}

void GLOperations::initLighting()
{
	GLfloat ambientLight[] = { 0.3, 0.3, 0.3, 1.0 };
	GLfloat diffuseLight[] = { 0.7, 0.7, 0.7, 1.0 };
	GLfloat specular[]     = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat specref[]      = { 1.0, 1.0, 1.0, 1.0 };
	// initial light position
	GLfloat position[]     = { -50.0, 50.0, 100.0, 1.0 };
	// hidden surface removal
	glEnable(GL_DEPTH_TEST);
	// which is the front face, counter-clockwise in this case
	glFrontFace(GL_CCW);
	// enable backface culling
	glEnable(GL_CULL_FACE);
	// enable lighting 
	glEnable(GL_LIGHTING);
	
	glLightfv(GL_LIGHT0, GL_AMBIENT, ambientLight);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuseLight);
	glLightfv(GL_LIGHT0, GL_SPECULAR, specular);
	glLightfv(GL_LIGHT0, GL_POSITION, position);
	glEnable(GL_LIGHT0);
	
	// enable color tracking
	glEnable(GL_COLOR_MATERIAL);

	glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);

	glMaterialfv(GL_FRONT, GL_SPECULAR, specref);
	glMateriali(GL_FRONT, GL_SHININESS, 128);
	// background color
	glClearColor(0.0, 0.0, 0.0, 1.0);
}

void GLOperations::initQuadrics()
{

}

void GLOperations::reshapeSetup()
{
	currentInstance = this;
	currentBoard = theGameBoard;
	glutReshapeFunc(GLOperations::s_reshapeFunc);
}

void GLOperations::renderSetup()
{
	currentInstance = this;
	currentBoard = theGameBoard;
	glutDisplayFunc(GLOperations::s_renderFunc);
}

void GLOperations::keyboardFuncSetup()
{
	currentInstance = this;
	currentBoard = theGameBoard;
	glutKeyboardFunc(GLOperations::s_keyboardFunc);
}

void GLOperations::mouseFuncSetup()
{
	currentInstance = this;
	currentBoard = theGameBoard;
	glutMouseFunc(GLOperations::s_mouseFunc);
}

void GLOperations::timerFuncSetup()
{
	currentInstance = this;
	currentBoard = theGameBoard;
	glutTimerFunc(40, GLOperations::s_timerFunc, 1);
}

void GLOperations::idleFuncSetup()
{
	currentInstance = this;
	currentBoard = theGameBoard;
	glutIdleFunc(GLOperations::s_idleFunc);
}

void GLOperations::enterMainLoop()
{
	glutMainLoop();
}

// XMIN/XMAX, YMIN/YMAX are the boundary of the scene of polygons. Class PolygonManager will supply them.
void GLOperations::s_reshapeFunc(int w, int h)
{
	// GL reshape procedure goes here
	// prevent devide by zero
	if(0 == h)
	{
		h = 1;
	}
	// set the new viewport
	glViewport(0, 0, w, h);
	// reset the viewing volume
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	// setup perspective projection
    gluPerspective(60.0, w/h, 1.0, 200.0);
	// finally reset the model view
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();                 
}

void GLOperations::s_renderFunc()
{
	// GL render goes here 
	
	// setting the clear color to be white
//	glClearColor(1.0, 1.0, 1.0, 1.0);
	// ckear the color buffer
	glClear(GL_COLOR_BUFFER_BIT);
	// prepare the model view
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	s_drawBoard();

	// let OpenGL executes the commands
	glFlush();	

}

void GLOperations::s_keyboardFunc(unsigned char key, int x, int y)
{
	// black, default.
	int color = 0;
	// who's player's turn?
	if(currentBoard->isPlayerRed())
	{
		// color is red
		color = 1;
	}
	else
	{
		// color is blue otherwise
		color = 2;
	}

	switch(key)
	{
		// ATTENTION: our internal indexing is shifted back one position
	case '1':
		{			
			currentBoard->insertAtColumn(0, color);
		}
		break;
	case '2':
		{			
			currentBoard->insertAtColumn(1, color);
		}
		break;
	case '3':
		{					
			currentBoard->insertAtColumn(2, color);		
		}
		break;
	case '4':
		{			
			currentBoard->insertAtColumn(3, color);
		}
		break;
	case '5':
		{			
			currentBoard->insertAtColumn(4, color);
		}
		break;
	case '6':
		{			
			currentBoard->insertAtColumn(5, color);
		}
		break;
	case '7':
		{			
			currentBoard->insertAtColumn(6, color);
		}
		break;
	default: ;
	}

	glutPostRedisplay();
}

void GLOperations::s_drawBoard()
{

}

void GLOperations::s_mouseFunc(int button, int state, int x, int y)
{

}

void GLOperations::s_timerFunc(int value)
{

}

void GLOperations::s_idleFunc()
{

}