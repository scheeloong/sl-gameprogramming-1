#pragma once
#include "HFILES/Timer.h"


Timer::Timer(Player *player, ALLEGRO_TIMER *timer, ALLEGRO_EVENT_QUEUE *event_queue)
{
	Timer::player = player;
	FPS = 60;
	timer = al_create_timer(1.0/FPS);
	srand(time(NULL));
	al_register_event_source(event_queue, al_get_timer_event_source(timer));
}


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
				if(player->getLife() <= 0)
					isGameOver = true;
			}
		}
}
