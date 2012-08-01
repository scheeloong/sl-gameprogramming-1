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
	// VL: I'd like the functions below to be encapsulated inside a single function,
	// so a single call can be made inside each collision class member.
	// But this is tricky because it's all custom, which tiles need checking for 
	// what collision check. TODO as of now.

	//==================
	// Guide
	// =================
	//  User1 - collidable
	//	User2 - special
	//	User3 - trigger *** Layer 1 perhaps? Goomba
	//	User4 - trigger Koopa Troopa
	//	User5 -
	//	User6 - death
	//	User7 - bouncing

	//	TL - question
	//	BR - coin
	//	TR - brick    
	//===================

	// All functions below return true if the Tile is X, false if not.
	// where X is special, bouncing, death, etc.
	// This function checks if a tile has special powers.
	inline bool isTileSpecial(int x, int y)
	{
		BLKSTR *blockdata;
		blockdata = MapGetBlock(x/mapblockwidth, y/mapblockheight); 
		return blockdata->user2;
	}
	
	// This function checks if a tile is currently bouncing.
	inline bool isTileBouncing(int x, int y)
	{
		BLKSTR *blockdata;
		blockdata = MapGetBlock(x/mapblockwidth, y/mapblockheight); 
		return blockdata->user7;
	}

	// This function checks if the tile is a killer (ie. inside a pit)
	inline bool isTileDeath(int x, int y)
	{
		// user6 is death 
		BLKSTR *blockdata;
		blockdata = MapGetBlock(x/mapblockwidth, y/mapblockheight); 
		return blockdata->user6;
	}

	// This function checks if tile is a Question mark gold tile.
	inline bool isQuestionTile(int x, int y)
	{
		BLKSTR *blockdata;
		blockdata = MapGetBlock(x/mapblockwidth, y/mapblockheight); 
		return blockdata->tl;
	}

	// This function checks if the tile is a coin.
	inline bool isCoinTile(int x, int y)
	{
		BLKSTR *blockdata;
		blockdata = MapGetBlock(x/mapblockwidth, y/mapblockheight); 
		return blockdata->br;
	}

	// This function checks if the tile is an overhead brick.
	inline bool isBrickTile(int x, int y)
	{
		BLKSTR *blockdata;
		blockdata = MapGetBlock(x/mapblockwidth, y/mapblockheight); 
		return blockdata->tr;
	}

	//------------------------------------------------------------------------------------------
	// Trigger Tiles

	// This function checks if the tile triggers a Goomba.
	inline bool isGoombaTriggerTile(int x, int y)
	{
		BLKSTR *blockdata;
		blockdata = MapGetBlock(x/mapblockwidth, y/mapblockheight); 
		return blockdata->user3;
	}

	// This function checks if the tile triggers a Koopa Troopa.
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

	// This function replaces an entire column of tiles (same x coordinate, different y coordinate)
	// with sky tiles. Primary application, get rid of all trigger tiles in the vertical column.
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