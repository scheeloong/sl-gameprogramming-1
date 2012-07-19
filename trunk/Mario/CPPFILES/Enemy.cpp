//
#include "HFILES/Enemy.h"

//Enemy::Enemy() : lives(1) {}; // normal enemy has 1 live only 
Enemy::Enemy(int lives) : lives(lives) {}; // Boss enemy has >1 live 

// Methods
// Minus i from lives
void Enemy::takeLife(int i)
{
	lives -= i; 
}

void Enemy::addLife(int i) // add i to lives (may not be needed) 
{
	lives += i; 
}

//This constructor won't work because the image won't have been initialized when it is called.
/*Enemy::Enemy(int x, int y, int velX, int velY, int dirX, int dirY, ALLEGRO_BITMAP *image, alive,bool render, int lives)
{
	// call parent constructor
	 GameObject::Init( x, y, velX, velY, dirX, dirY, image); 
	 // set lives
	 lives = 0;
	 addLife(lives); 
}*/

void Enemy::update()
{
	if(getAlive())
	{
		//the enemy moves on its own, so calling arbitrary move function.
		moveRight();
		moveVertically();
		if(++frameCount >= frameDelay)
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
}


//*/