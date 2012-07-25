#include "HFILES/GameObject.h"
// Defining Methods
GameObject::GameObject()
{
	x = 0, y = 0; 
	velX = 10, velY = 0;
	dirX = 0, dirY = 0; 
	alive = false; 
	render = true; 
	collidable = true; 
//	State::State(); // call State's class default constructor which initializes to normal
//	Collision::Collision();
	image = NULL;

	//positive for going down
	gravity = 1;
	halffire = 0;
	
}

// Initializing
void GameObject::Init(int x, int y, int velX, int velY, int dirX, int dirY, bool alive, ALLEGRO_BITMAP *image/*, State state, Collision col,*/)
{
	setX(x); 
	setY(y); 
	setVelX(velX); 
	setVelY(velY); 
	setDirX(dirX); 
	setDirY(dirY);
	setAlive(alive);
	//check if the image is true. setImage only if image exists.
	if(image)
		setImage(image);  
	//state; 
	//col; 
	//setAlive(alive); 
	//setRender(render); 
}

/*
bool GameObject::checkCollision(GameObject *object2) 
{
	return col.superCheckCollision(this, object2); 
}
*/