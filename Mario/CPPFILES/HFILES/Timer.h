#ifndef TIMER_H
#define TIMER_H

//#pragma once
#include "HFILES/Classes.h"
#include "HFILES/Player.h"

class Timer
{
private:
	
	int FPS;
	Player *player;

public:
	Timer(Player *player, ALLEGRO_TIMER *timer, ALLEGRO_EVENT_QUEUE *event_queue);
	void updateTimer(ALLEGRO_EVENT &ev);
	void destroyTimer(ALLEGRO_TIMER *timer) {al_destroy_timer(timer);}
};
#endif TIMER_H