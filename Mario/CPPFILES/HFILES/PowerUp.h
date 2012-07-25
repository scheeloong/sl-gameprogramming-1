// This class deals with PowerUps

#ifndef POWERUP_H
#define POWERUP_H
//#pragma once

#include "HFILES/Classes.h"
#include "HFILES/GameObject.h"

class PowerUp : public GameObject
{
	private:


	public:
		// Constructors
		PowerUp(); 
		PowerUp(int x, int y, int velX, int velY, int dirX, int dirY, ALLEGRO_BITMAP *image, bool alive,
		bool render);
		void update(); //TODO: make this.
		void Init(); // Initialize powerup based on position and type
		// Methods
};

#endif POWERUP_H
//*/
