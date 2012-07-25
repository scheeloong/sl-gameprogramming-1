// This class deals with collisions
#ifndef COLLISION_H
#define COLLISION_H
//#pragma once
//#include "HFILES/Player.h" // include player cause no idea how pragma once works, it did not allow collision to re-include GameObject
#include "Classes.h"
#include "GameObject.h"
#include "Player.h"
#include "Autobot.h"
#include "Database.h"


class Collision
{
private:
	//Change this to include all types of creatures.
	vector<int> playerBoundX;
	vector<int> playerBoundY;
	vector<int> enemyBoundX;
	vector<int> enemyBoundY;
	vector<int> powerUpBoundX;
	vector<int> powerUpBoundY;
	vector<int>::iterator iterX;
	vector<int>::iterator iterY;
	int counter;
	Database *database;

public:
		
		// Constructor
	//Collision() : boundX(0), boundY(0) {}
	Collision(Database *database);
	void insertObjectBounds(int ID, int species, int boundX, int boundY);
	void updateBounds(GameObject GameObject);

	void checkPlayerTileCollision();
	void checkEnemyTileCollision();
	void checkPowerUpTileCollision();
	void checkPlayerEnemyCollision();

	void checkCollision()
	{
		checkPlayerTileCollision();
		checkEnemyTileCollision();
		checkPowerUpTileCollision();
		checkPlayerEnemyCollision();
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
	
	inline bool isTileBouncing(int x, int y)
	{
		BLKSTR *blockdata;
		blockdata = MapGetBlock(x/mapblockwidth, y/mapblockheight); 
		return blockdata->user7;
	}

	inline bool isTileDeath(int x, int y)
	{
		// user6 is death 
		BLKSTR *blockdata;
		blockdata = MapGetBlock(x/mapblockwidth, y/mapblockheight); 
		return blockdata->user6;
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
	// Replaces a special tile with a solid collidable tile.
	inline void killSpecialTile(int x, int y)
	{
		// Tile #423 is a special replacement tile with User7 set as true.
		// It is only activated when a block is currently being pushed from below.
		MapSetBlock(x/mapblockwidth, y/mapblockheight, 423); 
	}
};

#endif