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
	// Methods
	void insertObjectBounds(int ID, int species, int boundX, int boundY);
	void updateBounds(GameObject GameObject);

	//====================
	// Collision Methods
	//====================
	// CL: SHOULD THESE BE PRIVATE METHODS? SINCE (SEE 6 LINES BELOW)
	void checkPlayerTileCollision();
	void checkEnemyTileCollision();
	void checkPowerUpTileCollision();
	void checkPlayerEnemyCollision();
	void checkPlayerPowerUpCollision();
	// THIS METHOD IS THE ONLY METHOD THAT NEEDS TO BE CALLED OUTSIDE THIS CLASS?
	// This function checks the collision among the GameObject classes
	void checkCollision()
	{
		checkPlayerTileCollision();
		checkEnemyTileCollision();
		checkPowerUpTileCollision();
		checkPlayerEnemyCollision();
		checkPlayerPowerUpCollision();
	}

	//====================
	// Tile Methods
	//====================
	// This function ... and returns ...
	inline bool isTileCollidable(int x, int y)
	{
		BLKSTR *blockdata;
		blockdata = MapGetBlock(x/mapblockwidth, y/mapblockheight); 
		return blockdata->user1;
	}

	//------------------------------------------------------------------------------------------
	// Identifying Tiles

	// This function ... and returns ...
	inline bool isTileSpecial(int x, int y)
	{
		BLKSTR *blockdata;
		blockdata = MapGetBlock(x/mapblockwidth, y/mapblockheight); 
		return blockdata->user2;
	}
	
	// This function ... and returns ...
	inline bool isTileBouncing(int x, int y)
	{
		BLKSTR *blockdata;
		blockdata = MapGetBlock(x/mapblockwidth, y/mapblockheight); 
		return blockdata->user7;
	}

	// This function ... and returns ...
	inline bool isTileDeath(int x, int y)
	{
		// user6 is death 
		BLKSTR *blockdata;
		blockdata = MapGetBlock(x/mapblockwidth, y/mapblockheight); 
		return blockdata->user6;
	}

	// This function ... and returns ...
	inline bool isQuestionTile(int x, int y)
	{
		BLKSTR *blockdata;
		blockdata = MapGetBlock(x/mapblockwidth, y/mapblockheight); 
		return blockdata->tl;
	}

	// This function ... and returns ...
	inline bool isCoinTile(int x, int y)
	{
		BLKSTR *blockdata;
		blockdata = MapGetBlock(x/mapblockwidth, y/mapblockheight); 
		return blockdata->br;
	}

	// This function ... and returns ...
	inline bool isBrickTile(int x, int y)
	{
		BLKSTR *blockdata;
		blockdata = MapGetBlock(x/mapblockwidth, y/mapblockheight); 
		return blockdata->tr;
	}

	//------------------------------------------------------------------------------------------
	// Trigger Tiles

	// This function ... and returns ...
	inline bool isGoombaTriggerTile(int x, int y)
	{
		BLKSTR *blockdata;
		blockdata = MapGetBlock(x/mapblockwidth, y/mapblockheight); 
		return blockdata->user3;
	}

	// This function ... and returns ...
	inline bool isKoopaTroopaTriggerTile(int x, int y)
	{
		BLKSTR *blockdata;
		blockdata = MapGetBlock(x/mapblockwidth, y/mapblockheight); 
		return blockdata->user4;
	}

	//------------------------------------------------------------------------------------------
	// These methods deal with getting rid of used Tiles
	
	// This function replaces a special tile with a solid collidable tile.
	inline void killSpecialTile(int x, int y)
	{
		// Tile #423 is a special replacement tile with User7 set as true.
		// It is only activated when a block is currently being pushed from below.
		MapSetBlock(x/mapblockwidth, y/mapblockheight, 423); 
	}

	// This function replaces a tile with the sky tile.
	inline void vapourizeTile(int x, int y)
	{
		MapSetBlock(x/mapblockwidth, y/mapblockheight, 10);
	}

	// This function ...?
	inline void vapourizeTileColumn(int x)
	{
		for(int y = 0; y <= HEIGHT; y+=50)
		{
			if(isGoombaTriggerTile(x, y) || isKoopaTroopaTriggerTile(x, y))
				vapourizeTile(x, y);
		}
	}
};

#endif