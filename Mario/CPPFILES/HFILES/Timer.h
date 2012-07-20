#ifndef TIMER_H
#define TIMER_H

//#pragma once
#include "HFILES/Classes.h"
#include "HFILES/Player.h"
#include "HFILES/Enemy.h"
#include "HFILES/Database.h"

class Timer
{
private:
	
	/*Player *player;
	Enemy *enemy;*/
	Database *database;
public:
	Timer(Database *database) { Timer::database = database;}
	bool isItFlying(GameObject *object);
	void updateTimer(ALLEGRO_EVENT *ev);
	void destroyTimer(ALLEGRO_TIMER *timer) {al_destroy_timer(timer);}
};
#endif TIMER_H