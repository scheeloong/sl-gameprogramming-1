#include "HFILES/BounceBlock.h"

void BounceBlock::Init(int x, int y, int velX, int velY, int dirX, int dirY, bool alive, 
	ALLEGRO_BITMAP *image, int startY, int species)
{
	//There are no animations associated with BounceBlock objects. Just move up and down.
	GameObject::Init(MISC, x, y, velX, velY, dirX, dirY, alive, image);
	BounceBlock::startY = startY;
	BounceBlock::species = species;;
}

void BounceBlock::update()
{
	/*if(isMoved)
	{
		cout << "inside" << endl;
		x -= xOff;
		isMoved = false;
	}*/
// if the block is back down to its starting height
	if (getY() + getVelY() > startY - 3)
	{   // Set the tile on Mappy back to brick
		if(species == DEAD_QUESTION)
		{
			setY(startY);
			// for some reason, the below is glitchy.
			// screen flashes briefly and replaces the tile with a shrunken one.
			MapChangeLayer(0);
			// This sets the DeadQuestion tile to a piece of land with User1 as true.
			MapSetBlockInPixels(getX(), getY() + 20, 407);
		}
		else if(species == DEAD_BRICK)
		{	//Set the brick back.
			MapChangeLayer(0);
			MapSetBlockInPixels(getX(), getY() + 20, 3);
			setAlive(false);
		}
		// setAlive(false);
	}
	else 
		moveVertically();
}

void BounceBlock::draw()
{
	al_draw_bitmap(getImage(), x - xOff, y, 0);
}

