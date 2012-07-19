#ifndef GOOMBA_H
#define GOOMBA_H

#include "Classes.h"
#include "HFILES/GameObject.h"
#include "HFILES/Enemy.h"

class Goomba : public Enemy
{
private:
public:
	Goomba() : Enemy () {}
	void Init(int x, int y, int velX, int velY, int dirX, int dirY, bool alive, ALLEGRO_BITMAP *image);
	void draw();
};

#endif GOOMBA_H