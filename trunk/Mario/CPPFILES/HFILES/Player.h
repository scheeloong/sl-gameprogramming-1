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
		Player() : GameObject() {ID = PLAYER; lives = 3;}
		// The Init function CANNOT be a constructor because the ALLEGRO_BITMAP *image is not 
		// initialized when the constructor is called. This must be called after the object is constructed.
		void Init(int x, int y, int velX, int velY, int dirX, int dirY, ALLEGRO_BITMAP *image);

		void moveUp() {y -= velY;}
		void moveDown() {y += velY;}
		void moveLeft() {setX(x -= velX);}
		void moveRight() {setX(x += velX);}

		// Methods
		int getLife() {return lives;}
		void takeLife (int i); // Minus lives by i
		void addLife (int i); // Add lives by i

		void update();
		void draw();
};

#endif PLAYER_H
//*/