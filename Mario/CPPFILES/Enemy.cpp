#include "Enemy.h"

Enemy::Enemy() : GameObject::GameObject(), lives(1) {}; // normal enemy has 1 live only 
Enemy::Enemy(int lives) : GameObject::GameObject(), lives(lives) {}; // Boss enemy has >1 live 

// Methods
// Minus i from lives
void Enemy::takeLife(int i)
{
	lives -= i; 
}

void Enemy::addLife(int i) // add i to lives (may not be needed) 
{
	lives += i; 
}

Enemy::Enemy(int x, int y, int velX, int velY, int dirX, int dirY, ALLEGRO_BITMAP *image, State state,
	Collision col, bool alive,bool render, int lives)
{
	// call parent constructor
	 GameObject::Init( x, y, velX, velY, dirX, dirY, image, state, col, alive, render); 
	 // set lives
	 this->lives = 0;
	 addLife(lives); 
}