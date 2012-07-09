#pragma once
#include "Classes.h"

class Player : public GameObject
{
	private:
		Score score; // each player has their own score 
		//Bullet (Stronger mario has bullet, might put bullet in state class), depends or make a different SuperPlayer class
		// Animation class needed?? 
		int lives; // number of lives

	public: 
		// Constructor (automatically calls parent's no-argument constructor by default) 
		Player();
		Player(int x, int y, int velX, int velY, int dirX, int dirY, ALLEGRO_BITMAP *image, State state, Collision col, bool alive,
			bool render, int lives);

		// Methods
		void takeLife (int i); // Minus lives by i
		void addLife (int i); // Add lives by i
};

