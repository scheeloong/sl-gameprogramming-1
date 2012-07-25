#include "HFILES/Database.h"

// Defining Methods
Database::Database()
{
	//makePlayer(WIDTH/2, HEIGHT/2, 5, 5, 1, 1, true); // make a player
	// enemies and powerups remain empty before tileblock sets it
}

void Database::InitImages(ALLEGRO_BITMAP *BabyMario, ALLEGRO_BITMAP *Goomba, ALLEGRO_BITMAP *deadQuestion, ALLEGRO_BITMAP *sky, ALLEGRO_BITMAP *deadBrick)
{
	Database::BabyMario = BabyMario;
	Database::GoombaPic = Goomba;
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
// Will need to indicate species with the introduction of KOOPATROOPAS!
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
void Database::makeBounceBlock(int x, int y, int velX, int velY, int dirX, int dirY, bool alive, int species)
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
			cout << "Erasing" << endl;
			//(*iterB)->destroy();
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
	//killPowerUps();
	killBounceBlocks();
	destroy();
	makePlayer(WIDTH/2, HEIGHT/2, 5, 5, 1, 1, true);
}

void Database::deleteDatabase()
{
	killPlayers();
	killEnemies();
	//killPowerUps();
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
void Database::killBounceBlocks()
{
	for( iterB = bounceBlocks.begin(); iterB != bounceBlocks.end(); iterB ++)
		(*iterB)->setAlive(false);
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
