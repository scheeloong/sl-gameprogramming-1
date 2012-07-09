// This class deals with collisions
#pragma once
#include "Classes.h"

using namespace std;

class Collision
{
	private:
		int *BoundX; // an array
		int *BoundY;

	public:
		
		// Constructor
		//Collision() : boundX(0), boundY(0) {}
		Collision()  
		{
			Collision::BoundX =  BoundX;
			Collision::BoundY =  BoundY;

			//TODO: Incorporate hash tables here to determine boundX and boundY for specific objects,
			//based on ID.
		}

		// Methods
		void updateBounds(GameObject GameObject)
		{
			// May need to check somewhere the type of GameObject, can use dynamic cast or simple ID to check
			//boundX = meObject.x + 20; 
			//boundY = GameObject.y + 20; 
		}

		bool superCheckCollision(GameObject &object1, GameObject &object2) // FIXME
		{
			float X1 = object1.getX();
			float Y1 = object1.getY();

			float X2 = object2.getX();
			float Y2 = object2.getY();

			int bX1 = BoundX[object1.getID()] [object1.getSpecies()];
			int bY1 = BoundY[object1.getID()]  [object1.getID()];
			int bX2 = BoundX[ object2.getID()]  [object2.getSpecies()];
			int bY2 = BoundY[object2.getID()]  [object2.getSpecies()];

			if( X1 + bX1 > X2 - bX2 &&
				X1 - bX1 < X2 + bX2 &&
				Y1 + bY1 > Y2 - bY2 &&
				Y1 - bY1 < Y2 + bY2)
				return true;
			else
				return false;
		}
};

