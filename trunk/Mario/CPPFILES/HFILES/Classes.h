#ifndef CLASSES_H
#define CLASSES_H

//#pragma once

//================================================================================================================
// LATEST UPDATE: NO IDEA WHY SOMETIMES INCLUDE USING "HFILES/CLassname" whereas now needs "Classname" directly
// Suspecting error comes from the way pragma once is used. 
// Trying out including files needed in each H File instead of here. 
// FOr now, this class is for allegro includes and globals only 
// NOTE: THE ORDER WHICH YOU INCLUDE STUFF MATTERS!! INCLUDE WHATEVER THAT IS INDEPENDENT FIRST!!
//================================================================================================================

// We will be using Java Conventions
// Class name (Capital letters) EX: Mario (capital M)
// variable/method names (small then Capital letters) EX: doSomethingHere (small d, big S and H) 
// Special keywords in Java used here. 
// TODO (means there is something to do here)
// FIXME (means the code has bugs/ incomplete) fix it!
// PARAM (the parameters that the method takes in)
// RETURN (the return value and what it actually returns) 

// SelfNote: I may be making too many classes.. Classes like Score may not be needed.. We'll see. 

#include <stdlib.h>
//==========================
// Allegro 5 
//==========================
#include <allegro5\allegro.h>
// Fonts
#include <allegro5\allegro_font.h>
#include <allegro5\allegro_ttf.h>
// Images
#include <allegro5\allegro_image.h> 
#include <allegro5\allegro_primitives.h> 
// Sounds
#include <allegro5\allegro_audio.h> 
#include <allegro5\allegro_acodec.h>
// Mappy
#include "HFILES/mappy_A5.h"
#include <math.h>
#include <vector>

//#include "HFILES/Database.h" // shifted from below in case order matters. 

//=======================
// Game Objects Files 
//=======================

/*
#include "HFILES/GameObject.h"
#include "HFILES/Player.h"
#include "HFILES/Enemy.h"
#include "HFILES/PowerUp.h"
*/

//====================
// Collision Files 
//====================

/*
#include "HFILES/Collision.h"
#include "HFILES/State.h"
#include "HFILES/Score.h"
//#include "HFILES/Database.h"
*/


//===================
// Input / Output  
//===================
#include <iostream>
using namespace std; 

/*
#include "HFILES/Display.h"
#include "HFILES/Keyboard.h"
#include "HFILES/Timer.h"
#include "HFILES/Sound.h"
*/

//===================
// Databases
//===================
#include <list> 

//===================
// Globals
//===================

// our user defined width and height that the Mario depends on, might not be const
//const int SLWIDTH, STARTWIDTH, ENDWIDTH;  
//const int SLHEIGHT, STARTHEIGHT, ENDHEIGHT; 

/*#ifdef __MAIN__
	#define __EXTERN(type, name, value) type name = value;
#else
	#define __EXTERN(type, name, value) extern type name;
#endif 

__EXTERN(bool , done, false);
__EXTERN(bool , redraw, false);
__EXTERN(bool , isGameOver, false);*/
 
//#define MODE GFX_AUTODETECT_WINDOWED
extern const float PI;
extern bool done;
extern bool redraw;
extern bool isGameOver;

//TODO: Include our formula to defined our own width and height later

// The actual width and height of the screen
static const int WIDTH = 800; 
static const int HEIGHT = 600; 
static const int FPS = 60;
static ALLEGRO_DISPLAY *display = NULL;
static ALLEGRO_EVENT_QUEUE *event_queue = NULL;
static ALLEGRO_TIMER *clocker = NULL;

// These will be updated between Keyboard and Timer classes
extern bool keys[5];
extern bool lock[5];
extern int xOff;
extern int yOff;
// This fluxes between 0 and 1, to decrease the effect of gravity in
// updateTimer. 
// To be updated later
static enum ID{PLAYER, ENEMY, POWERUP, BULLET, BORDER, MISC, EXPLOSION};
static enum enemySpecies{GOOMBA, KOOPA_TROOPA, PIRANHA_PLANT};
static enum blockSpecies{DEAD_QUESTION, SKY, DEAD_BRICK};
static enum powerUpSpecies{SUPER_MUSHROOM, FIRE_FLOWER, STAR};
static enum GAMESTATES{INTRO, MENU, PLAYING, PAUSE, GAMEOVER};
static enum KEYS{UP, DOWN, LEFT, RIGHT, SPACE, R, ESC};
//For the animations of all sprites.
//LEFT means walking to the left, RIGHT means walking to the right.
static enum FACING{WALKLEFT = -1, WALKRIGHT = 1, JUMPMODE = 3};


#endif CLASSES_H