#ifndef GOOMBA_H
#define GOOMBA_H

#include "Classes.h"
#include "HFILES/GameObject.h"
#include "HFILES/Autobot.h"

class Goomba : public Autobot
{
private:
public:
	Goomba() : Autobot () {setSpecies(GOOMBA); setfacing(WALKLEFT);}
	void Init(int ID, int x, int y, int velX, int velY, int dirX, int dirY, bool alive, ALLEGRO_BITMAP *image);
	void draw();
};

#endif GOOMBA_H