#ifndef PLAYER_H
#define PLAYER_H
//#pragma once
#include "HFILES/Classes.h"
//#include "HFILES/Collision.h"
#include "HFILES/GameObject.h"
#include "HFILES/State.h"

class Player : public GameObject
{

	private:
		State *state; // Use this to manipulate game state to GameOver etc.
		int lives; // number of TOTAL lives, has nothing to do with Mario's size.
		int maxSpeed; // maxSpeed is for when player jumps up. Therefore is negative.
		int score; // coin collection and enemy farming.
		int isTransforming; // ranges between 0 and 4.
	public: 
		// Constructor (automatically calls parent's no-argument constructor by default) 
		Player() : GameObject()
		{
			ID = PLAYER; 
			species = BABY; 
			lives = 3; 
			maxSpeed = -12; 
			score = 0;
			isTransforming = 0;
		}
		
		// The Init function CANNOT be a constructor because the ALLEGRO_BITMAP *image is not 
		// initialized when the constructor is called. This must be called after the object is constructed.
		// This function also initializes the animation data.
		void Init(State *state, int x, int y, int velX, int velY, int dirX, int dirY, bool alive, ALLEGRO_BITMAP *image);
		
		// Animation Helpers
		// Changes curFrame to the last frame at index 3 (JUMPMODE)
		void jumpGlide() {curFrame = JUMPMODE;}
		void crouch() {curFrame = CROUCH;}
		void resetAnimation() {if(curFrame == JUMPMODE || curFrame == CROUCH || (!keys[RIGHT] && !keys[LEFT])) curFrame = 0;}

		void moveLeft() {GameObject::moveLeft(); setfacing(WALKLEFT);}
		void moveRight() {GameObject::moveRight(); setfacing(WALKRIGHT);}

		// Methods
		int getLife() {return lives;}
		void incrementLife ();
		void decrementLife ();
		void promotePlayer() {incrementAnimationRow(); species++;}
		void demotePlayer() 
		{
			if(!decrementAnimationRow())
			{
				state->setState(GAMEOVER);
			}
			else
				species--;
		}
		
		int getIsTransforming(){return isTransforming;}
		void addScore(int ID_Harvested);
		int getScore() {return score;}
		void startLeap();
		/*void setToGroundLevel(int height)
		{
			if(species == BABY)
				GameObject::setToGroundLevel(height);
			else if(species == RED || species == WHITE)
				GameObject::setToGroundLevel(height);
		}*/
		void update();
		void draw();
		void destroy() {}
};

#endif PLAYER_H
//*/