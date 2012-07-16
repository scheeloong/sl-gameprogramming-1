#pragma once
#include "HFILES/Timer.h"

void Timer::updateTimer(ALLEGRO_EVENT &ev)
{
	if(ev.type == ALLEGRO_EVENT_TIMER)
		{
			redraw = true;
			if(keys[UP] && !lock[UP])
				player->moveUp();
			else if(keys[DOWN] && !lock[DOWN])
				player->moveDown();
			//animations for later
			//else
			//	ResetShipAnimation(ship, 1);

			if(keys[LEFT] && !lock[LEFT])
				player->moveLeft();
			else if(keys[RIGHT] && !lock[RIGHT])
				player->moveRight();
			//else
			//	ResetShipAnimation(ship, 2);

			if(!isGameOver)
			{
				//if(player->getLife() <= 0)
					//isGameOver = true;
			}
		}
}
