// This class stores all the header files needed. 
	// For simplicity, every header file and main function includes this class. 
#pragma once

// We will be using Java Conventions
// Class name (Capital letters) EX: Mario (capital M)
// variable/method names (small then Capital letters) EX: doSomethingHere (small d, big S and H) 
// Special keywords in Java used here. 
// TODO (means there is something to do here)
// FIXME (means the code has bugs/ incomplete) fix it!
// PARAM (the parameters that the method takes in)
// RETURN (the return value and what it actually returns) 

// SelfNote: I may be making too many classes.. Classes like Score may not be needed.. We'll see. 

// NOTE: THE ORDER WHICH YOU INCLUDE STUFF MATTERS!! INCLUDE WHATEVER THAT IS INDEPENDENT FIRST!!

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

//TODO: Include all the allegro 5 header files


#include "HFILES/Database.h" // shifted from below in case order matters. 
//=======================
// Game Objects Files 
//=======================
#include "HFILES/GameObject.h"
#include "HFILES/Player.h"
#include "HFILES/Enemy.h"
#include "HFILES/PowerUp.h"

//====================
// Collision Files 
//====================
#include "HFILES/Collision.h"
#include "HFILES/State.h"
#include "HFILES/Score.h"
//#include "HFILES/Database.h"
ALLEGRO_EVENT_QUEUE *event_queue = al_create_event_queue();
ALLEGRO_TIMER *clocker = NULL;
//===================
// Input / Output  
//===================
#include "HFILES/Display.h"
#include "HFILES/Keyboard.h"
#include "HFILES/Timer.h"
#include <iostream>
#include "HFILES/Sound.h"
#include <stdlib.h>
//===================
// Databases
//===================
#include <list> 
using namespace std; 

//===================
// Globals
//===================

// our user defined width and height that the Mario depends on, might not be const
//const int SLWIDTH, STARTWIDTH, ENDWIDTH;  
//const int SLHEIGHT, STARTHEIGHT, ENDHEIGHT; 
bool done = false;
bool redraw = false;
//only truified when player lives are over.
bool isGameOver = false;

//TODO: Include our formula to defined our own width and height later

// The actual width and height of the screen
const int WIDTH = 600; 
const int HEIGHT = 800; 

// These will be updated between Keyboard and Timer classes
bool keys[] = {false, false, false, false, false};
bool lock[] = {false, false, false, false, false};


// To be updated later
enum ID{PLAYER, ENEMY, BULLET, BORDER, MISC, EXPLOSION};
enum GAMESTATES{INTRO, MENU, PLAY, GAMEOVER};
enum KEYS{UP, DOWN, LEFT, RIGHT, SPACE};


