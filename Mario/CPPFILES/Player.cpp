#include "Player.h"
// Constructor
Player::Player() : score(), lives(3) {}

// Methods
void Player::takeLife (int i)
{
	lives -= i; 
}

void Player::addLife (int i)
{
	lives += i; 
}

Player::Player(int x, int y, int velX, int velY, int dirX, int dirY, ALLEGRO_BITMAP *image, State state, Collision col, bool alive,
		bool render, int lives)
{
		GameObject::Init( x, y, velX, velY, dirX, dirY, image, state, col, alive, render); 
		score; // initializes to 0.  
		this->lives = 0; 
		addLife(lives); 
}


