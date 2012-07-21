#include "HFILES/Collision.h"

Collision::Collision(Database *database)  
{
	Collision::database = database;
	insertObjectBounds(PLAYER, 13, 23);
	// Enemy only refers to Goomba as of now.
	insertObjectBounds(ENEMY, 22, 27);
}

//Adds new GameObject bounds to the two vectors. 
//The ID is just a stub, so you see what you're adding.
//It's not used in the function at all. The ID should be 
// the index of the added bounds.
void Collision::insertObjectBounds(int ID, int boundX, int boundY)
{
	Collision::boundX.push_back(boundX);
	Collision::boundY.push_back(boundY);
}

void updateBounds(GameObject GameObject)
{
	// May need to check somewhere the type of GameObject, can use dynamic cast or simple ID to check
	//boundX = meObject.x + 20; 
	//boundY = GameObject.y + 20; 
}

//This function gets called in the big while loop. It sums up all of class Collision.
void Collision::checkCollision()
{
	checkPlayerTileCollision();
	checkEnemyTileCollision();
	checkPlayerEnemyCollision();
}

void Collision::checkEnemyTileCollision()
{
	for(database->iterE = database->getEnemiesBegin(); database->iterE != database->getEnemiesEnd(); database->iterE++)
	{
		//This check might not be necessary.
		if((*(database->iterE))->getAlive())
		{
			float x = (*(database->iterE))->getX();
			float y = (*(database->iterE))->getY();

			int bx = boundX[(*(database->iterE))->getID()];
			int by = boundY[(*(database->iterE))->getID()];
	
			//Underfeet check. Due to some strange logic, we first have to check if it's onAir,
			//if not then check if it's on the ground. 
			if (!isTileCollidable(x, y + by)) {(*(database->iterE))->setonAir(true);}
			//reset animation isn't extremely important here.
			else {(*(database->iterE))->setonAir(false); (*(database->iterE))->setVelY(0); (*(database->iterE))->resetAnimation();}
			//Overhead check - won't really happen with enemies
			if (isTileCollidable(x, y - by)) {}

			//Rightside check. Only reverseDirection if the dude is currently TRYING TO WALKRIGHT && hitting a tile on the right!
			if (isTileCollidable(x + bx, y) && (*(database->iterE))->getfacing() == WALKRIGHT) 
				(*(database->iterE))->reverseDirection();
			//Leftside check. Only reverseDirection if the dude is currently TRYING TO WALKLEFT && hitting a tile on the left!
			if (isTileCollidable(x - bx, y) && (*(database->iterE))->getfacing() == WALKLEFT) 
				(*(database->iterE))->reverseDirection();
	
		}
	}

}
void Collision::checkPlayerTileCollision()
{
	for(database->iterP = database->getPlayersBegin(); database->iterP != database->getPlayersEnd(); database->iterP++)
	{
		float x = (*(database->iterP))->getX();
		float y = (*(database->iterP))->getY();

		int bx = boundX[(*(database->iterP))->getID()];
		int by = boundY[(*(database->iterP))->getID()];

		//If Mario jumps above the visible screen, tile collisions won't be checked.
		if(y > 0)
		//Check 4 corners of object1's bound box.
		//Underfeet check
		{
			if (!isTileCollidable(x, y + by)) {lock[DOWN] = false; (*(database->iterP))->setonAir(true);}
			else {lock[DOWN] = true; (*(database->iterP))->setonAir(false); (*(database->iterP))->setVelY(0); (*(database->iterP))->resetAnimation();}
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
			if(isTileSpecial(x, y))
			{
				if(isQuestionTile(x, y))
				{
					//do stuff
				}
				else if(isCoinTile(x, y))
				{
					//do stuff
				}
				else if(isBrickTile(x, y))
				{
					//do stuff
				}
			}
			if(isTriggerTile(x, y))
			{
				cout<<"Making enemy!" << endl;
				database->makeEnemy(WIDTH/2, HEIGHT/2, -3, 0, 1, 1, true);
				killTriggerTile(x, y);
			}
		}
	}
}

void Collision::checkPlayerEnemyCollision()
{
	for(database->iterP = database->getPlayersBegin(); database->iterP != database->getPlayersEnd(); database->iterP++)
	{
		float Px = (*(database->iterP))->getX();
		float Py = (*(database->iterP))->getY();

		int Pbx = boundX[(*(database->iterP))->getID()];
		int Pby = boundY[(*(database->iterP))->getID()];

		for(database->iterE = database->getEnemiesBegin(); database->iterE != database->getEnemiesEnd();)
		{
			float Ex = (*(database->iterE))->getX();
			float Ey = (*(database->iterE))->getY();

			int Ebx = boundX[(*(database->iterE))->getID()];
			int Eby = boundY[(*(database->iterE))->getID()];

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
					cout << "Mario's Life--" << endl;
					continue;
				}
			}
			// If the iterator did not change, increment it.

			database->iterE++;
		}
	}
}
