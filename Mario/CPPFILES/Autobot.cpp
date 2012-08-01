//
#include "HFILES/Autobot.h"
//===============
// Constructors
//===============
Autobot::Autobot(int lives) : lives(lives) {}; // Boss enemy has >1 live 

// CL: SO HOW DO WE INITIALIZE IT?
// VL: We'll use Init() as defined in Autobot.h. It just doesn't have the ALLEGRO_BITMAP *image, alive, render, etc as parameters.
//This constructor won't work because the image won't have been initialized when it is called.
// Kill the /*stuff*/ asap.
/*Enemy::Enemy(int x, int y, int velX, int velY, int dirX, int dirY, ALLEGRO_BITMAP *image, alive,bool render, int lives)
{
	// call parent constructor
	 GameObject::Init( x, y, velX, velY, dirX, dirY, image); 
	 // set lives
	 lives = 0;
	 addLife(lives); 
}*/

//============
// Methods
//============

// This function minus i from lives
void Autobot::takeLife(int i)
{
	lives -= i; 
}

//------------------------------------------------------------------------------------------

// This function adds i to lives
void Autobot::addLife(int i)
{
	lives += i; 
}

//------------------------------------------------------------------------------------------

// This function updates the position of the Autobot.
void Autobot::update()
{
	//the enemy moves on its own, so calling arbitrary move function.
	if(!getCollidable() && checkAnchorXDistance(100))
		setCollidable(true);
	moveSideWays(velX - deltaXOff);
	moveVertically();
	cout << deltaXOff << " " << xOff << endl;
	//=============================================
	// 1 2 3 2 1 2 3 2 1 animation
	//=============================================
	if(++frameCount >= frameDelay)
	{
		// Go forward through the sprite sheet (LtoR)
		if(rewind == 1)
		{
			// If it is at the RIGHT end of the sprite sheet
			if(curFrame >= maxFrame)
			{
				// Let it move left
				rewind = -1;
			}
		}
		// Go backward through the sprite sheet (RtoL);
		else if(rewind == -1)
		{
			// If it is at the LEFT end of the sprite sheet,
			if(curFrame <= 0)
			{
				// Let it move right
				rewind = 1;
			}
		}
		curFrame += rewind; // move the current frame 
		frameCount = 0; // reset frameCount
	}
}
