// This class stores all the game objects in a linked list. 

#ifndef DATABASE_H 
#define DATABASE_H
//#pragma once

#include "HFILES/Classes.h"
#include "HFILES/GameObject.h"
#include "HFILES/PowerUp.h"
#include "HFILES/Player.h"
#include "HFILES/Autobot.h"
#include "HFILES/Goomba.h"
#include "HFILES/BounceBlock.h"

class Database
{
	private:
		// Create generic double linked list of GameObjects used
		// using type GameObject * because it's more general. For destroy list.
		list<Player *> players; // create a double linked list of players 
		list<Autobot *> enemies; 
		list<PowerUp *> powerUps; 
		list<BounceBlock *> bounceBlocks;

		// Seperator iterators for cleaner code

		ALLEGRO_BITMAP *BabyMario;
		ALLEGRO_BITMAP *GoombaPic;
		ALLEGRO_BITMAP *deadQuestion;
		ALLEGRO_BITMAP *sky;
		ALLEGRO_BITMAP *deadBrick;

	public:
		// Constructors
		Database(); 
		void InitImages(ALLEGRO_BITMAP *BabyMario, ALLEGRO_BITMAP *Goomba, ALLEGRO_BITMAP *deadQuestion, ALLEGRO_BITMAP *sky, ALLEGRO_BITMAP *deadBrick);
		//These don't modify the lists on their own, so safer and more convenient to be public.
		list<Player *>::iterator iterP; 
		list<Autobot *>::iterator iterE; 
		list<PowerUp *>::iterator iterPU; 
		list<BounceBlock *>::iterator iterB;

		list<Player *>::iterator getPlayersBegin() {return players.begin();}
		list<Autobot *>::iterator getEnemiesBegin() {return enemies.begin();}
		list<PowerUp *>::iterator getPowerUpsBegin() {return powerUps.begin();}
		list<BounceBlock *>::iterator getBounceBlocksBegin() {return bounceBlocks.begin();}
		list<Player *>::iterator getPlayersEnd() {return players.end();}
		list<Autobot *>::iterator getEnemiesEnd() {return enemies.end();}
		list<PowerUp *>::iterator getPowerUpsEnd() {return powerUps.end();}
		list<BounceBlock *>::iterator getBounceBlocksEnd() {return bounceBlocks.end();}
		int getEnemiesSize() {return ((int) enemies.size());}

		// Methods
		void makePlayer(int x, int y, int velX, int velY, int dirX, int dirY, bool alive);  
		//we need makeGoomba, makeTurtle, etcetc
		void makeEnemy(int species, int x, int y, int velX, int velY, int dirX, int dirY, bool alive); 
	//	void makePowerUps(); 
		void makeBounceBlock(int species, int x, int y, int velX, int velY, int dirX, int dirY, bool alive);

		void updatePlayerList();
		void updateEnemyList();
		// void updatePowerUpList();
		void updateBounceBlockList();
		void update()
		{
			updatePlayerList();
			updateEnemyList();
			// updatePowerUpList();
			updateBounceBlockList();
		}
		
		//is there a better way to do this? I can't convert list<Player *> to list<GameObject *>

		void drawPlayerList();
		void drawEnemyList();
		void drawPowerUpList();
		void drawBounceBlockList();
		void draw()
		{
			drawBounceBlockList();
			drawPlayerList();
			drawEnemyList();
			//drawPowerUpList();
		}

		void destroyPlayerList();
		void destroyEnemyList();
		void destroyPowerUpList();
		void destroyBounceBlockList();
		void destroy()
		{
			destroyPlayerList();
			destroyEnemyList();
			//destroyPowerUpList(powerUps, iterPU);
			destroyBounceBlockList();
		}
		
		// This function is for RESET purposes, for restarting the game.
		void resetDatabase();
		// This function is for EXITING the game.
		void deleteDatabase();

		// setAlive(false) for every object in players list 
		void killPlayers();
		void killEnemies();
		void killPowerUps();
		void killBounceBlocks();

		// Destroys a specific enemy.
		list<Autobot *>::iterator destroyEnemy(list<Autobot *>::iterator iter); 
	//	void destroyPowerUps(); 
};

#endif DATABASE_H