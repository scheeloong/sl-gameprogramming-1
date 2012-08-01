#ifndef KOOPATROOPA_H
#define KOOPATROOPA_H

#include "HFILES/Classes.h"
#include "HFILES/GameObject.h"
#include "HFILES/Autobot.h"

class KoopaTroopa : public Autobot
{
private:
	int state;
	// Upgrading Koopa --------------------
	// This function changes the turtle's state from WALKING to INSHELL, sets his velX = 0
	// and appropriately sets animation data associated with that.
	void tuckShell();

	// This function changes the turtle's state from INSHELL to GLIDING, sets initial velX
	// and again sets animation data associated with that.
	void moveTuckShell(int playerWalk);
	// ------------------------------------

public:
	//===================
	// Constructors
	//===================
	KoopaTroopa() : Autobot () {setfacing(WALKLEFT); state = WALKING;}
	void Init(int ID, int species, int x, int y, int velX, int velY, int dirX, int dirY, bool alive, ALLEGRO_BITMAP *image);

	//===================
	// Set & Get
	//===================
	// Refers to private member, not class State.
	int getState() {return state;}

	//===================
	// Methods
	//===================
	// Upgrading Koopa -----------------------

	// This function integrates tuckShell() and moveTuckShell() based on KoopaTroopa's current state.
	// Parameters: playerFacing is the direction that the player faces when he kicks the turtle 
	//			   (WALKRIGHT or WALKLEFT). 
	//			   Needed to move the turtle in that direction.
	void kickTurtle(int playerFacing);
	//----------------------------------------

	// (@Override) This function draws Koopa based on his state. 
	// Overrides purely because the png image is flipped, where the Koopa normally faces left
	// and Mario faces right. so this the ALLEGRO_FLIP_HORIZONTAL flag is in a different place.
	void draw();

	//----------------------------------------
	// This function updates Koopa's animations and moves Koopa, depending on his state.
	void update();
};

#endif KOOPATROOPA_H