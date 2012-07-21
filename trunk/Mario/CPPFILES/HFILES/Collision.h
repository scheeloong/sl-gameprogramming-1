// This class deals with collisions
#ifndef COLLISION_H
#define COLLISION_H
//#pragma once
//#include "HFILES/Player.h" // include player cause no idea how pragma once works, it did not allow collision to re-include GameObject
#include "Classes.h"
#include "GameObject.h"
#include "Player.h"
#include "Enemy.h"
#include "Database.h"


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
	Database *database;

public:
		
		// Constructor
	//Collision() : boundX(0), boundY(0) {}
	Collision(Database *database);
	void insertObjectBounds(int ID, int boundX, int boundY);
	void updateBounds(GameObject GameObject);
	void checkCollision();
	void checkEnemyTileCollision();
	void checkPlayerTileCollision();
	void checkPlayerEnemyCollision();
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

	inline bool isTriggerTile(int x, int y)
	{
		BLKSTR *blockdata;
		blockdata = MapGetBlock(x/mapblockwidth, y/mapblockheight); 
		return blockdata->user3;
	}
	inline void killTriggerTile(int x, int y)
	{
		BLKSTR *blockdata;
		blockdata = MapGetBlock(x/mapblockwidth, y/mapblockheight); 
		blockdata->user3 = 0;
	}
};

#endif