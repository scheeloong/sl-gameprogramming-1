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
	Goomba *goomba;
	Background *background;
	Collision *collision;
	// Constructor
	Mario()
	{
		//clocker = NULL;
		//event_queue = NULL;
		//done = false;

		player = new Player();
		goomba = new Goomba();
		timer = new Timer(player, goomba);
		screen = new Display(player, goomba);
		keyboard = new Keyboard();
		background = new Background();
		collision = new Collision(player, goomba);
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
		ALLEGRO_BITMAP *Goomba;
		
		BabyMario = al_load_bitmap("BabyMario 120.png");
		Goomba = al_load_bitmap("Goomba 120.png");

		//Register
		al_register_event_source(event_queue, al_get_display_event_source(display));
		al_register_event_source(event_queue, al_get_keyboard_event_source());		
		al_register_event_source(event_queue, al_get_timer_event_source(clocker));

		//Object Initialization
		player->Init(WIDTH/2, HEIGHT/2, 5, 5, 1, 1, BabyMario);
		goomba->Init(WIDTH/2, HEIGHT/2, -2, 0, 1, 1, Goomba);

		//Let's start it up!
		al_start_timer(clocker);
		while(!done)
		{
			ALLEGRO_EVENT ev;
			al_wait_for_event(event_queue, &ev);
			timer->updateTimer(&ev);
			collision->checkCollision();
			keyboard->updateKeyboard(&ev);
			//This will be replaced by the updating member of database.
			player->update();
			goomba->update();
			screen->updateDisplay(event_queue, &ev);
			// GAME LOOP
		}
		
		player->destroy();
		goomba->destroy();
		al_destroy_event_queue(event_queue);
		timer->destroyTimer(clocker);
		//THIS LINE WILL CAUSE CRASH! Because the bitmap was 
		//already destroyed in player->destroy()
		//I've left the remains here so we don't make the same 4 hour mistake.
		//al_destroy_bitmap(BabyMario);
		//screen->destroyDisplay();
		screen->destroyFont();
		MapFreeMem();
		delete player;
		delete goomba;
		delete timer; 
		delete keyboard;
		delete screen;		
		delete collision;
		al_destroy_display(display);
		return 0;
	}	
}; 