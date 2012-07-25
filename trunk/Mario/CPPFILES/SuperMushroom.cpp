//
#include "HFILES/SuperMushroom.h"

void SuperMushroom::Init(int ID, int species, int x, int y, int velX, int velY, int dirX, int dirY, bool alive, ALLEGRO_BITMAP *image)
{
	Autobot::Init(ID, species, x, y, velX, velY, dirX, dirY, alive, image);

	/*maxFrame = 1;
	curFrame = 0;
	frameCount = 3;
	frameDelay = 15;
	frameWidth = 120;
	frameHeight = 120;
	animationColumns = 4;
	// animationDirection is currently not used
	animationDirection = 1;

	animationRow = 0;
	rewind = 1;*/
}

void SuperMushroom::draw()
{
	if(getAlive())
	{
		/*int fx = (curFrame % animationColumns) * frameWidth;
		int fy = animationRow * frameHeight;

		al_draw_bitmap_region(image, fx, fy, frameWidth,
			frameHeight, x - frameWidth / 2 + 6, y - frameHeight /2 + 10, 0);*/

		al_draw_bitmap(image, x - 25, y - 25, 0);
		al_draw_filled_rectangle(x-22, y-27, x+22, y+27, al_map_rgba(255, 0, 255, 100));
	}
}

