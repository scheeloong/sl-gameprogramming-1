#ifndef GOOMBA_H
#define GOOMBA_H

#include "Classes.h"
#include "HFILES/GameObject.h"
#include "HFILES/Autobot.h"

class Goomba : public Autobot
{
private:
public:
	//===================
	// Constructor
	//===================
	Goomba() : Autobot () {setfacing(WALKLEFT);}
	void Init(int ID, int species, int x, int y, int velX, int velY, int dirX, int dirY, bool alive, ALLEGRO_BITMAP *image);
	//===================
	// Methods
	//===================
	void draw();
};

#endif GOOMBA_H