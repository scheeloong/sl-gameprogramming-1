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
		void moveLeft() {facing = WALKLEFT; x -= velX;}
		void moveRight() {facing = WALKRIGHT; x += velX;}
		// Changes curFrame to the last frame at index 3 (JUMPMODE)
		void jumpGlide() {curFrame = JUMPMODE;}
		void resetAnimation() {curFrame = 0;}

		// Methods
		int getLife() {return lives;}
		void takeLife (int i); // Minus lives by i
		void addLife (int i); // Add lives by i

		void update();
		void draw();
		void destroy() {al_destroy_bitmap(image);}
};

#endif PLAYER_H
//*/