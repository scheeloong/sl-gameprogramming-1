#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "HFILES/Classes.h"
#include "HFILES/State.h"
//#include "HFILES/Collision.h"
class GameObject 
{
protected: 
	// Type of Game Object
	int ID; 
	// Can't remember why we needed species. Assuming state will handle all this...
	// int species;

	// DO NOT CHANGE int TYPE to float for position and velocity.
	// WILL CAUSE CRASH in Collision class
	// Positions
	int x; 
	int y; 
	// Velocities
	int velX; 
	int velY; 
	// Direction of Movement
	int dirX; 
	int dirY; 
	// Image
	ALLEGRO_BITMAP *image; 

	// State state; 
	// Collision
    // Collision col; 
	bool collidable; // if it is collidable, set collidable to true

	// Alive and Draw, currently unused
	bool alive; 
	bool render; 

	// Animations
	int maxFrame;
	int curFrame;
	int frameCount;
	int frameDelay;
	int frameWidth;
	int frameHeight;
	int animationColumns;
	//Unused by Player class atm.
	int animationDirection;

	//animationRow only needed for gridded sprite sheets
	// not single row
	int animationRow;
	int rewind;
	//Direction the sprite is facing.
	int facing;

	int gravity;

public:
	// Constructor
	GameObject();

	// Method for constructor (more specific) 
	// This Init function is expected to be called ONCE for each GameObject, so some parameters 
	// might never need to be updated. (state, col..?)
	void Init(int x, int y, int velX, int velY, int dirX, int dirY, ALLEGRO_BITMAP *image/*, State state, Collision col,*/); 

	//===============================
	// Set & Get
	//===============================
	void setX(int i) {x = i;}
	void setY(int i) {y = i;}
	int getX() {return x;}
	int getY() {return y;}
	void setVelX(int i) {velX = i;} 
	void setVelY(int i) {velY = i;}
	int getVelX() {return velX;}
	int getVelY() {return velY;}
	void setDirX(int i) { dirX = i;}
	void setDirY(int i) { dirY = i;}
	int getDirX() {return dirX;} 
	int getDirY() {return dirY;}
	void setAlive(bool al) { alive = al; }
	bool getAlive() { return alive; }
	void setRender (bool ren) { render = ren; }
	bool getRender() { return render; }
	void setImage(ALLEGRO_BITMAP *im) { image = im; }
	void setID(int id) { ID = id; } 
	int getID() {return ID;}
	/*void setSpecies(int spec) {species = spec;}
	int getSpecies() {return species;}*/
	
	//===================================
	// Moving the Object
	//===================================
	//since velY fluxes between + and - values, and the objects 
	//can't normally move down, this function is sufficient
	void moveVertically() {y += velY;}
	void moveDown() {y -= velY;} //unused atm.

	//facing lets the object know which way it is facing, so
	//draw will use the ALLEGRO REFLECT flag as necessary (see Player::draw())
	void moveLeft() {facing = WALKLEFT; x -= velX;}
	void moveRight() {facing = WALKRIGHT; x += velX;}
	void accelerate() {velY += gravity;}

	//TODO: modify this to accommodate for velX reverses as well (for enemies)
	void reverseDirection() {if(onAir && velY <= 0) {velY = 0; moveVertically();}}

	bool checkCollision(GameObject *object2);   //unlikely to be used

	virtual void update() //;
	{
		printf("Gameobject Update");
	}

	virtual void draw() {}
	// update GameObject's position, vel, dir, image etc..
	// Virtual cause different objects have different update methods
	// Destructor (will need to handle in some special way due to multiple inheritance) 
	virtual void destroy() {}
	
	// Friend Class
//	friend class Collision; // Allow collision class to access private members of GameObject's data
}; 

#endif GAMEOBJECT_H