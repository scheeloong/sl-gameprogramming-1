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

public:
		
		// Constructor
	//Collision() : boundX(0), boundY(0) {}
	Collision(Player *player)  
	{
		Collision::player = player;
		insertObjectBounds(PLAYER, 13, 25);
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

	//TODO: modify parameter to pass in three lists.
	void checkTileCollision()
	{
		float x = player->getX();
		float y = player->getY();

		int bx = boundX[player->getID()];
		int by = boundY[player->getID()];

		//Check 4 corners of object1's bound box.
		
		//Underfeet check
		if (!isTileCollidable(x, y + by)) {lock[DOWN] = false; onAir = true;}
		else {lock[DOWN] = true; onAir = false; player->setVelY(0); player->resetAnimation();}
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