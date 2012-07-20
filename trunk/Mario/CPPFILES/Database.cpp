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

void Database::updateList(list<Player *> &object_list, list<Player *>::iterator iter)
{
	for( iter = object_list.begin(); iter != object_list.end(); iter++)
	{
		(*iter)->update();
	}
}
void Database::updateList(list<Enemy *> &object_list, list<Enemy *>::iterator iter)
{
	for( iter = object_list.begin(); iter != object_list.end(); iter++)
	{
		(*iter)->update();
	}
}

void Database::drawList(list<Player *> object_list, list<Player *>::iterator iter)
{
	for( iter = object_list.begin(); iter != object_list.end(); iter++)
	{
		(*iter)->draw();
	}
}
void Database::drawList(list<Enemy *> object_list, list<Enemy *>::iterator iter)
{
	for( iter = object_list.begin(); iter != object_list.end(); iter++)
	{
		(*iter)->draw();
	}
}
void Database::destroyList(list<Player *> object_list, list<Player *>::iterator iter)
{
	for( iter = object_list.begin(); iter != object_list.end(); )
	{
		if(! (*iter)->getAlive())
		{
			//Call native destroy on the object.
			(*iter)->destroy();
			//Destroy object.
			delete (*iter);
			iter = object_list.erase(iter);
		}
		else
			iter++;
	}
}
void Database::destroyList(list<Enemy *> object_list, list<Enemy *>::iterator iter)
{
	for( iter = object_list.begin(); iter != object_list.end(); )
	{
		if(! (*iter)->getAlive())
		{
			//Call native destroy on the object.
			(*iter)->destroy();
			//Destroy object.
			delete (*iter);
			iter = object_list.erase(iter);
		}
		else
			iter++;
	}
}
/*void Database::destroyPlayer()
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
}*/

void destroyEnemy()
{

}

/*void destroyPowerUps()
{

}*/
