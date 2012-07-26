//
// This class contains display and font initialization.
#ifndef DISPLAY_H
#define DISPLAY_H
//#pragma once
#include "HFILES/Classes.h"
#include "HFILES/Database.h"
#include "State.h"
// Main class (Mario) will have an instance of Display
class Display
{
	private:
		//string name; // keeps track of name of actor playing. 
		//ALLEGRO_DISPLAY *display; 
		ALLEGRO_FONT *font;
		Database *database;
		State *state;
		// font
		// background images? 
		// Mappy? 

		// Helper Methods
		//void createDisplay(int width, int height); I think this is done in constructor.

	public:
		// Constructor
		Display(Database *database = NULL, State *state = NULL);
		void initFont(ALLEGRO_FONT *font) {Display::font = font;} // Gets actor's name
		// Methods
		void displayScore(int x, int y);
		void inputName(); // Get's actor's name and inputs into game for high score. 
		void updateDisplay(ALLEGRO_EVENT_QUEUE *event_queue, ALLEGRO_EVENT *ev);
		void destroyFont() {al_destroy_font(font);}
		//void destroyDisplay() {al_destroy_display(display);}
};

#endif DISPLAY_H
//*/