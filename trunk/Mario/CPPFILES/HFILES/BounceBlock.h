#ifndef BOUNCEBLOCK_H
#define BOUNCEBLOCK_H
#include "Classes.h"
#include "GameObject.h"
#include "Autobot.h"
// CL: In every class file, always separate the Constructors, Get & Set, public methods (used outside class)
	// & private methods(used in class), like what I've done below. It improves readability by a lot.
	// Include more comments like @Override (Java convention) to let someone know the function was overriden from parent class

class BounceBlock : public Autobot
{
private:
	// the next two variables store coordinates of the block on the map
	int startX;
	int startY; // initial y position
	int species; // type of bounce block
	bool active;
public:
	// Constructor
	BounceBlock() : Autobot() {velX = 0; ID = MISC; onAir = true;}
	void Init(int x, int y, int velX, int velY, int dirX, int dirY, bool alive, 
		ALLEGRO_BITMAP *image, int species);
	// Get & Set
	int getStartY() {return startY;}
	// Methods
	void update();
	void draw();
};
#endif BOUNCEBLOCK_H