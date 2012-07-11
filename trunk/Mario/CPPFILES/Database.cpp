#include "Database.h"

// Defining Methods
Database::Database()
{
	makePlayer(); // make a player
	// enemies and powerups remain empty before tileblock sets it
}
		
void Database::makePlayer()
{
	Player *pl = new Player(); 
	players.push_back(pl);
}

void Database::makeEnemy()
{
	Enemy *en = new Enemy(); 
	enemies.push_back(en); 
}

void Database::makePowerUps()
{
	PowerUp *pu = new PowerUp(); 
	powerUps.push_back(pu); 
}

void destroyPlayer()
{
	for( iterP = players.begin(); iterP != players.end(); )
	{
		if(! (*iterP)->GetAlive())
		{
			delete (*iterP);
			iter = objects.erase(iter);
		}
		else
			iterP++;
	}
}

void destroyEnemy()
{

}

void destroyPowerUps()
{

}