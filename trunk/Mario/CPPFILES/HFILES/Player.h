#pragma once
#include "Classes.h"

class Player : public GameObject
{
	private:
		//Score score; // each player has their own score 
		//Bullet (Stronger mario has bullet, might put bullet in state class), depends or make a different SuperPlayer class
		// Animation class needed?? 
		int lives; // number of lives

	public: 
		// Constructor (automatically calls parent's no-argument constructor by default) 
		Player();
		//Player() : score(), lives(3) {};

		void moveUp() {setY(y -= velY);};
		void moveDown() {setY(y += velY);};
		void moveLeft() {setX(x -= velX);};
		void moveRight() {setX(x += velX);}; 

		// Methods
		int getLife() {return lives;};
		void takeLife (int i); // Minus lives by i
		void addLife (int i); // Add lives by i
};