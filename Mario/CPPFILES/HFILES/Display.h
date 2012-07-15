// This class contains display and font initialization.
#pragma once
#include "Classes.h"

// Main class (Mario) will have an instance of Display
class Display
{
	private:
		//string name; // keeps track of name of actor playing. 
		ALLEGRO_DISPLAY *display; 
		ALLEGRO_FONT *font18;
		Player *player;
		// font
		// background images? 
		// Mappy? 

		// Helper Methods
		//void createDisplay(int width, int height); I think this is done in constructor.

	public:
		// Constructor
		Display(ALLEGRO_EVENT_QUEUE *event_queue, Player *player = NULL);
		void Init(); // Gets actor's name
		// Methods
		//void displayMessage(int posx, int posy, string message);
		void inputName(); // Get's actor's name and inputs into game for high score. 
		void updateDisplay(ALLEGRO_EVENT_QUEUE *event_queue);
		void destroyFont() {al_destroy_font(font18);}
		void destroyDisplay() {al_destroy_display(display);}
};