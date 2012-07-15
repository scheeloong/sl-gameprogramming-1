/*//
    // This class stores all the header files needed. 
	// For simplicity, every header file and main function includes this class. 
#pragma once
#include <iostream>
using namespace std; 
// We will be using Java Conventions
// Class name (Capital letters) EX: Mario (capital M)
// variable/method names (small then Capital letters) EX: doSomethingHere (small d, big S and H) 
// Special keywords in Java used here. 
// TODO (means there is something to do here)
// FIXME (means the code has bugs/ incomplete) fix it!
// PARAM (the parameters that the method takes in)
// RETURN (the return value and what it actually returns) 

// Why bother with header files?? Why not just use cpp files?? Come to think of it, the tutorials didn't need to use HEADER files at all!
// I just remembered from lectures.. 
// Headerfiles => Declaration of prototypes and their Documented Comments!!
	// (where we put PARAM, RETURN, and comments about all the methods, classes, datas)
// CPPfiles => Definition of classes and methods (only simple documented comments, comments more on code structure) 

		// NOTE!! NOW I AM JUST INCLUDING EVERY HEADER FILE HERE TILL WE FINISH THIS GAME
		// ONCE IT'S DONE, I WILL PUT THE RESPECTIVE HEADER FILES INTO THEIR RESPECTIVE CLASSES SO THAT
		// THE CLASSES ARE MORE ORGANIZE AND EFFICIENT(DON'T HAVE TO INCLUDE SO MANY TIMES), LESS DUPLICATION OF INCLUDE code

// SelfNote: I may be making too many classes.. Classes like Score may not be needed.. We'll see. 

//==========================
// Allegro 5 
//==========================
#include <allegro5\allegro5.h>
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
#include "mappy_A5.h"

//TODO: Include all the allegro 5 header files

//=======================
// Game Objects Files 
//=======================
#include "GameObject.h"
#include "Player.h"
#include "Enemy.h"
#include "PowerUp.h"

//====================
// Collision Files 
//====================
#include "Collision.h"
#include "State.h"
#include "Score.h"
#include "Database.h"

//===================
// Input / Output  
//===================
#include "Display.h"

#include "Sound.h"


//===================
// Databases
//===================
#include <list> 
#include <set>

//===================
// Globals
//===================

// our user defined width and height that the Mario depends on, might not be const
const int SLWIDTH, STARTWIDTH, ENDWIDTH;  
const int SLHEIGH, STARTHEIGHT, ENDHEIGHT; 

int PlayerBoundX[]= {20, 20, 20, 20}; 
int PlayerBoundY[] = {20, 20, 20, 20};
int EnemyBoundX[] = {20, 20, 20, 20};
int EnemyBoundY[] = {20, 20, 20, 20};
int *BoundX[] = {PlayerBoundX, EnemyBoundX};
int *BoundY[] = {PlayerBoundY, EnemyBoundY};

//TODO: Include our formula to defined our own width and height later

// The actual width and height of the screen
const int WIDTH = 600; 
const int HEIGHT = 800; 

bool keys[] = {false, false, false, false, false};
enum KEYS{UP, DOWN, LEFT, RIGHT, SPACE};


// To be updated later
enum ID{PLAYER, ENEMY, BULLET, BORDER, MISC, EXPLOSION};
//enum KEYS{UP, DOWN, LEFT, RIGHT, SPACE}
//enum GAMESTATES{INTRO, MENU, PLAY, GAMEOVER};

typedef Bou (*ObjectArray)[5][10][15];
 ObjectArray ptr = (ObjectArray) new object[5][10][15];
 //*/