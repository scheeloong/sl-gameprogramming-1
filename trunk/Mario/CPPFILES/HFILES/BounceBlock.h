#ifndef BOUNCEBLOCK_H
#define BOUNCEBLOCK_H
#include "Classes.h"
#include "GameObject.h"

class BounceBlock : public GameObject
{
private:
	// the next two variables store coordinates of the block on the map
	int startY;
	int species;
public:
	BounceBlock() : GameObject() {velX = 0; ID = MISC; onAir = true;}
	void Init(int x, int y, int velX, int velY, int dirX, int dirY, bool alive, 
		ALLEGRO_BITMAP *image, int startY, int species);
	int getStartY() {return startY;}
	void update();
	void draw();
};
#endif BOUNCEBLOCK_H