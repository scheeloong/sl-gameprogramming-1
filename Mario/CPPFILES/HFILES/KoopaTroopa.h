#ifndef KOOPATROOPA_H
#define KOOPATROOPA_H

#include "HFILES/Classes.h"
#include "HFILES/GameObject.h"
#include "HFILES/Autobot.h"

class KoopaTroopa : public Autobot
{
private:
	int state;
public:
	KoopaTroopa() : Autobot () {setfacing(WALKLEFT); state = WALKING;}
	void Init(int ID, int species, int x, int y, int velX, int velY, int dirX, int dirY, bool alive, ALLEGRO_BITMAP *image);
	void kickTurtle(int playerWalk = 0)
	{
		if(state == WALKING)
			tuckShell();
		else if(state == INSHELL)
		{
			setCollidable(false);
			moveTuckShell(playerWalk);
		}
	}
	void tuckShell() 
	{
		incrementAnimationRow(); 
		setVelX(0); 
		setAnchorX(getX()); 

		curFrame = 0;
		maxFrame = 0; 
		animationColumns = 5;
		rewind = 0;
		state = INSHELL; 
		species = KOOPA_TROOPA_SHELL;
	}
	void moveTuckShell(int playerWalk) 
	{
		setVelX(playerWalk * 5);
		setAnchorX(getX()); 

		curFrame = 0;
		maxFrame = 4;
		rewind = 1;
		frameDelay = 8;

		state = GLIDING; 
		playerWalk > 0 ? facing = WALKRIGHT : facing = WALKLEFT;
		// species is already KOOPA_TROOPA_SHELL;
	}
	int getState() {return state;}
	void draw();
	void update();
};

#endif KOOPATROOPA_H