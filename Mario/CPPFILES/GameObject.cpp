#include "HFILES/GameObject.h"
#include <stdlib.h> // for NULL
#include "HFILES/State.h"
#include "HFILES/Collision.h"

// Defining Methods
GameObject::GameObject()
{
	x = 0, y = 0; 
	velX = 0, velY = 0;
	dirX = 0, dirY = 0; 
	alive = true; 
	render = true; 
	collidable = false; 
	State::State(); // call State's class default constructor which initializes to normal
	Collision::Collision();
	image = NULL; 
}

// Initializing
void GameObject::Init(int x, int y, int velX, int velY, int dirX, int dirY, ALLEGRO_BITMAP *image, /*State state, Collision col,*/
		bool alive, bool render)
{
	setX(x); 
	setY(y); 
	setVelX(velX); 
	setVelY(velY); 
	setDirX(dirX); 
	setDirY(dirY); 
	setImage(image);  
	//state; 
	//col; 
	setAlive(alive); 
	setRender(render); 
}

/*
bool GameObject::checkCollision(GameObject *object2) 
{
	return col.superCheckCollision(this, object2); 
}
*/