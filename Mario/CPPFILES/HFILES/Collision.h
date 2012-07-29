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
	int playerBoundX[10];
	int playerBoundY[10];
	int enemyBoundX[10];
	int enemyBoundY[10];
	int powerUpBoundX[10];
	int powerUpBoundY[10];
	// counter is obscelete?
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
	void checkPlayerPowerUpCollision();


	void checkCollision()
	{
		checkPlayerTileCollision();
		checkEnemyTileCollision();
		checkPowerUpTileCollision();
		checkPlayerEnemyCollision();
		checkPlayerPowerUpCollision();
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

	inline bool isGoombaTriggerTile(int x, int y)
	{
		BLKSTR *blockdata;
		blockdata = MapGetBlock(x/mapblockwidth, y/mapblockheight); 
		return blockdata->user3;
	}
	inline bool isKoopaTroopaTriggerTile(int x, int y)
	{
		BLKSTR *blockdata;
		blockdata = MapGetBlock(x/mapblockwidth, y/mapblockheight); 
		return blockdata->user4;
	}
	inline void killGoombaTriggerTile(int x, int y)
	{
		BLKSTR *blockdata;
		blockdata = MapGetBlock(x/mapblockwidth, y/mapblockheight); 
		blockdata->user3 = 0;
	}
	inline void killKoopaTroopaTriggerTile(int x, int y)
	{
		BLKSTR *blockdata;
		blockdata = MapGetBlock(x/mapblockwidth, y/mapblockheight); 
		blockdata->user4 = 0;
	}
	// Replaces a special tile with a solid collidable tile.
	inline void killSpecialTile(int x, int y)
	{
		// Tile #423 is a special replacement tile with User7 set as true.
		// It is only activated when a block is currently being pushed from below.
		MapSetBlock(x/mapblockwidth, y/mapblockheight, 423); 
	}

	// Replaces a tile with sky tile
	inline void vapourizeTile(int x, int y)
	{
		MapSetBlock(x/mapblockwidth, y/mapblockheight, 10);
	}
};

#endif