#ifndef PLAYER_H
#define PLAYER_H
//#pragma once
#include "HFILES/Classes.h"
#include "HFILES/GameObject.h"

class Player : public GameObject
{
	private:
		int lives; // number of lives
	public: 
		// Constructor (automatically calls parent's no-argument constructor by default) 
		Player();
		Player(int x, int y, int velX, int velY, int dirX, int dirY, ALLEGRO_BITMAP *image, bool alive,
		bool render, int lives);

		void moveUp() {y -= velY;}
		void moveDown() {y += velY;}
		void moveLeft() {setX(x -= velX);}
		void moveRight() {setX(x += velX);}

		// Methods
		int getLife() {return lives;};
		void takeLife (int i); // Minus lives by i
		void addLife (int i); // Add lives by i

		 void update();
};

#endif PLAYER_H
//*/