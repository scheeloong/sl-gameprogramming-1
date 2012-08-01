#include "HFILES/KoopaTroopa.h"

//=================
// Constructors
//=================
void KoopaTroopa::Init(int ID, int species, int x, int y, int velX, int velY, int dirX, int dirY, bool alive, ALLEGRO_BITMAP *image)
{
	Autobot::Init(ID, species, x, y, velX, velY, dirX, dirY, alive, image);
	maxFrame = 1;
	curFrame = 0;
	frameCount = 3;
	frameDelay = 15;
	frameWidth = 120;
	frameHeight = 120;
	animationColumns = 2;
	facing = WALKLEFT;
	// animationDirection becomes critical when Koopa is in his shell and gliding 
	animationDirection = facing;
	animationRow = 0;
	rewind = 1;
}

//=================
// Methods
//=================
void KoopaTroopa::kickTurtle(int playerWalk = 0)
{
	if(state == WALKING)
		tuckShell();
	else if(state == INSHELL)
	{
		setCollidable(false);
		moveTuckShell(playerWalk);
	}
}

void KoopaTroopa::tuckShell() 
{
	incrementAnimationRow(); 
	setVelX(0); 
	setAnchorX(getX()); 

	curFrame = 0;
	maxFrame = 0; 
	animationColumns = 5;
	rewind = 0;
	state = INSHELL; 
	species = KOOPA_TROOPA_SHELL;
}

void KoopaTroopa::moveTuckShell(int playerFacing) 
{
	setVelX(playerFacing * 5);
	// After the object moves a certain distance away from from anchor point,
	// it's collidable will be set back to true.
	setAnchorX(getX()); 

	curFrame = 0;
	maxFrame = 4;
	rewind = 1;
	frameDelay = 8;

	state = GLIDING; 
	playerFacing > 0 ? facing = WALKRIGHT : facing = WALKLEFT;
}

void KoopaTroopa::draw()
{
	int fx = (curFrame % animationColumns) * frameWidth;
	int fy = animationRow * frameHeight;
	if(state == WALKING) // used for bound box testing.
	{
		if (facing == WALKRIGHT)
		al_draw_bitmap_region(image, fx, fy, frameWidth,
			frameHeight, x - frameWidth / 2, y - frameHeight /2 + 10, ALLEGRO_FLIP_HORIZONTAL);
		else if (facing == WALKLEFT)
		al_draw_bitmap_region(image, fx, fy, frameWidth,
			frameHeight, x - frameWidth / 2, y - frameHeight /2 + 10, 0);
		//This tests the bounding box dimensions.
		al_draw_filled_rectangle(x-22, y-30, x+22, y+30, al_map_rgba(255, 0, 255, 100));
	}
	else if(state = INSHELL || state == GLIDING)
	{
		if (facing == WALKRIGHT)
		al_draw_bitmap_region(image, fx, fy, frameWidth,
			frameHeight, x - frameWidth / 2, y - frameHeight /2 - 2, 0);
		else if (facing == WALKLEFT)
		al_draw_bitmap_region(image, fx, fy, frameWidth,
			frameHeight, x - frameWidth / 2, y - frameHeight /2 - 2, ALLEGRO_FLIP_HORIZONTAL);
		//This tests the bounding box dimensions.
		al_draw_filled_rectangle(x-20, y-20, x+20, y+20, al_map_rgba(255, 0, 0, 100));
	}
}

// This function ...
void KoopaTroopa::update()
{
	//the enemy moves on its own, so calling arbitrary move function.
	if(!getCollidable() && checkAnchorXDistance(100))
	{setCollidable(true);}
	moveSideWays(velX - deltaXOff);
	moveVertically();
	// The below is a strict 123123123 animation for spinning Koopa in shell
	// exclusively.
	if(species == KOOPA_TROOPA_SHELL && getVelX())
	{
		if(++frameCount >= frameDelay)
		{
			curFrame += animationDirection;
			if(curFrame >= maxFrame)
				{curFrame = 0;}
			else if(curFrame <= 0)
				{curFrame = maxFrame - 1;}
			frameCount = 0;
		}
	}
	// The below is a 1 2 3 2 1 2 3 2 1 animation, same as Autobot::update();
	else
	{ 
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