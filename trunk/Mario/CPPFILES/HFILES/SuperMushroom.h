// This class deals with PowerUps

#ifndef SUPERMUSROOM_H
#define SUPERMUSHROOM_H
//#pragma once

#include "HFILES/Classes.h"
#include "HFILES/GameObject.h"
#include "HFILES/Autobot.h"

class SuperMushroom : public Autobot
{
	private:
	public:
		// Constructors
		SuperMushroom() : Autobot() {setfacing(WALKRIGHT);} 
		void Init(int ID, int species, int x, int y, int velX, int velY, int dirX, int dirY, bool alive, ALLEGRO_BITMAP *image);
		void draw(); //TODO: make this.
};

#endif POWERUP_H
//*/
