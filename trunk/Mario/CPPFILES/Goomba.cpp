#include "HFILES/Goomba.h"

void Goomba::Init(int ID, int species, int x, int y, int velX, int velY, int dirX, int dirY, bool alive, ALLEGRO_BITMAP *image)
{
	Autobot::Init(ID, species, x, y, velX, velY, dirX, dirY, alive, image);

	maxFrame = 1;
	curFrame = 0;
	frameCount = 3;
	frameDelay = 15;
	frameWidth = 120;
	frameHeight = 120;
	animationColumns = 4;
	// animationDirection is currently not used
	animationDirection = 1;

	animationRow = 0;
	rewind = 1;
	facing = WALKLEFT;
}

void Goomba::draw()
{
		int fx = (curFrame % animationColumns) * frameWidth;
		int fy = animationRow * frameHeight;
		//if (animationDirection == 1)

		//The trailing added numbers after frameWidth/2 etc. are all arbitrary.
		//The spritesheet in this case was a little crooked and those numbers
		//help recenter the sprite to be drawn.

		al_draw_bitmap_region(image, fx, fy, frameWidth,
			frameHeight, x - frameWidth / 2 + 6, y - frameHeight /2 + 10, 0);
		//This tests the bounding box dimensions.
		al_draw_filled_rectangle(x-22, y-27, x+22, y+27, al_map_rgba(255, 0, 255, 100));
}