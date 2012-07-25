#include "HFILES/Collision.h"

Collision::Collision(Database *database)  
{
	Collision::database = database;
	insertObjectBounds(PLAYER, 0, 13, 23);
	// Enemy only refers to Goomba as of now.
	insertObjectBounds(ENEMY, GOOMBA, 22, 27);
	insertObjectBounds(POWERUP, SUPER_MUSHROOM, 22, 27);
	counter = 0;
}

//Adds new GameObject bounds to the two vectors. 
//The ID is just a stub, so you see what you're adding.
//It's not used in the function at all. The ID should be 
// the index of the added bounds.
void Collision::insertObjectBounds(int ID, int species, int boundX, int boundY)
{
	if(ID == PLAYER)
	{
		playerBoundX.push_back(boundX);
		playerBoundY.push_back(boundY);
	}
	else if(ID == ENEMY)
	{
		// determine the appropriate iterator position.
		iterY = powerUpBoundY.begin();
		for(iterX = enemyBoundX.begin(); iterX != enemyBoundX.end(); iterX++)
		{
			if(counter == species) 
			{
				counter = 0;
				break;
			}
			else
				counter++;
			iterY++;
		}
		// and insert an element at that position.
		enemyBoundX.insert(iterX, boundX);
		enemyBoundY.insert(iterY, boundY);
	}
	else if(ID == POWERUP)
	{
		iterY = powerUpBoundY.begin();
		for(iterX = powerUpBoundX.begin(); iterX != powerUpBoundX.end(); iterX++)
		{
			if(counter == species)
			{
				counter = 0;
				break;
			}
			else 
				counter++;
			iterY++;
		}
		powerUpBoundX.insert(iterX, boundX);
		powerUpBoundY.insert(iterY, boundY);
	}

}

void updateBounds(GameObject GameObject)
{
	// May need to check somewhere the type of GameObject, can use dynamic cast or simple ID to check
	//boundX = meObject.x + 20; 
	//boundY = GameObject.y + 20; 
}
void Collision::checkPlayerTileCollision()
{
	for(database->iterP = database->getPlayersBegin(); database->iterP != database->getPlayersEnd(); database->iterP++)
	{
		int x = (*(database->iterP))->getX();
		int y = (*(database->iterP))->getY();

		// Player class does not have a species, so until we implement multiplayer mode, bx and by 
		// will be stored at index 0, or PLAYER.
		int bx = playerBoundX[(*(database->iterP))->getID()];
		int by = playerBoundY[(*(database->iterP))->getID()];

		//If Mario jumps above the visible screen, tile collisions won't be checked.
		if(y > 0)
		//Check 4 corners of object1's bound box.
		//Underfeet check
		{
			if (!isTileCollidable(x, y + by)) {lock[DOWN] = false; (*(database->iterP))->setonAir(true);}
			else 
			{
				lock[DOWN] = true; 
				(*(database->iterP))->setonAir(false); 
				// Sets player at ground level with VelY = 0 //
				(*(database->iterP))->setVelY(0); 
				(*(database->iterP))->setY(((y+by)/mapblockheight) * 50 - 22); 
				///////////////////////////////////////////////
				(*(database->iterP))->resetAnimation();
			}
			//Overhead check
			if (isTileCollidable(x, y - by)) {lock[UP] = true; (*(database->iterP))->reverseDirection();}
			else lock[UP] = false;
			//Rightside check
			if (isTileCollidable(x + bx, y)) lock[RIGHT] = true;
			else lock[RIGHT] = false;
			//Leftside check
			if (isTileCollidable(x - bx, y)) lock[LEFT] = true;
			else lock[LEFT] = false;

			//TODO: modify to check every side of body.
			if(isTileSpecial(x, y - 25))
			{
				if(isQuestionTile(x, y - 25))
				{
					database->makeBounceBlock(DEAD_QUESTION, (x/mapblockwidth) * 50, ((y-25)/mapblockheight) * 50, 0, -5, 1, 1, true);
					database->makePowerUp(SUPER_MUSHROOM, (x/mapblockwidth) * 50 + 25, ((y-25)/mapblockheight) * 50 - 30, 2, -5, 1, 1, true);
					killSpecialTile(x, y - 25);
				}
				else if(isCoinTile(x, y))
				{
					cout << "Coin!" << endl;
					//do stuff
				}
				else if(isBrickTile(x, y - 25))
				{
					database->makeBounceBlock(DEAD_BRICK, (x/mapblockwidth) * 50, ((y-25)/mapblockheight) * 50, 0, -4, 1, 1, true);
					killSpecialTile(x, y - 25);
				}
			}
			if(isTriggerTile(x, y))
			{
				database->makeEnemy(GOOMBA, WIDTH/2, HEIGHT/2, -3, 0, 1, 1, true);
				killTriggerTile(x, y);
			}
		}
	}
}
void Collision::checkEnemyTileCollision()
{
	for(database->iterE = database->getEnemiesBegin(); database->iterE != database->getEnemiesEnd(); database->iterE++)
	{
		//This check might not be necessary.
		if((*(database->iterE))->getAlive())
		{
			int x = (*(database->iterE))->getX();
			int y = (*(database->iterE))->getY();

			int bx = enemyBoundX[(*(database->iterE))->getSpecies()];
			int by = enemyBoundY[(*(database->iterE))->getSpecies()];
	
			//Underfeet check. Due to some strange logic, we first have to check if it's onAir,
			//if not then check if it's on the ground. 
			if (!isTileCollidable(x, y + by)) {(*(database->iterE))->setonAir(true);}
			else 
			{
				if(!isTileBouncing(x, y + by))
				{
					(*(database->iterE))->setonAir(false); 
					// Sets enemy at ground level with VelY = 0 //
					(*(database->iterE))->setVelY(0); 
					(*(database->iterE))->setY(((y+by)/mapblockheight) * 50 - 22); 
				}
				else // Tile is bouncing
				{
					(*(database->iterE))->setVelY(-8);
					// Goomba will bounce up and accelerate to bottom of screen. (Disables collidability);
					(*(database->iterE))->setAlive(false);
					(*(database->iterE))->setonAir(true);
				}
				//////////////////////////////////////////////
			}
			//Overhead check - won't really happen with enemies
			if (isTileCollidable(x, y - by)) {}

			//Rightside check. Only reverseDirection if the dude is currently TRYING TO WALKRIGHT && hitting a tile on the right!
			if (isTileCollidable(x + bx, y) && (*(database->iterE))->getfacing() == WALKRIGHT) 
				(*(database->iterE))->reverseDirection();
			//Leftside check. Only reverseDirection if the dude is currently TRYING TO WALKLEFT && hitting a tile on the left!
			if (isTileCollidable(x - bx, y) && (*(database->iterE))->getfacing() == WALKLEFT) 
				(*(database->iterE))->reverseDirection();
			if(isTileDeath(x, y))
				database->iterE = database->destroyEnemy(database->iterE);
	
		}
	}
}
void Collision::checkPowerUpTileCollision()
{
	for(database->iterPU = database->getPowerUpsBegin(); database->iterPU != database->getPowerUpsEnd(); database->iterPU++)
	{
	//This check might not be necessary.
		if((*(database->iterPU))->getAlive())
		{
			int x = (*(database->iterPU))->getX();
			int y = (*(database->iterPU))->getY();

			int bx = powerUpBoundX[(*(database->iterPU))->getSpecies()];
			int by = powerUpBoundY[(*(database->iterPU))->getSpecies()];

			//Underfeet check. Due to some strange logic, we first have to check if it's onAir,
			//if not then check if it's on the ground. 
			if (!isTileCollidable(x, y + by)) {(*(database->iterPU))->setonAir(true);}
			
			else 
			{
				if(!isTileBouncing(x, y + by))
				{
					(*(database->iterPU))->setonAir(false); 
					// Sets player at ground level with VelY = 0 //
					(*(database->iterPU))->setVelY(0); 
					(*(database->iterPU))->setY(((y+by)/mapblockheight) * 50 - 22); 
					///////////////////////////////////////////////
				}
				else
					(*(database->iterPU))->setVelY(-5); 
			}
			//Overhead check - won't really happen with autobots
			if (isTileCollidable(x, y - by)) {}
			//Rightside check. Only reverseDirection if the dude is currently TRYING TO WALKRIGHT && hitting a tile on the right!
			if (isTileCollidable(x + bx, y) && (*(database->iterPU))->getfacing() == WALKRIGHT) 
			{(*(database->iterPU))->reverseDirection();}
			//Leftside check. Only reverseDirection if the dude is currently TRYING TO WALKLEFT && hitting a tile on the left!
			if (isTileCollidable(x - bx, y) && (*(database->iterPU))->getfacing() == WALKLEFT) 
				(*(database->iterPU))->reverseDirection();
		}
	}
}

