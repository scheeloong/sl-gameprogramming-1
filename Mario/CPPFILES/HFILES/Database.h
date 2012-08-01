// This class stores all the game objects in a linked list. 

#ifndef DATABASE_H 
#define DATABASE_H
//#pragma once

#include "HFILES/Classes.h"
#include "HFILES/GameObject.h"
#include "HFILES/SuperMushroom.h"
#include "HFILES/Player.h"
#include "HFILES/Autobot.h"
#include "HFILES/Goomba.h"
#include "HFILES/KoopaTroopa.h"
#include "HFILES/BounceBlock.h"
#include "HFILES/State.h"

class Database
{
	private:
		State *state; // This is needed by player.
		// Create generic double linked list of GameObjects used
		// using type GameObject * because it's more general. For destroy list.
		list<Player *> players; // create a double linked list of players 
		list<Autobot *> enemies; 
		list<Autobot *> powerUps; 
		list<BounceBlock *> bounceBlocks;

		// Images
		ALLEGRO_BITMAP *BabyMario;
		ALLEGRO_BITMAP *GoombaPic;
		ALLEGRO_BITMAP *PowerUpsPic;
		ALLEGRO_BITMAP *KoopaTroopaPic;
		ALLEGRO_BITMAP *deadQuestion;
		ALLEGRO_BITMAP *sky;
		ALLEGRO_BITMAP *deadBrick;

		// Private method, not to be called outside this class.
		// CL: You don't have to state it as private, it is understood as it is
		// indented under the private column
		// VL: LOL I don't think I commented that one.
		
		
		// Draw
		void drawPlayerList();
		void drawEnemyList();
		void drawPowerUpList();
		void drawBounceBlockList();

		// Destroy
		void destroyPlayerList();
		void destroyEnemyList();
		void destroyPowerUpList();
		void destroyBounceBlockList();

		// This method cleans up all the linked list in the Database class.
		// To be called by public destroy functions below.
		void destroy()
		{
			destroyPlayerList();
			destroyEnemyList();
			destroyPowerUpList();
			destroyBounceBlockList();
		}

	public:
		//===================
		// Constructors
		//===================
		Database(State *state); 
		void InitImages(ALLEGRO_BITMAP *BabyMario, ALLEGRO_BITMAP *Goomba, ALLEGRO_BITMAP *KoopaTroopa, ALLEGRO_BITMAP *PowerUps,
			            ALLEGRO_BITMAP *deadQuestion, ALLEGRO_BITMAP *sky, ALLEGRO_BITMAP *deadBrick);
		//These don't modify the lists on their own, so safer and more convenient to be public.
		//Separate iterators for cleaner code
		list<Player *>::iterator iterP; 
		list<Autobot *>::iterator iterE; 
		list<Autobot *>::iterator iterPU; 
		list<BounceBlock *>::iterator iterB;
		//====================
		// Get & Set Methods
		//====================
		// (returns first and last objects in the linked list)
		list<Player *>::iterator getPlayersBegin() {return players.begin();}
		list<Autobot *>::iterator getEnemiesBegin() {return enemies.begin();}
		list<Autobot *>::iterator getPowerUpsBegin() {return powerUps.begin();}
		list<BounceBlock *>::iterator getBounceBlocksBegin() {return bounceBlocks.begin();}
		list<Player *>::iterator getPlayersEnd() {return players.end();}
		list<Autobot *>::iterator getEnemiesEnd() {return enemies.end();}
		list<Autobot *>::iterator getPowerUpsEnd() {return powerUps.end();}
		list<BounceBlock *>::iterator getBounceBlocksEnd() {return bounceBlocks.end();}
		int getEnemiesSize() {return ((int) enemies.size());} // returns size of enemy

		//===================
		// Methods
		//===================
		// Create
		void makePlayer(int x, int y, int velX, int velY, int dirX, int dirY, bool alive);  
		void makeEnemy(int species, int x, int y, int velX, int velY, int dirX, int dirY, bool alive); 
		void makePowerUp(int species, int x, int y, int velX, int velY, int dirX, int dirY, bool alive); 
		void makeBounceBlock(int species, int x, int y, int velX, int velY, int dirX, int dirY, bool alive);

		//---------------------------------------------------------------------------------------------------
		// Update
		// VL: I don't know why this must be public. Apparently the next 4 functions must be.
		void updatePlayerList();
		void updateEnemyList();
		void updatePowerUpList();
		void updateBounceBlockList();

		void update()
		{
			updatePlayerList();
			updateEnemyList();
		    updatePowerUpList();
			updateBounceBlockList();
		}

		//---------------------------------------------------------------------------------------------------
		// Draw
		// VL: is there a better way to do this? I can't convert list<Player *> to list<GameObject *>
		void draw()
		{
			drawBounceBlockList();
			drawPlayerList();
			drawEnemyList();
			drawPowerUpList();
		}

		//---------------------------------------------------------------------------------------------------
		
		// This function is for RESET purposes, for restarting the game.
		void resetDatabase();
		// This function is for EXITING the game.
		void deleteDatabase();

		// setAlive(false) for every object in lists 
		void killPlayers();
		void killEnemies();
		void killPowerUps();
		void killBounceBlocks();

		// Destroys a specific enemy.
		list<Autobot *>::iterator destroyEnemy(list<Autobot *>::iterator iter); 
		list<Autobot *>::iterator destroyPowerUp(list<Autobot *>::iterator iter);

		//---------------------------------------------------------------------------------------------------
		// State
		void setState(int state)
		{
			Database::state->setState(state);
		}
};

#endif DATABASE_H