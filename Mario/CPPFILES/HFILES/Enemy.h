#pragma once
#include "Classes.h"
#include "HFILES/GameObject.h"

class Enemy : public GameObject
{/*
	private:
		int lives; // BOSS ENEMY has > 1 life
	public:
		// Constructor
		Enemy(); // normal enemy has 1 live only 
		Enemy(int lives); // Boss enemy has >1 live 

		Enemy(int x, int y, int velX, int velY, int dirX, int dirY, ALLEGRO_BITMAP *image, State state, Collision col, bool alive,
			bool render, int lives); 


		// Methods
		void takeLife(int i); // Minus i from lives
		void addLife(int i); // add i to lives (may not be needed) */
};

