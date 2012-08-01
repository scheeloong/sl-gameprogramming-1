#include "HFILES/BounceBlock.h"

// Constructor
void BounceBlock::Init(int x, int y, int velX, int velY, int dirX, int dirY, bool alive, 
	ALLEGRO_BITMAP *image, int startY, int species)
{
	//There are no animations associated with BounceBlock objects. Just move up and down.
	GameObject::Init(MISC, x, y, velX, velY, dirX, dirY, alive, image);
	BounceBlock::startY = startY;
	BounceBlock::species = species;;
}

//------------------------------------------------------------------------------------------

// This function updates the position and properties of the block.
void BounceBlock::update()
{
	x -= xOff;
// If the block is back down to its starting height
	if (getY() + getVelY() > startY - 3)
	{   // Set the tile on Mappy back to brick
		if(species == DEAD_QUESTION)
		{
			// set the tile's position y back down to starting height,
			setY(startY);
			MapChangeLayer(0);
			// set the underlying block to a 4 sided collidable block with
			// no special properties
			MapSetBlockInPixels(getX(), getY() + 20, 407);
		}
		else if(species == DEAD_BRICK)
		{
			MapChangeLayer(0);
			// set the block back to a brick block, good as new.
			// can be triggered again.
			MapSetBlockInPixels(getX(), getY() + 20, 3);
			setAlive(false);
		}
	}
	else 
		moveVertically();
}

//------------------------------------------------------------------------------------------

// This function draws the block onto the screen
void BounceBlock::draw()
{
	al_draw_bitmap(getImage(), x - xOff, y, 0);
}

