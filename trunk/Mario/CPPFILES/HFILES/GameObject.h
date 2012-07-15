#pragma once
#include "HFILES/Classes.h"
#include "HFILES/State.h"
#include "HFILES/Collision.h"
//#include <stdlib.h> // for NULL (might not be needed since defined in Classes.h
class GameObject 
{
protected: 
	// Type of Game Object
	int ID; 
	int species;
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

	// State
	//State state; 
	// Collision
//	Collision col; 
	bool collidable; // if it is collidable, set collidable to true

	// Alive and Draw? 
	bool alive; 
	bool render; 

	/*
	// Animations
	int maxFrame;
	int curFrame;
	int frameCount;
	int frameDelay;
	int frameWidth;
	int frameHeight;
	int animationColumns;
	int animationDirection;
	*/

public:
	// Constructor
	GameObject();

	// Method for constructor (more specific) 
	void Init(int x, int y, int velX, int velY, int dirX, int dirY, ALLEGRO_BITMAP *image, /*State state, Collision col,*/
		 bool alive, bool render); 

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
	void setSpecies(int spec) {species = spec;}
	int getSpecies() {return species;}

	// Methods
	bool checkCollision(GameObject *object2);   // Returns true if there is collision

	virtual void update(); // update GameObject's position, vel, dir, image etc..
		// Virtual cause different objects have different update methods
	// Destructor (will need to handle in some special way due to multiple inheritance) 
	
	// Friend Class
	friend class Collision; // Allow collision class to access private members of GameObject's data
}; 

