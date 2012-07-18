// This class deals with collisions
#ifndef COLLISION_H
#define COLLISION_H
//#pragma once
//#include "HFILES/Player.h" // include player cause no idea how pragma once works, it did not allow collision to re-include GameObject
#include "Classes.h"
#include "GameObject.h"
#include "Player.h"


class Collision
{
/*// TEMPORARY (start)
private:
	int i;
public:
	Collision() : i(0) {}

//bool superCheckCollision(GameObject &object1, GameObject &object2); // may need to change to &object1 , &object2
// TEMPORARY (end)*/

//TODO: give this class 3 pointers to the 3 database arrays.

private:
	//Change this to include all types of creatures.
	vector<int> boundX;
	vector<int> boundY;
	Player *player;
	Enemy *enemy;

public:
		
		// Constructor
	//Collision() : boundX(0), boundY(0) {}
	Collision(Player *player, Enemy *enemy)  
	{
		Collision::player = player;
		Collision::enemy = enemy;
		insertObjectBounds(PLAYER, 13, 23);
		// Enemy only refers to Goomba as of now.
		insertObjectBounds(ENEMY, 22, 27);
	}

	//Adds new GameObject bounds to the two vectors. 
	//The ID is just a stub, so you see what you're adding.
	//It's not used in the function at all. The ID should be 
	// the index of the added bounds.
	void insertObjectBounds(int ID, int boundX, int boundY)
	{
		Collision::boundX.push_back(boundX);
		Collision::boundY.push_back(boundY);
	}

	// Methods
	void updateBounds(GameObject GameObject)
	{
		// May need to check somewhere the type of GameObject, can use dynamic cast or simple ID to check
		//boundX = meObject.x + 20; 
		//boundY = GameObject.y + 20; 
	}

	//This function gets called in the big while loop. It sums up all of class Collision.
	void checkCollision()
	{
		checkTileCollision(player);
		checkTileCollision(enemy);
	}

	void checkTileCollision(Enemy *enemy)
	{
		float x = enemy->getX();
		float y = enemy->getY();

		int bx = boundX[enemy->getID()];
		int by = boundY[enemy->getID()];

		//Underfeet check. Due to some strange logic, we first have to check if it's onAir,
		//if not then check if it's on the ground. 
		if (!isTileCollidable(x, y + by)) {enemy->setonAir(true);}
		//reset animation isn't extremely important here.
		else {enemy->setonAir(false); enemy->setVelY(0); enemy->resetAnimation();}
		//Overhead check - won't really happen with enemies
		if (isTileCollidable(x, y - by)) {}
		//Rightside check. Only reverseDirection if the dude is currently TRYING TO WALKRIGHT && hitting a tile on the right!
		if (isTileCollidable(x + bx, y) && enemy->getfacing() == WALKRIGHT) 
			enemy->reverseDirection(); 
	
		//Leftside check. Only reverseDirection if the dude is currently TRYING TO WALKLEFT && hitting a tile on the left!
		if (isTileCollidable(x - bx, y) && enemy->getfacing() == WALKLEFT) 
			enemy->reverseDirection(); 
	}
	void checkTileCollision(Player *player)
	{
		float x = player->getX();
		float y = player->getY();

		int bx = boundX[player->getID()];
		int by = boundY[player->getID()];

		//If Mario jumps above the visible screen, tile collisions won't be checked.
		if(y > 0)
		//Check 4 corners of object1's bound box.
		//Underfeet check
		{
			if (!isTileCollidable(x, y + by)) {lock[DOWN] = false; player->setonAir(true);}
			else {lock[DOWN] = true; player->setonAir(false); player->setVelY(0); player->resetAnimation();}
			//Overhead check
			if (isTileCollidable(x, y - by)) {lock[UP] = true; player->reverseDirection();}
			else lock[UP] = false;
			//Rightside check
			if (isTileCollidable(x + bx, y)) lock[RIGHT] = true;
			else lock[RIGHT] = false;
			//Leftside check
			if (isTileCollidable(x - bx, y)) lock[LEFT] = true;
			else lock[LEFT] = false;

			//TODO: modify to check every side of body.
			if(isTileSpecial(x, y))
			{
				if(isQuestionTile(x, y))
				{
					//do stuff
				}
				else if(isCoinTile(x, y))
				{
					//do stuff
				}
				else if(isBrickTile(x, y))
				{
					//do stuff
		
				}
			}
		}
	}
	inline bool isTileCollidable(int x, int y)
	{
		BLKSTR *blockdata;
		blockdata = MapGetBlock(x/mapblockwidth, y/mapblockheight); 
		return blockdata->user1;
	}

	inline bool isTileSpecial(int x, int y)
	{
		BLKSTR *blockdata;
		blockdata = MapGetBlock(x/mapblockwidth, y/mapblockheight); 
		return blockdata->user2;
	}

	inline bool isQuestionTile(int x, int y)
	{
		BLKSTR *blockdata;
		blockdata = MapGetBlock(x/mapblockwidth, y/mapblockheight); 
		return blockdata->tl;
	}

	inline bool isCoinTile(int x, int y)
	{
		BLKSTR *blockdata;
		blockdata = MapGetBlock(x/mapblockwidth, y/mapblockheight); 
		return blockdata->br;
	}

	inline bool isBrickTile(int x, int y)
	{
		BLKSTR *blockdata;
		blockdata = MapGetBlock(x/mapblockwidth, y/mapblockheight); 
		return blockdata->tr;
	}
};

#endif