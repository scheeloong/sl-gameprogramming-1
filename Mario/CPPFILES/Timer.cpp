#pragma once
#include "HFILES/Timer.h"

// This function checks if the object is flying, and if yes,
// ensures that it accelerates at the right rate.
bool Timer::isItFlying(GameObject *object)
{
	if (object->getonAir() == true && object->getAlive()) //object is in the air and alive
	{	//halffire ensures we accelerate 
		// every other loop through update timer.
		// essentially making gravity = 0.5
		if(object->gethalffire())
		{
			object->accelerate();
			object->sethalffire(0);
		}
		else object->sethalffire(1);
		return true;
	}
	return false;
}
void Timer::updateTimer(ALLEGRO_EVENT *ev)
{
	
	MapUpdateAnims();
	if(ev->type == ALLEGRO_EVENT_TIMER)
		{
			redraw = true;
			if(isItFlying(player)) {}
			else if(keys[UP] && !lock[UP])
			{	
				// UNIQUE to PLAYER: gives player the initial velocity
				player->startLeap();
				// changes curFrame to JUMPMODE
				player->jumpGlide();
			}
			else if(keys[DOWN] && !lock[DOWN])
				player->moveDown();

			if(keys[LEFT] && !lock[LEFT])
				player->moveLeft();
			else if(keys[RIGHT] && !lock[RIGHT])
				player->moveRight();

			//animation only goes back to frame 0 when all keys are released.
			if(!keys[UP] && !keys[DOWN] && !keys[LEFT] && !keys[RIGHT])
				player->resetAnimation();

			if(!isGameOver)
			{
				isItFlying(enemy); //if(player->getLife() <= 0)
									//isGameOver = true;
			}
		}
}
