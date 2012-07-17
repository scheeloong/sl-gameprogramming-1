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
		maxFrame = 4;
		curFrame = 0;
		frameCount = 4;
		frameDelay = 50;
		frameWidth = 120;
		frameHeight = 120;
		animationColumns = 4;
		// why 3?
		animationDirection = 1;

		animationRow = 0;
		//addLife(lives); I don't know why this is here.
}

//Update animations
void Player::update()
{
	if(++frameCount >= frameDelay)
	{
		curFrame += animationDirection;
		cout << "curFrame = " << curFrame << endl;
		if(curFrame >= maxFrame)
			curFrame = 0;
		else if(curFrame <= 0)
			curFrame = maxFrame - 1;
				frameCount = 0;
	}
}

void Player::draw()
{
	int fx = (curFrame % animationColumns) * frameWidth;
	int fy = animationRow * frameHeight;
	
	al_draw_bitmap_region(image, fx, fy, frameWidth,
		frameHeight, x - frameWidth / 2, y - frameHeight /2, 0);
}
