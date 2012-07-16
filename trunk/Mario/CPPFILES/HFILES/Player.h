#ifndef PLAYER_H
#define PLAYER_H
//#pragma once
#include "HFILES/Classes.h"
#include "HFILES/GameObject.h"

class Player : public GameObject
{
	private:
		//Score score; // each player has their own score 
		//Bullet (Stronger mario has bullet, might put bullet in state class), depends or make a different SuperPlayer class
		// Animation class needed?? 
		//int lives; // number of lives

	public: 
		// Constructor (automatically calls parent's no-argument constructor by default) 
		Player() : GameObject(){x = 0;}
		Player(int x, int y, int velX, int velY, int dirX, int dirY, /*ALLEGRO_BITMAP *image, State state, Collision col,*/  bool alive,
		bool render, int lives);

		// TEMPORARY CONSTRUCTOR
		//Player() : lives(3) {}; 

		void moveUp() {setY(y -= velY);};
		void moveDown() {setY(y += velY);};
		void moveLeft() {setX(x -= velX);};
		void moveRight() {setX(x += velX);}; 

		// Methods
		//int getLife() {return lives;};
		void takeLife (int i); // Minus lives by i
		void addLife (int i); // Add lives by i

		 void update();
};

#endif PLAYER_H
//*/