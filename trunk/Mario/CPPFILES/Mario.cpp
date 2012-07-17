// This is the main class that handles all the execution of the game
	// The actual main function will be defined in MarioApp.cpp
#include "HFILES\Mario.h"

class Mario
{
public:
		Timer *timer;
		Display *screen; 
		Keyboard *keyboard;
		//Database *database; 
		Player *player;
		Background *background;
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
			background = new Background();
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

		//Checks
		if(!al_init())										//initialize Allegro
			return -1;
		display = al_create_display(WIDTH, HEIGHT);
		if(!display)										
			exit (-1);

		//Install
		al_install_keyboard();
		al_init_image_addon();

		//Create
		event_queue = al_create_event_queue();
		clocker = al_create_timer(1.0/FPS);
		srand(time(NULL));

		//Load
		if(MapLoad("50x50.FMP", 1))
			return(-5); 
		ALLEGRO_BITMAP *BabyMario;
		BabyMario = al_load_bitmap("BabyMario 120.png");
		//Register
		al_register_event_source(event_queue, al_get_display_event_source(display));
		al_register_event_source(event_queue, al_get_keyboard_event_source());		
		al_register_event_source(event_queue, al_get_timer_event_source(clocker));

		//Object Initialization
		player->Init(0, HEIGHT, 5, 5, 1, 1, BabyMario);
		

		//Let's start it up!
		al_start_timer(clocker);
		while(!done)
		{
			ALLEGRO_EVENT ev;
			al_wait_for_event(event_queue, &ev);
			timer->updateTimer(&ev);
			keyboard->updateKeyboard(&ev);
			//This will be replaced by the updating member of database.
			player->update();
			screen->updateDisplay(event_queue, &ev);
			// GAME LOOP
		}
		delete player;
		al_destroy_event_queue(event_queue);
		timer->destroyTimer(clocker);
		al_destroy_bitmap(BabyMario);
		//screen->destroyDisplay();
		screen->destroyFont();
		MapFreeMem();
		delete timer; 
		delete keyboard;
		delete screen;
		al_destroy_display(display);
		return 0;
	}
	
}; 