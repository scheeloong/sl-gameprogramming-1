//
#include "HFILES/PowerUp.h"

// Constructor
PowerUp::PowerUp() {}; 

PowerUp::PowerUp(int x, int y, int velX, int velY, int dirX, int dirY, ALLEGRO_BITMAP *image,
	/*State state, Collision col,*/ bool alive, bool render)
{
	GameObject::Init( x, y, velX, velY, dirX, dirY, image/*, state, col,*/); 
}

// Methods
void PowerUp::Init()
{
	
}
//