void Collision::checkPlayerEnemyCollision()
{
	for(database->iterP = database->getPlayersBegin(); database->iterP != database->getPlayersEnd(); database->iterP++)
	{
		int Px = (*(database->iterP))->getX();
		int Py = (*(database->iterP))->getY();

		int Pbx = playerBoundX[(*(database->iterP))->getID()];
		int Pby = playerBoundY[(*(database->iterP))->getID()];

		for(database->iterE = database->getEnemiesBegin(); database->iterE != database->getEnemiesEnd();)
		{
			int Ex = (*(database->iterE))->getX();
			int Ey = (*(database->iterE))->getY();

			int Ebx = enemyBoundX[(*(database->iterE))->getSpecies()];
			int Eby = enemyBoundY[(*(database->iterE))->getSpecies()];

			// If Mario lands on an enemy. 
			if((Py + Pby) <= Ey && (Py + Pby) >= (Ey - Eby)) 
			{	// If one corner of his bound box is between the corners of his enemy's
				if(((Px + Pbx) >= (Ex - Ebx) && (Px + Pbx) <= (Ex + Ebx)) || 
				   ((Px - Pbx) >= (Ex - Ebx) && (Px + Pbx) <= (Ex + Ebx)))
				{
					//Increase Mario's score
					database->iterE = database->destroyEnemy(database->iterE);
					continue;
				}
			}
			// Player's left hits Enemy's right || Player's right hits Enemy's left
			else if((Px - Pbx) >= (Ex - Ebx) && (Px - Pbx) <= (Ex + Ebx) ||
				    (Px + Pbx) >= (Ex - Ebx) && (Px + Pbx) <= (Ex + Ebx))
			{
				if((Py - Pby) >= (Ey - Eby) && (Py - Pby) <= (Ey + Eby) ||
				   (Py + Pby) >= (Ey - Eby) && (Py + Pby) <= (Ey + Eby))

				{
					// TODO: decrease Mario's life! currently an infinite loop.
					//*(database->iterP)->decrementLife();
					continue;
				}
			}
			database->iterE++;
		}
	}
}
