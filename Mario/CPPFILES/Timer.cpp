#pragma once
#include "HFILES/Timer.h"

// This function checks if the object is flying, and if yes,
// ensures that it accelerates at the right rate.
bool Timer::isItFlying(GameObject *object)
{
	if (object->getonAir() == true) //object is in the air
	{	// halffire ensures we accelerate 
		// every other loop through update timer.
		// essentially making gravity = 0.5
		if(object->gethalffire())
		{
			object->accelerate();
			object->sethalffire(0);
		}
		else object->sethalffire(1);
		return true;
	}
	return false;
}
void Timer::updateTimer(ALLEGRO_EVENT *ev)
{
	
	MapUpdateAnims();
	if(ev->type == ALLEGRO_EVENT_TIMER)
	{
		redraw = true;
		if(state->getState() == PLAYING)
		{
			for(database->iterP = database->getPlayersBegin(); database->iterP != database->getPlayersEnd(); database->iterP++)
			{
				if(isItFlying(*(database->iterP))) {}
		
				else if(keys[UP] && !lock[UP])
			{		
					// UNIQUE to PLAYER: gives player the initial velocity
					(*(database->iterP))->startLeap();
					// changes curFrame to JUMPMODE
					(*database->iterP)->jumpGlide();
				}
				else if(keys[DOWN] && !lock[DOWN])
					(*(database->iterP))->moveDown();
	
				if(keys[LEFT] && !lock[LEFT])
					(*(database->iterP))->moveLeft();
				else if(keys[RIGHT] && !lock[RIGHT])
					(*(database->iterP))->moveRight();

				//animation only goes back to frame 0 when all keys are released.
				if(!keys[UP] && !keys[DOWN] && !keys[LEFT] && !keys[RIGHT])
					(*(database->iterP))->resetAnimation();
				// Changing state upon pressing ESC key.
				if(keys[ESC]) {keys[ESC] = false; state->setState(PAUSE);}
				
				// Updating the database's enemies and powerups by incorporating gravity.
				for(database->iterE = database->getEnemiesBegin(); database->iterE != database->getEnemiesEnd(); database->iterE++)
					isItFlying(*database->iterE);
				for(database->iterPU = database->getPowerUpsBegin(); database->iterPU != database->getPowerUpsEnd(); database->iterPU++)
				{
					isItFlying(*database->iterPU);
					
				}
				// Keep the bounceblocks accelerating until they reach their original starting position.
				for(database->iterB = database->getBounceBlocksBegin(); database->iterB != database->getBounceBlocksEnd(); database->iterB++)
				{
					if((*database->iterB)->getY() < (*database->iterB)->getStartY())
						isItFlying(*database->iterB);
					else 
						(*database->iterB)->setVelY(0);
				}
				//isItFlying(*database->iterB);
			}
		}
		else if(state->getState() == PAUSE)
		{
			if(keys[R]) state->setState(PLAYING);
			else if(keys[ESC]) 
			{
				state->setState(GAMEOVER);
				keys[ESC] = false;
			}
		}

		else if(state->getState() == GAMEOVER)
		{
			cout << "In timer's Gameover" << endl;
			if(keys[R])
			{
				// reset database!
				// reload map
				database->resetDatabase();
				state->setState(PLAYING);
			}
			else if(keys[ESC]) done = true;
		}
	}
}

