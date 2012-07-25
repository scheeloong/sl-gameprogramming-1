#ifndef AUTOBOT_H
#define AUTOBOT_H
//#pragma once

#include "HFILES/Classes.h"
#include "HFILES/GameObject.h"

// This class, previously known as Enemy, has been renamed Autobot.
// This is because it contains key members that apply to both Enemy objects (Goomba, Koopa Troopas, etc)
// as well as PowerUp objects (Super Mushrooms, Fire Flowers, etc). It will act as the parent of all 
// enemies and powerups. 
// Note: The key similarity between enemies and powerups is that both move with automation. Dropping, tile
//		 collisions, species, image, animations, lives, and so on.
class Autobot : public GameObject
{
	private:
		int lives; // BOSS ENEMY has > 1 life
		int species;
	public:
		// Constructor
		Autobot() : GameObject() {lives = 1;} // normal enemy has 1 live only, WALKLEFT because it does so by default.
		Autobot(int lives); // Boss enemy has >1 live 
		void Init(int ID, int x, int y, int velX, int velY, int dirX, int dirY, bool alive, ALLEGRO_BITMAP *image)
		{GameObject::Init(ID, x, y, velX, velY, dirX, dirY, alive, image);}
		void InitImage(ALLEGRO_BITMAP *image) {setImage(image);}
		int getSpecies() {return species;}
		void setSpecies(int species) {Autobot::species = species;}
		void update();
		void destroy() {setAlive(false);}
		// Methods
		void takeLife(int i); // Minus i from lives
		void addLife(int i); // add i to lives (may not be needed) 
};
#endif AUTOBOT_H
//*/

