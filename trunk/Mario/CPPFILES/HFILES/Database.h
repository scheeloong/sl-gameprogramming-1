// This class stores all the game objects in a linked list. 

#ifndef DATABASE_H 
#define DATABASE_H
//#pragma once

#include "HFILES/Classes.h"
#include "HFILES/GameObject.h"
#include "HFILES/PowerUp.h"
#include "HFILES/Player.h"
#include "HFILES/Enemy.h"
#include "HFILES/Goomba.h"

class Database
{
	private:
		// Create generic double linked list of GameObjects used
		// using type GameObject * because it's more general. For destroy list.
		list<Player *> players; // create a double linked list of players 
		list<Enemy *> enemies; 
		list<PowerUp *> powerUps; 
	
		// Seperator iterators for cleaner code

		ALLEGRO_BITMAP *BabyMario;
		ALLEGRO_BITMAP *GoombaPic;

	public:
		// Constructors
		Database(); 
		void InitImages(ALLEGRO_BITMAP *BabyMario, ALLEGRO_BITMAP *Goomba);
		//These don't modify the lists on their own, so safer and more convenient to be public.
		list<Player *>::iterator iterP; 
		list<Enemy *>::iterator iterE; 
		list<PowerUp *>::iterator iterPU; 

		list<Player *>::iterator getPlayersBegin() {return players.begin();}
		list<Enemy *>::iterator getEnemiesBegin() {return enemies.begin();}
		list<PowerUp *>::iterator getPowerUpsBegin() {return powerUps.begin();}
		list<Player *>::iterator getPlayersEnd() {return players.end();}
		list<Enemy *>::iterator getEnemiesEnd() {return enemies.end();}
		list<PowerUp *>::iterator getPowerUpsEnd() {return powerUps.end();}
		int getEnemiesSize() {return ((int) enemies.size());}

		// Methods
		void makePlayer(int x, int y, int velX, int velY, int dirX, int dirY, bool alive);  
		//we need makeGoomba, makeTurtle, etcetc
		void makeEnemy(int x, int y, int velX, int velY, int dirX, int dirY, bool alive); 
	//	void makePowerUps(); 

		void updatePlayerList();
		void updateEnemyList();
		// void updatePowerUpList();
		void update()
		{
			updatePlayerList();
			updateEnemyList();
			// updatePowerUpList();
		}
		
		//is there a better way to do this? I can't convert list<Player *> to list<GameObject *>

		void drawPlayerList();
		void drawEnemyList();
		void drawPowerUpList();
		void draw()
		{
			drawPlayerList();
			drawEnemyList();
			//drawPowerUpList();
		}

		void destroyPlayerList();
		void destroyEnemyList();
		void destroyPowerUpList();
		void destroy()
		{
			destroyPlayerList();
			destroyEnemyList();
			//destroyPowerUpList(powerUps, iterPU);
		}
		
		void resetDatabase();

		// setAlive(false) for every object in players list 
		void killPlayers();
		void killEnemies();
		void killPowerUps();

		// Destroys a specific enemy.
		list<Enemy *>::iterator destroyEnemy(list<Enemy *>::iterator iter); 
	//	void destroyPowerUps(); 
};

#endif DATABASE_H