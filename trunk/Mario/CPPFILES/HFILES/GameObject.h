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
	int species;

	// DO NOT CHANGE:
		// int TYPE to float for position and velocity.
		// WILL CAUSE CRASH in Collision class

	// Positions
	int x; 
	int y; 
	// Velocities
	int velX; 
	int velY;
	// Direction of Movement (ABSOLUTELY USELESS) // CL:why?
	int dirX; 
	int dirY; 
	// Alive and Draw  //(currently unused)
	ALLEGRO_BITMAP *image; 
	bool alive; 
	bool render; 
	bool collidable; // applies specifically to inter-object collidability only and not tiles.
	int anchorX; // marks the original X position of the object, which is used
				 // as a comparison for moving it a certain distance before collidable is reset
	// Animations
	int maxFrame;
	int curFrame;
	int frameCount;
	int frameDelay;
	int frameWidth;
	int frameHeight;
	int animationColumns;
	// Unused by Player class atm.
	int animationDirection;

	// animationRow only needed for gridded sprite sheets
	// not single row
	int animationRow;
	int rewind;
	int facing; // Direction the sprite is facing
	int gravity;
	bool onAir;
	// Refer to Timer::isItFlying(object)
	int halffire;

public:
	//===================
	// Constructors
	//===================
	GameObject();

	// This Init function is expected to be called ONCE for each GameObject, so some parameters 
	// might never need to be updated. (state, col..?)
	void Init(int ID, int x, int y, int velX, int velY, int dirX, int dirY, bool alive, ALLEGRO_BITMAP *image); 

	//===================
	// Set & Get
	//===================
	void setID(int id) { ID = id; } 
	int getID() {return ID;}
	int getSpecies() {return species;}
	void setSpecies(int species) {GameObject::species = species;}
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
	void setCollidable(bool collidable) {GameObject::collidable = collidable;}
	bool getCollidable(){return collidable;}
	void setAnchorX(int anchorX) {GameObject::anchorX = anchorX;}
	int getAnchorX() {return anchorX;}
	ALLEGRO_BITMAP *getImage() {return image;}
	void setImage(ALLEGRO_BITMAP *im) { image = im; }
	void setAnimationRow(int animationRow) {GameObject::animationRow = animationRow;}

	//===================
	// Methods
	//===================
	// TODO: determine if we need a cap for this.
	void incrementAnimationRow()
	{
		if(animationRow <= 2)
			animationRow++;
	}
	// tries to decrement animationRow, returns true upon success.
	// Becomes false if we try demoting baby mario.
	bool decrementAnimationRow() 
	{
		if(animationRow <= 0) 
			return false; 
		else 
		{
			animationRow--; 
			return true;
		}
	}
	bool getonAir() {return onAir;}
	void setonAir(bool onAir) {GameObject::onAir = onAir;}
	int getfacing() {return facing;}
	void setfacing(int facing) {GameObject::facing = facing;}
	bool gethalffire() {return halffire;}
	void sethalffire(int halffire) {GameObject::halffire = halffire;}
	/*void setSpecies(int spec) {species = spec;}
	int getSpecies() {return species;}*/
	
	//===================================
	// Movement Of Object
	//===================================
	//since velY fluxes between + and - values, and the objects 
	//can't normally move down, this function is sufficient
	void moveVertically() {y += velY;}
	void moveDown() {y -= velY;} //unused atm.

	//facing lets the object know which way it is facing, so
	//draw will use the ALLEGRO REFLECT flag as necessary (see Player::draw())
	void moveLeft() {x -= velX;}
	void moveRight() {x += velX;}
	void accelerate() {velY += gravity;}

	// This function checks if the object has moved a certain
	// distance away from an anchor point.
	bool checkAnchorXDistance(int radius)
	{
		return (x - anchorX >= radius || x - anchorX <= -1*radius);
	}
	//TODO: modify this to accommodate for velX reverses as well (for enemies)
	void reverseDirection() 
	{
		//This will be called for the player when they hit something overhead.
		if(getID() == PLAYER)
			if(getonAir() && velY <= 0) {velY = 0; moveVertically();}
		if(getID() == ENEMY || getID() == POWERUP)
		{
			// setfacing to the opposite. ie. WALKRIGHT to WALKLEFT and vice versa
			velX *= -1;
			setfacing(getfacing() * -1);
			animationDirection *= -1;
		}
	}

	void setToGroundLevel(int y)
	{
		setVelY(0);
		setY(y);
	}

	virtual void update() //;
	{
	}

	virtual void resetAnimation() {}
	virtual void draw() {}
	//The next 2 are only for Class Player.
	virtual void startLeap() {}
	virtual void jumpGlide() {}
	virtual void destroy() {}
	
	//===================
	// Friend Class
	//===================
//	friend class Collision; // Allow collision class to access private members of GameObject's data
}; 

#endif GAMEOBJECT_H