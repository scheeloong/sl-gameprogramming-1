#ifndef ENEMY_H
#define ENEMY_H
//#pragma once

#include "HFILES/Classes.h"
#include "HFILES/GameObject.h"

class Enemy : public GameObject
{
	private:
		int lives; // BOSS ENEMY has > 1 life
		int species;
	public:
		// Constructor
		Enemy() : GameObject() {ID = ENEMY; lives = 1; species = GOOMBA; facing = WALKLEFT;} // normal enemy has 1 live only, WALKLEFT because it does so by default.
		Enemy(int lives); // Boss enemy has >1 live 
		void Init(int x, int y, int velX, int velY, int dirX, int dirY, bool alive, ALLEGRO_BITMAP *image)
		{GameObject::Init(x, y, velX, velY, dirX, dirY, alive, image);}
		void InitImage(ALLEGRO_BITMAP *image) {setImage(image);}
		/*void Init(int x, int y, int velX, int velY, int dirX, int dirY, ALLEGRO_BITMAP *image, State state, Collision col, bool alive,
			bool render, int lives); */
		void update();
		void destroy() {setAlive(false);}
		// Methods
		void takeLife(int i); // Minus i from lives
		void addLife(int i); // add i to lives (may not be needed) 
};
#endif ENEMY_H
//*/

