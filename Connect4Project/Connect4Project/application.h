// COMP 6761, Summer 2012
// Term Project, a Connect 4 game.
// Name: Hadi Karesli, h_karesli@yahoo.com
// Concordia Student ID: 9317201
 

#ifndef APPLICATION_H
#define APPLICATION_H

class TScene;
// suggestion:
// class TGamelogic;

// This was supposed to be the main class in the application, 
// which should have the game loop mechanism implemented inside.
// But is ditched in favor of the use of FreeGLUT.
// It's included here for completeness.

// could be a singleton, we will think it later.
class TApplication
{
private:
	// is application active? if false then exit
	bool active;
	// a pointer to scene data, that is light, camera, object data
	TScene* scene;

	// suggestion:
	// TGamelogic* gameImp;  // <-- using pointer-to-implementation idiom

	// disallow:
	TApplication(const TApplication&);
	TApplication& operator=(const TApplication&);
public:
	// the constructor is explicit to prevent casting
	explicit TApplication();
	explicit TApplication(int argc, char* argv[]);
	// make the destructor virtual to enable polymorphic behavior, should the class be subclassed further
	virtual ~TApplication();

	// the most important game operations during the game loop are updateUserInput, updateGameLogic, updateGraphics:
	// updates user input and mouse/keyboard handling
	virtual void updateUserInput();
	// update game logic based on user input and game mechanisms
	virtual void updateGameLogic();
	// send graphics to the pipeline to be rendered
	virtual void updateGraphics(int argc, char* argv[]);
	// is the application active? if true returned then yes
	inline bool isActive() const { return active; }
	// set the activness of the application
	inline void setActive(bool status) { active = status; }
	// set the scene object pointer
	void setScene(TScene*);
	// get a pointer to scene data
	TScene* getScene() const;
	// executes the application
	void execute(int argc, char* argv[]);

};


#endif
