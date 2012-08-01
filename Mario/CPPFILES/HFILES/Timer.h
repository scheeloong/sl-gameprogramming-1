#ifndef TIMER_H
#define TIMER_H

//#pragma once
#include "HFILES/Classes.h"
#include "HFILES/Player.h"
#include "HFILES/Autobot.h"
#include "HFILES/Database.h"
#include "HFILES/State.h"

class Timer
{
private:
	
	/*Player *player;
	Enemy *enemy;*/
	Database *database;
	State *state;
	bool isItFlying(GameObject *object);

public:
	Timer(Database *database, State *state) { Timer::database = database; Timer::state = state;}
	void updateTimer(ALLEGRO_EVENT *ev);
	void destroyTimer(ALLEGRO_TIMER *timer) {al_destroy_timer(timer);}
};
#endif TIMER_H