// This is the main class that handles all the execution of the game
	// The actual main function will be defined in MarioApp.cpp
#include "Mario.h" 

class Mario
{
	private:
		int x; // temporary
	public:
	// Constructor
		Mario() : x(0) {}

	// Methods
	void run() 
	{
		ALLEGRO_EVENT_QUEUE *event_queue = NULL;
		// Initialize EVERYTHING: 
		// ALLEGRO init!!
		// ALLEGRO addon!! 
					  /*al_install_keyboard();
						al_init_image_addon();
						al_init_font_addon();
						al_init_ttf_addon();
						al_init_primitives_addon();
						al_install_audio();
						al_init_acodec_addon();*/
		// ALLEGRO LOAD RESOURCES!! (SOUND, FONT, IMAGES)
		// EVENT QUEUE AND TIMER
		// i) Display
		// ii) Player
		// iii) Sound
		// iv) Background
		// v) Timer
		// vi) Event Queue

		// This function handles everything, it is used to run the whole game. 
		// the game loop is contained in here
		while(true)
		{
			// GAME LOOP
		}
	}
}; 