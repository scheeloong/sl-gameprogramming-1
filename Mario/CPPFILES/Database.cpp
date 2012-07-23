#include "HFILES/Database.h"

// Defining Methods
Database::Database()
{
	//makePlayer(WIDTH/2, HEIGHT/2, 5, 5, 1, 1, true); // make a player
	// enemies and powerups remain empty before tileblock sets it
}

void Database::InitImages(ALLEGRO_BITMAP *BabyMario, ALLEGRO_BITMAP *Goomba)
{
	Database::BabyMario = BabyMario;
	Database::GoombaPic = Goomba;
}
		
void Database::makePlayer(int x, int y, int velX, int velY, int dirX, int dirY, bool alive)
{
	Player *player = new Player(); 
	player->Init(x, y, velX, velY, dirX, dirY, alive, BabyMario);
	players.push_back(player);
}
void Database::makeEnemy(int x, int y, int velX, int velY, int dirX, int dirY, bool alive)
{
	Goomba *goomba = new Goomba(); 
	goomba->Init(x, y, velX, velY, dirX, dirY, alive, GoombaPic);
	enemies.push_back(goomba); 
}
/*void Database::makePowerUps()
{
	PowerUp *pu = new PowerUp(); 
	powerUps.push_back(pu); 
}*/

void Database::updatePlayerList()
{
	for( iterP = players.begin(); iterP != players.end(); iterP ++)
	{
		(*iterP)->update();
	}
}
void Database::updateEnemyList()
{
	for( iterE = enemies.begin(); iterE != enemies.end(); iterE++)
	{
		(*iterE)->update();
	}
}

void Database::drawPlayerList()
{
	for( iterP = players.begin(); iterP != players.end(); iterP ++)
	{
		(*iterP)->draw();
	}
}
void Database::drawEnemyList()
{
	for( iterE = enemies.begin(); iterE != enemies.end(); iterE++)
	{
		(*iterE)->draw();
	}
}

void Database::destroyPlayerList()
{
	for( iterP = players.begin(); iterP != players.end(); )
	{
		if(! (*iterP)->getAlive())
		{
			//Call native destroy on the object.
			(*iterP)->destroy();
			//Destroy object.
			delete (*iterP);
			iterP = players.erase(iterP);
		}
		else
			iterP++;
	}
}
void Database::destroyEnemyList()
{
	for( iterE = enemies.begin(); iterE != enemies.end(); )
	{
		if(! (*iterE)->getAlive())
		{
			//Call native destroy on the object.
			(*iterE)->destroy();
			//Destroy object.
			delete (*iterE);
			iterE = enemies.erase(iterE);
		}
		else
			iterE++;
	}
}

void Database::resetDatabase()
{
	killPlayers();
	killEnemies();
	//killPowerUps();
	destroy();
	makePlayer(WIDTH/2, HEIGHT/2, 5, 5, 1, 1, true);
}

void Database::killPlayers()
{
	for( iterP = players.begin(); iterP != players.end(); iterP ++)
		(*iterP)->setAlive(false);
}
void Database::killEnemies()
{
	for( iterE = enemies.begin(); iterE != enemies.end(); iterE ++)
		(*iterE)->setAlive(false);
}
list<Enemy *>::iterator Database::destroyEnemy(list<Enemy *>::iterator iter)
{
	(*iter)->destroy();
	iter = enemies.erase(iter);
	return iter;
}

/* This is an old template for destroy. Very general.
void Database::destroyEnemyList(list<Enemy *> *object_list, list<Enemy *>::iterator iter)
{
	for( iter = object_list->begin(); iter != object_list->end(); )
	{
		if(! (*iter)->getAlive())
		{
			//Call native destroy on the object.
			(*iter)->destroy();
			//Destroy object.
			delete (*iter);
			iter = object_list->erase(iter);
		}
		else
			iter++;
	}
}*/
/*void destroyPowerUps()
{

}*/
