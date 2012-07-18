#ifndef TIMER_H
#define TIMER_H

//#pragma once
#include "HFILES/Classes.h"
#include "HFILES/Player.h"
#include "HFILES/Enemy.h"

class Timer
{
private:
	
	Player *player;
	Enemy *enemy;

public:
	Timer(Player *player, Enemy *enemy) {Timer::player = player; Timer::enemy = enemy;}
	bool isItFlying(GameObject *object);
	void updateTimer(ALLEGRO_EVENT *ev);
	void destroyTimer(ALLEGRO_TIMER *timer) {al_destroy_timer(timer);}
};
#endif TIMER_H