#pragma once
#include "HFILES/Timer.h"

void Timer::updateTimer(ALLEGRO_EVENT *ev)
{
	MapUpdateAnims();
	if(ev->type == ALLEGRO_EVENT_TIMER)
		{
			redraw = true;
			if(keys[UP] && !lock[UP])
			{	
				player->moveUp();
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
				//if(player->getLife() <= 0)
					//isGameOver = true;
			}
		}
}
