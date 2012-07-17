#pragma once
#include "HFILES/Timer.h"

void Timer::updateTimer(ALLEGRO_EVENT *ev)
{
	MapUpdateAnims();
	if(ev->type == ALLEGRO_EVENT_TIMER)
		{
			redraw = true;
			if(keys[UP] && !lock[UP])
				player->moveUp();
			else if(keys[DOWN] && !lock[DOWN])
				player->moveDown();
			else
				//player->resetAnimation();

			if(keys[LEFT] && !lock[LEFT])
				player->moveLeft();
			else if(keys[RIGHT] && !lock[RIGHT])
				player->moveRight();
			else
				player->resetAnimation();

			if(!isGameOver)
			{
				//if(player->getLife() <= 0)
					//isGameOver = true;
			}
		}
}
