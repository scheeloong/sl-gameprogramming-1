#include "HFILES/SuperMushroom.h"

//================
// Constructors
//================

void SuperMushroom::Init(int ID, int species, int x, int y, int velX, int velY, int dirX, int dirY, bool alive, ALLEGRO_BITMAP *image)
{
	Autobot::Init(ID, species, x, y, velX, velY, dirX, dirY, alive, image);

	// changes the animation row to match the species, moving down the png image.
	animationRow = species;
	//maxFrame = 1;
	curFrame = 0;
	//frameCount = 3;
	//frameDelay = 15;
	frameWidth = 50;
	frameHeight = 50;
	if(species == FIRE_FLOWER)
		setVelX(0);
	//animationColumns = 1;
	// animationDirection is currently not used
	//animationDirection = 1;

	//animationRow = 0;
	//rewind = 1;
}

//================
// Methods
//================
void SuperMushroom::draw()
{
	if(getAlive())
	{
		int fx = 0;
		int fy = animationRow * frameHeight;

		al_draw_bitmap_region(image, fx, fy, frameWidth,
			frameHeight, x - frameWidth / 2, y - frameHeight /2, 0);

		al_draw_filled_rectangle(x-22, y-27, x+22, y+27, al_map_rgba(255, 0, 255, 100));
	}
}
