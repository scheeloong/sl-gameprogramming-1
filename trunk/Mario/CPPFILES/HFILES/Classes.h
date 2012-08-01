#ifndef CLASSES_H
#define CLASSES_H

//#pragma once

// VL: First of all, testing has to do with lots of the syntax in the code. Many instances of trial and error were performed,
// and some residue is still hanging around. Some good, some bad. Just a lot of them.

// BEFORE YOU START DOING ANYTHING, PLEASE:
// i) Try running, it should behave as it was in revision 72. (I was not able to run the file, probably some visual studio thingy)
		// if you can't run, refer to CAN'T RUN
// ii) spend 30mins-1 hour to fix up all comments (just look through every file and you will know what I mean.
// iii) Read LATEST UPDATE before you do ii)
// iv) Try running again to ensure that your commenting did accidentally spoil the code
// v) If it runs, update to the latest revision. Now is revision 73 (my comments), revision 74 should include
				// all the comments from you and no changes to the code performance.
// vi) Message me when you're done=)

//================================================================================================================
// CAN'T RUN
// CL: IF YOU CAN'T RUN, ITS NOT ANYTHING TO DO WITH THE COMMENTS, I CHANGED THE WAY THE SOME HEADER FILES ARE INCLUDED,
// EX: #include "HFILES/bla" instead of "bla" viceversa. Just change that to fix the problem.
// it should run like how it should before I did anything.
//================================================================================================================

//================================================================================================================
// LATEST UPDATE
// All comments with CL: or VL: is specific for group communications. They are temporary comments that will be 
// removed later. Example:
// CL: Wtf is this? 
// VL: A function to install the images
// CL: (After understanding, deletes the previous 2 lines, and will help update comments
//      to improve readability.)
//----------------------------------------------------------------------------------------------------------------
// Note: Companies require >= 1 person to review each other's code to ensure that it is readable.
// Trust me, more comments is always better than no comments. Try svn checkout a new file from some website,
// you won't understand what a simple line such as
// xfactor++; 
// does. Of course, you know it increases some variable xfactor by 1. But what's the point in doing so? 
// that's when you have to always comment.
//----------------------------------------------------------------------------------------------------------------
// Next, above every function.( I prefer it in cpp files instead of hfiles though Prof.Pitt use to do it in hfiles)
// Make sure you include its description (no matter how simply it is) EX: This function keeps track of a players lives.
// And also include its PARAMETERS && RETURN values!! 
// EX: It takes in the current x and y position of the player
//     and returns the number of lives of the player or NULL if it is dead, it returns -1 in case of error.
//----------------------------------------------------------------------------------------------------------------
// Lastly, please learn to use more indentation for conditional and loops. 
// if(), for(), while() etc..
// DON'T DO THIS.
// if(bla)
// {bla;}
// blabla;
// Instead DO THIS
// if(bla)
//     bla; // (4 spaces (or a tab) is standard (NOT for all languages)
// blabla; // This will automaticaly be understood as not being in the if statement since it wasn't indented.
//================================================================================================================

//================================================================================================================
// NO IDEA WHY NEED TO ALTERNATE BETWEEN INCLUDE USING "HFILES/CLassname" OR "Classname" directly.
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
#include <list>

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
#include <list> // CL: WHY DID YOU INCLUDE <LIST> TWICE? 

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

// This bool is used to let various functions know that the xOff has been changed from keyboard input. 
static ALLEGRO_DISPLAY *display = NULL;
static ALLEGRO_EVENT_QUEUE *event_queue = NULL;
static ALLEGRO_TIMER *clocker = NULL;

// These will be updated between Keyboard and Timer classes
extern bool keys[5];
extern bool lock[5];
extern int xOff;
extern int yOff;
extern int playerVelX;
extern int oldXOff;
extern int deltaXOff;
extern bool isMoved;
// NILL and NALL are space holders that represent 0. This is important in score keeping.
static enum ID{PLAYER, ENEMY, POWERUP, BULLET, BORDER, MISC, EXPLOSION};
static enum TILES{BRICK, COIN};
static enum playerSpecies{BABY, RED, WHITE};
// KOOPA_TROOPA_SHELL is inserted at end of enum to not hyperboost the scoring system.
static enum enemySpecies{GOOMBA, KOOPA_TROOPA, PIRANHA_PLANT, KOOPA_TROOPA_SHELL};
static enum koopaState{WALKING, INSHELL, GLIDING};
static enum blockSpecies{DEAD_QUESTION, SKY, DEAD_BRICK};
static enum powerUpSpecies{SUPER_MUSHROOM, FIRE_FLOWER, STAR};
static enum GAMESTATES{INTRO, MENU, PLAYING, PAUSE, GAMEOVER};
static enum KEYS{UP, DOWN, LEFT, RIGHT, SPACE, R, ESC};
//For the animations of all sprites.
//LEFT means walking to the left, RIGHT means walking to the right.
static enum FACING{WALKLEFT = -1, WALKRIGHT = 1, JUMPMODE = 3, CROUCH = 4};

#endif CLASSES_H