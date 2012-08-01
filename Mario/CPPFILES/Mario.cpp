// This is the main class that handles all the execution of the game
	// The actual main function will be defined in MarioApp.cpp
#include "HFILES\Mario.h"
#include <allegro5/allegro_acodec.h>

class Mario
{
public:
	Timer *timer;
	Display *screen; 
	Keyboard *keyboard;
	//Database *database; 
	Player *player;
	Goomba *goomba;
	State *state;
	Background *background;
	Collision *collision;
	Database *database;
	bool reloadedMap;
	// Constructor
	Mario()
	{
		//clocker = NULL;
		//event_queue = NULL;
		//done = false;
		state = new State();
		database = new Database(state);
		/*player = new Player(); obscelete due to database implementation
		goomba = new Goomba();*/
		timer = new Timer(database, state);
		screen = new Display(database, state);
		keyboard = new Keyboard(state);
		background = new Background();
		collision = new Collision(database);
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
		al_init_primitives_addon();
		al_init_font_addon();
		al_init_ttf_addon();
	

		//Create
		event_queue = al_create_event_queue();
		clocker = al_create_timer(1.0/FPS);
		srand(time(NULL));
		
		//Load
		ALLEGRO_BITMAP *Mario = NULL;
		ALLEGRO_BITMAP *Goomba = NULL;
		ALLEGRO_BITMAP *KoopaTroopa = NULL;
		ALLEGRO_BITMAP *PowerUps = NULL;
		ALLEGRO_BITMAP *DeadQuestion = NULL;
		ALLEGRO_BITMAP *Sky = NULL;
		ALLEGRO_BITMAP *DeadBrick = NULL;
		ALLEGRO_FONT *font18 = NULL;
		if(MapLoad("50x50.FMP", 1))
			exit(-5); 
		//The images below MUST be stored in the Mario folder, and NOT in Resources.
		Mario = al_load_bitmap("MarioGenerations 120.png");
		Goomba = al_load_bitmap("Goomba 120.png");
		KoopaTroopa = al_load_bitmap("KoopaTroopa 120.png");
		PowerUps = al_load_bitmap("PowerUps 50x100.png");
		DeadQuestion = al_load_bitmap("DeadQuestion 50x100.png");
		Sky = al_load_bitmap("Sky 50x100.png");
		DeadBrick = al_load_bitmap("DeadBrick 50x100.png");
		font18 = al_load_font("Arial.ttf", 18, 0);

		//Register
		al_register_event_source(event_queue, al_get_display_event_source(display));
		al_register_event_source(event_queue, al_get_keyboard_event_source());		
		al_register_event_source(event_queue, al_get_timer_event_source(clocker));
		//Object Initialization
		database->InitImages(Mario, Goomba, KoopaTroopa, PowerUps, DeadQuestion, Sky, DeadBrick);
		database->makePlayer(WIDTH/2 - 200, HEIGHT/2, 5, 5, 1, 1, true);
		screen->initFont(font18);
		//Let's start it up!
		al_start_timer(clocker);
		while(!done)
		{
			oldXOff = xOff;
			ALLEGRO_EVENT ev;
			al_wait_for_event(event_queue, &ev);
			timer->updateTimer(&ev);
			collision->checkCollision();
			keyboard->updateKeyboard(&ev);
			// only update state of database if we're in play mode.
			if(state->getState() == PLAYING) {database->update(); reloadedMap = false;}
			screen->updateDisplay(event_queue, &ev);
			if(state->getState() == GAMEOVER && !reloadedMap) reloadMap();
			deltaXOff = xOff - oldXOff;
		}
		
		database->deleteDatabase();
		al_destroy_event_queue(event_queue);
		timer->destroyTimer(clocker);
		//THIS LINE WILL CAUSE CRASH! Because the bitmap was 
		//already destroyed in player->destroy()
		//I've left the remains here so we don't make the same 4 hour mistake.
		//al_destroy_bitmap(BabyMario);
		//screen->destroyDisplay();
		screen->destroyFont();
		MapFreeMem();
		delete database;
		delete timer; 
		delete keyboard;
		delete screen;		
		delete collision;
		al_destroy_bitmap(Mario);
		al_destroy_bitmap(Goomba);
		al_destroy_bitmap(KoopaTroopa);
		al_destroy_bitmap(PowerUps);
		al_destroy_bitmap(DeadQuestion);
		al_destroy_bitmap(Sky);
		al_destroy_bitmap(DeadBrick);
		al_destroy_display(display);
		return 0;
	}	

	void reloadMap()
	{
		MapFreeMem();
		if(MapLoad("50x50.FMP", 1))
			exit(-5); 
		reloadedMap = true;
		xOff = 0;
		yOff = 0;
	}
}; 