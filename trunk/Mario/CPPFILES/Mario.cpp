// This is the main class that handles all the execution of the game
	// The actual main function will be defined in MarioApp.cpp
#include "HFILES\Mario.h"

class Mario
{
	private:
		Timer *timer;
		Display *display; 
		Keyboard *keyboard;
		Database *database; 
		Player *player;
	public:
	// Constructor
		Mario()
		{
			timer = new Timer(player, clocker, event_queue);
			player = new Player();
			display = new Display(event_queue, player);
			keyboard = new Keyboard(event_queue);
		}
	// Methods
	void run() 
	{
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
		// Keyboard NOTE: delete keyboard at end.
		al_start_timer(clocker);
		while(!done)
		{
			ALLEGRO_EVENT ev;
			al_wait_for_event(event_queue, &ev);
			timer->updateTimer(ev);
			keyboard->updateKeyboard(ev);
			display->updateDisplay(event_queue);
			// GAME LOOP
		}
		delete player;
		al_destroy_event_queue(event_queue);
		timer->destroyTimer(clocker);
		display->destroyDisplay();
		display->destroyFont();
		delete timer; 
		delete keyboard;
		delete display;
	}
}; 