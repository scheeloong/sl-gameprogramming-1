#include "HFILES/Database.h"

// Defining Methods
Database::Database()
{
	//makePlayer(WIDTH/2, HEIGHT/2, 5, 5, 1, 1, true); // make a player
	// enemies and powerups remain empty before tileblock sets it
}

void Database::InitImages(ALLEGRO_BITMAP *BabyMario, ALLEGRO_BITMAP *Goomba, ALLEGRO_BITMAP *Mushroom,
	                      ALLEGRO_BITMAP *deadQuestion, ALLEGRO_BITMAP *sky, ALLEGRO_BITMAP *deadBrick)
{
	Database::BabyMario = BabyMario;
	Database::GoombaPic = Goomba;
	Database::MushroomPic = Mushroom;
	Database::deadQuestion = deadQuestion;
	Database::sky = sky;
	Database::deadBrick = deadBrick;
}
		
void Database::makePlayer(int x, int y, int velX, int velY, int dirX, int dirY, bool alive)
{
	Player *player = new Player(); 
	player->Init(x, y, velX, velY, dirX, dirY, alive, BabyMario);
	players.push_back(player);
}
void Database::makeEnemy(int species, int x, int y, int velX, int velY, int dirX, int dirY, bool alive)
{
	if(species == GOOMBA)
	{
		Goomba *goomba = new Goomba(); 
		goomba->Init(ENEMY, GOOMBA, x, y, velX, velY, dirX, dirY, alive, GoombaPic);
		enemies.push_back(goomba);
	}
}
void Database::makePowerUp(int species, int x, int y, int velX, int velY, int dirX, int dirY, bool alive)
{
	if(species == SUPER_MUSHROOM)
	{
		SuperMushroom *mushroom = new SuperMushroom();
		mushroom->Init(POWERUP, SUPER_MUSHROOM, x, y, velX, velY, dirX, dirY, alive, MushroomPic);
		powerUps.push_back(mushroom); 
	}
}
void Database::makeBounceBlock(int species, int x, int y, int velX, int velY, int dirX, int dirY, bool alive)
{
	BounceBlock *bblock = new BounceBlock();
	if(species == DEAD_QUESTION)
	{	
		bblock->Init(x, y, velX, velY, dirX, dirY, alive, deadQuestion, y, species);
	}
	else if(species == SKY)
		bblock->Init(x, y, velX, velY, dirX, dirY, alive, sky, y, species);
	else if(species == DEAD_BRICK)
		bblock->Init(x, y, velX, velY, dirX, dirY, alive, deadBrick, y, species);

	bounceBlocks.push_back(bblock);
}

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
void Database::updatePowerUpList()
{
	for( iterPU = powerUps.begin(); iterPU != powerUps.end(); iterPU++)
	{
		(*iterPU)->update();
	}
}
void Database::updateBounceBlockList()
{
	for( iterB = bounceBlocks.begin(); iterB != bounceBlocks.end(); )
	{
		if((*iterB)->getAlive())
		{
			(*iterB)->update();
			iterB++;
		}
		else
		{
			delete (*iterB);
			iterB = bounceBlocks.erase(iterB);
		}
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
void Database::drawPowerUpList()
{
	for( iterPU = powerUps.begin(); iterPU != powerUps.end(); iterPU++)
	{
		(*iterPU)->draw();
	}
}
void Database::drawBounceBlockList()
{
	for (iterB = bounceBlocks.begin(); iterB != bounceBlocks.end(); iterB++)
	{
		(*iterB)->draw();
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
void Database::destroyPowerUpList()
{
	for( iterPU = powerUps.begin(); iterPU != powerUps.end(); )
	{
		if(! (*iterPU)->getAlive())
		{
			//Call native destroy on the object.
			(*iterPU)->destroy();
			//Destroy object.
			delete (*iterPU);
			iterPU = powerUps.erase(iterPU);
		}
		else
			iterPU++;
	}
}
void Database::destroyBounceBlockList()
{
	for( iterB = bounceBlocks.begin(); iterB != bounceBlocks.end(); )
	{
		if(! (*iterB)->getAlive())
		{
			//Call native destroy on the object.
			(*iterB)->destroy();
			//Destroy object.
			delete (*iterB);
			iterB = bounceBlocks.erase(iterB);
		}
		else
			iterB++;
	}
}

void Database::resetDatabase()
{
	killPlayers();
	killEnemies();
	killPowerUps();
	killBounceBlocks();
	destroy();
	makePlayer(WIDTH/2, HEIGHT/2, 5, 5, 1, 1, true);
}
void Database::deleteDatabase()
{
	killPlayers();
	killEnemies();
	killPowerUps();
	killBounceBlocks();
	destroy();
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
void Database::killPowerUps()
{
	for( iterPU = powerUps.begin(); iterPU != powerUps.end(); iterPU ++)
		(*iterPU)->setAlive(false);
}
void Database::killBounceBlocks()
{
	for( iterB = bounceBlocks.begin(); iterB != bounceBlocks.end(); iterB ++)
		(*iterB)->setAlive(false);
}

list<Autobot *>::iterator Database::destroyEnemy(list<Autobot *>::iterator iter)
{
	(*iter)->destroy();
	iter = enemies.erase(iter);
	return iter;
}
list<Autobot *>::iterator Database::destroyPowerUp(list<Autobot *>::iterator iter)
{
	(*iter)->destroy();
	iter = powerUps.erase(iter);
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
