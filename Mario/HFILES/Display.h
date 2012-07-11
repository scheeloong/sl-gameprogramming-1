// This class handles input and output
// contains display and font initialization as well
#pragma once
#include "Classes.h"

// Main class (Mario) will have an instance of Display
class Display
{
	private:
		string name; // keeps track of name of actor playing. 
		ALLEGRO_DISPLAY *display; 
		ALLEGRO_FONT *font18;
		// font
		// background images? 
		// Mappy? 

		// Helper Methods
		void createDisplay(int width, int height);

	public:
		// Constructor
		Display(ALLEGRO_EVENT_QUEUE &event_queue)
		{

			display = NULL;
			display = al_create_display(WIDTH, HEIGHT);
			//buggy.
			al_register_event_source(&event_queue, al_get_display_event_source(display));
			al_init_font_addon();
			al_init_ttf_addon();
			font18 = al_load_font("arial.ttf", 18, 0);
		}
		void Init() // Gets actor's name
		{
			//modify this to print to display. 
			cout << "Please enter your name: " << endl;
			cin >> name >> endl;
			cout << "Hi, " << name << " !" << endl;
		}
		// Methods
		void displayMessage(int x, int y, string message) // Display message at x and y position of screen
		{
			//why does this work? try message..c_str()
			al_draw_textf(font18, al_map_rgb(255, 255, 255), x, y, 0, "%s", message);
		}
		void inputName(); // Get's actor's name and inputs into game for high score. 

		void flipDisplay()
		{
			al_flip_display();
			al_clear_to_color(al_map_rgb(0,0,0));
		}
};