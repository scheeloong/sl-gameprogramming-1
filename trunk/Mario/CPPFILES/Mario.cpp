// This is the main class that handles all the execution of the game
	// The actual main function will be defined in MarioApp.cpp
#include "HFILES\Mario.h"
		//extern bool	redraw = false;
		//extern bool	isGameOver = false;
class Mario
{
public:
		Timer *timer;
		Display *screen; 
		Keyboard *keyboard;
		//Database *database; 
		Player *player;
		//static ALLEGRO_DISPLAY *display;
	// Constructor
		Mario()
		{
			//clocker = NULL;
			//event_queue = NULL;
			//done = false;

			player = new Player();
			timer = new Timer(player);
			screen = new Display(player);
			keyboard = new Keyboard();
		}
	// Methods
	int run() 
	{
		// Initialize EVERYTHING: 
		// ALLEGRO init!!
		// ALLEGRO addon!! 
//				        al_install_keyboard();
//						al_init_image_addon();
//						al_init_font_addon();
//						al_init_ttf_addon();
//						al_init_primitives_addon();
//						al_install_audio();
//						al_init_acodec_addon();
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
		if(!al_init())										//initialize Allegro
			return -1;
		display = al_create_display(WIDTH, HEIGHT);
		if(!display)										
			exit (-1);
		event_queue = al_create_event_queue();
		al_register_event_source(event_queue, al_get_display_event_source(display));

		al_install_keyboard();
		al_register_event_source(event_queue, al_get_keyboard_event_source());

		clocker = al_create_timer(1.0/FPS);
		srand(time(NULL));
		al_register_event_source(event_queue, al_get_timer_event_source(clocker));
		al_start_timer(clocker);
		while(!done)
		{
			ALLEGRO_EVENT ev;
			al_wait_for_event(event_queue, &ev);
			timer->updateTimer(&ev);
			keyboard->updateKeyboard(&ev);
			screen->updateDisplay(event_queue, &ev);
			// GAME LOOP
		}
		delete player;
		al_destroy_event_queue(event_queue);
		timer->destroyTimer(clocker);
		//screen->destroyDisplay();
		screen->destroyFont();
		
		delete timer; 
		delete keyboard;
		delete screen;
		al_destroy_display(display);
		return 0;
	}
	
}; 