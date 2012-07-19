#ifndef PLAYER_H
#define PLAYER_H
//#pragma once
#include "HFILES/Classes.h"
//#include "HFILES/Collision.h"
#include "HFILES/GameObject.h"

class Player : public GameObject
{

	private:
		int lives; // number of lives
		//maxSpeed is for when player jumps up. Therefore is negative.
		int maxSpeed;
	public: 
		// Constructor (automatically calls parent's no-argument constructor by default) 
		Player() : GameObject() {ID = PLAYER; lives = 3; maxSpeed = -12;}
		
		// The Init function CANNOT be a constructor because the ALLEGRO_BITMAP *image is not 
		// initialized when the constructor is called. This must be called after the object is constructed.
		// This function also initializes the animation data.
		void Init(int x, int y, int velX, int velY, int dirX, int dirY, bool alive, ALLEGRO_BITMAP *image);
		
		// Animation Helpers
		// Changes curFrame to the last frame at index 3 (JUMPMODE)
		void jumpGlide() {curFrame = JUMPMODE;}
		void resetAnimation() {curFrame = 0;}

		void moveLeft() {GameObject::moveLeft(); setfacing(WALKLEFT);}
		void moveRight() {GameObject::moveRight(); setfacing(WALKRIGHT);}

		// Methods
		int getLife() {return lives;}
		void takeLife (int i); // Minus lives by i
		void addLife (int i); // Add lives by i
		void startLeap();
		void update();
		void draw();
		void destroy() {al_destroy_bitmap(image);}
};

#endif PLAYER_H
//*/