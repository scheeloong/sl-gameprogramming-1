#include "HFILES\Player.h"
//=======================
// Constructors
//=======================
//Player::Player() : lives(3) {}

void Player::Init(State *state, int x, int y, int velX, int velY, int dirX, int dirY, bool alive, ALLEGRO_BITMAP *image)
{
	Player::state = state;
	GameObject::Init(PLAYER, x, y, velX, velY, dirX, dirY, alive, image);
	//array indexing, so 2 frames.
	maxFrame = 2;
	curFrame = 0;
	frameCount = 0;
	frameDelay = 5;
	frameWidth = 120;
	frameHeight = 120;
	animationColumns = 5;
	// animationDirection is currently not used by player objects.
	// it might be the same as rewind.
	animationDirection = 1;

	animationRow = 0;
	rewind = 1;
	facing = WALKRIGHT;
	//addLife(lives); I don't know why this is here.
}

//=======================
// Methods
//=======================

// This function decrements the player's live by 1
// and changes the gamestate to GAMEOVER if
// the player is dead.
void Player::decrementLife()
{
	if(--lives < 0)
		state->setState(GAMEOVER);
}

//------------------------------------------------------------------------
// This function increments the player's live by 1.
void Player::incrementLife ()
{
	lives++;
}

//------------------------------------------------------------------------
// This function ...
void Player::addScore(int ID_Harvested)
{
	score += (ID_Harvested + 1) * 100;
}

//------------------------------------------------------------------------
// This function updates the animations and velocity of the player.
void Player::update()
{
	moveVertically();
	if(curFrame == JUMPMODE); //TODO: Mario needs to hold his jump position until
	// he hits the ground again. 
	else if(curFrame == CROUCH);

	// Allows the mario sprite to move fluently through
	// his 3 positions: Stand, Step, and Land
	// 1 2 3 2 1 2 3 2 1 instead of 1 2 3 1 2 3 1 2 3
	else if(++frameCount >= frameDelay && (keys[RIGHT]||keys[LEFT]))
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
		frameCount = 0;
		curFrame += rewind;
	}
}

//------------------------------------------------------------------------
// This function ...
void Player::draw()
{
	int fx = (curFrame % animationColumns) * frameWidth;
	int fy = animationRow * frameHeight;
	//if (animationDirection == 1)

	//The trailing added numbers after frameWidth/2 etc. are all arbitrary.
	//The spritesheet in this case was a little crooked and those numbers
	//help recenter the sprite to be drawn.
	if(species == BABY) // used for bound box testing.
	{
		if (facing == WALKRIGHT)
		al_draw_bitmap_region(image, fx, fy, frameWidth,
			frameHeight, x - frameWidth / 2 + 10, y - frameHeight /2 + 10, 0);
		else if (facing == WALKLEFT)
		al_draw_bitmap_region(image, fx, fy, frameWidth,
			frameHeight, x - frameWidth / 2 - 10, y - frameHeight /2 + 10, ALLEGRO_FLIP_HORIZONTAL);
		//This tests the bounding box dimensions.
		al_draw_filled_rectangle(x-13, y-23, x+13, y+23, al_map_rgba(255, 0, 255, 100));
	}
	else if(species == RED || species == WHITE)
	{
		if (facing == WALKRIGHT)
		al_draw_bitmap_region(image, fx, fy, frameWidth,
			frameHeight, x - frameWidth / 2 + 10, y - frameHeight /2 - 2, 0);
		else if (facing == WALKLEFT)
		al_draw_bitmap_region(image, fx, fy, frameWidth,
			frameHeight, x - frameWidth / 2 - 10, y - frameHeight /2 - 2, ALLEGRO_FLIP_HORIZONTAL);
		//This tests the bounding box dimensions.
		al_draw_filled_rectangle(x-20, y-45, x+20, y+45, al_map_rgba(255, 0, 255, 100));
	}
}

//------------------------------------------------------------------------
// This function ...
void Player::startLeap() 
{
	//Start the jump only if the object is NOT onAir, aka on the ground
	if(!getonAir())
	{
		setVelY(maxSpeed);
		//Every time the speed is changed, moveVertically must be called
		//to change the object's position slightly. Otherwise, the 
		//Collision class keeps it in a stuck mode.
		moveVertically();
		//Because it's been movedVertically, it is now in the air.
		setonAir(true);
	}
}
