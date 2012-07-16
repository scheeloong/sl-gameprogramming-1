//
// This class is the User_Interface file. 
// It is used to test that the Mario Game is working
// Maybe the GameStates (Like StartGame, QuitGame can be handled here) 
#include "Mario.cpp"

// TEMPORARY FILE FOR TRYING OUT BUILD IS WORKING IN VISUAL STUDIO 2010
#include <stdio.h>
#include <iostream>
#include <time.h>
#include "HFILES\Classes.h"
//===================================
// For now, just use main function,
// instead of making MarioApp
// a class for compiler to know
// where main function is
//===================================

void sleep(long d)
{
	clock_t start = clock();
	while(clock() - start < d); ///loop until time's up
}
	Mario *mario = new Mario();
	
	
// currently infinite loop before anything even happens
int main()
{
	__EXTERN(bool , done, false);
	__EXTERN(bool , redraw, false);
	__EXTERN(bool , isGameOver, false);
	printf("hahahaa\n");
	//sleep(1000000000000000);	
	mario->run();
	return 0;
}

// undefined reference to main if used this for now. Not using Main Function properly
/*
class MarioApp
{
	private:
		Mario mario; 
	public: 
		// Constructor

		// Main Function
		int main()
		{
			printf("hahaa\n"); // for debugging 
			//mario.run(); 
			return 5000; 
		}
};
*/