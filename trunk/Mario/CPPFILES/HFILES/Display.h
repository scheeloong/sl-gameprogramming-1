//
// This class contains display and font initialization.
#ifndef DISPLAY_H
#define DISPLAY_H
//#pragma once
#include "HFILES/Classes.h"
#include "HFILES/Player.h"
#include "HFILES/Enemy.h"

//only truified when player lives are over.
// Main class (Mario) will have an instance of Display
class Display
{
	private:
		//string name; // keeps track of name of actor playing. 
		//ALLEGRO_DISPLAY *display; 
		ALLEGRO_FONT *font18;
		Player *player;
		Enemy *enemy;
		// font
		// background images? 
		// Mappy? 

		// Helper Methods
		//void createDisplay(int width, int height); I think this is done in constructor.

	public:
		// Constructor
		Display(Player *player = NULL, Enemy *enemy = NULL);
		void Init(); // Gets actor's name
		// Methods
		void displayMessage(int posx, int posy, string message);
		void inputName(); // Get's actor's name and inputs into game for high score. 
		void updateDisplay(ALLEGRO_EVENT_QUEUE *event_queue, ALLEGRO_EVENT *ev);
		void destroyFont() {al_destroy_font(font18);}
		//void destroyDisplay() {al_destroy_display(display);}
};

#endif DISPLAY_H
//*/