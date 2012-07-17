#include "HFILES\Player.h"
// Constructor
//Player::Player() : lives(3) {}

// Methods
void Player::takeLife (int i)
{
	lives -= i; 
}

void Player::addLife (int i)
{
	lives += i; 
}

void Player::Init(int x, int y, int velX, int velY, int dirX, int dirY, ALLEGRO_BITMAP *image /*, State state, Collision col,*/)
{
		GameObject::Init(x, y, velX, velY, dirX, dirY, image/*, state, col,*/);
		maxFrame = 1;
		curFrame = 0;
		frameCount = 4;
		frameDelay = 10;
		frameWidth = 120;
		frameHeight = 120;
		animationColumns = 4;
		// animationDirection is currently not used by player objects.
		// it might be the same as rewind.
		animationDirection = 1;

		animationRow = 0;
		rewind = 1;
		facing = WALKRIGHT;
		//addLife(lives); I don't know why this is here.
}

//Update animations
void Player::update()
{
	//Allows the mario sprite to move fluently through
	//his 3 positions: Stand, Step, and Land
	//1 2 3 2 1 2 3 2 1 instead of 1 2 3 1 2 3 1 2 3
	if(++frameCount >= frameDelay && (keys[RIGHT]||keys[LEFT]))
	{
		// Go forward through the sprite sheet (LtoR)
		if(rewind == 1)
		{
			if(curFrame >= maxFrame)
			{
				rewind = -1;
			}
		}
		// Go backward through the sprite sheet (RtoL);
		else if(rewind == -1)
		{
			if(curFrame <= 0)
			{
				rewind = 1;
			}
		}
		curFrame += rewind;
		frameCount = 0;
	}
}

void Player::draw()
{
	int fx = (curFrame % animationColumns) * frameWidth;
	int fy = animationRow * frameHeight;
	if (animationDirection == 1)

	if (facing == WALKRIGHT)
	al_draw_bitmap_region(image, fx, fy, frameWidth,
		frameHeight, x - frameWidth / 2, y - frameHeight /2, 0);
	else if (facing == WALKLEFT)
	al_draw_bitmap_region(image, fx, fy, frameWidth,
		frameHeight, x - frameWidth / 2, y - frameHeight /2, ALLEGRO_FLIP_HORIZONTAL);
}
