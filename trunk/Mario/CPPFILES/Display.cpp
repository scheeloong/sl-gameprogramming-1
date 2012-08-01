#include "HFILES/Display.h"

//==============
// Attributes
//==============
bool done = false;
bool redraw = false;
bool isGameOver = false;
bool keys[] = {false, false, false, false, false};
bool lock[] = {false, false, false, false, false};
const float PI = 3.14159;
int xOff = 0;
int yOff = 0;
int playerVelX = 0;
int oldXOff = 0;
int deltaXOff = 0;
bool isMoved = false;

//==============
// Constructor
//==============
Display::Display(Database *database, State *state)
{
	Display::database = database;
	Display::state = state;
}

//==============
// Methods
//==============

// This function ...
void Display::displayScore(int posx, int posy) // Display message at x and y position of screen
{
	for(database->iterP = database->getPlayersBegin(); database->iterP != database->getPlayersEnd(); database->iterP++) 
		al_draw_textf(font, al_map_rgb(0, 0, 0), 5, 5, 0, "Score: %i", (*(database->iterP))->getScore());
}

//----------------------------------------------------------------------------------------------------------------------
// This function ...
void Display::updateDisplay(ALLEGRO_EVENT_QUEUE *event_queue, ALLEGRO_EVENT *ev)
{
	if(ev->type == ALLEGRO_EVENT_DISPLAY_CLOSE)
	{
		done = true;
	}
	if(redraw && al_is_event_queue_empty(event_queue))
		{
			//xOff and yOff as defined in classes.h 
			MapDrawBG(xOff, yOff, 0, 0, WIDTH, HEIGHT);
			MapDrawFG(xOff, yOff, 0, 0, WIDTH, HEIGHT, 0);
			MapDrawFG(xOff, yOff, 0, 0, WIDTH, HEIGHT, 1);
		/*	MapDrawBG(0, 0, xOff, yOff, WIDTH, HEIGHT);
			MapDrawFG(0, 0, xOff, yOff, WIDTH, HEIGHT, 0);
			MapDrawFG(0, 0, xOff, yOff, WIDTH, HEIGHT, 1);*/
			//Layer 1 features foreground tiles such as coin and ? blocks.
			//Collision is detected on Layer 0 though.
			MapChangeLayer(1);
			MapDrawBG(0, 0, xOff, yOff, WIDTH, HEIGHT);
		//	MapDrawBG(xOff, yOff, 0, 0, WIDTH, HEIGHT);
			MapChangeLayer(0);
			redraw = false;
			if(state->getState() == PLAYING)
			{
				database->draw();
				displayScore(5, 5);
			}
			else if(state->getState() == PAUSE)
			{
				// Still draw a still image of gameplay in the back.
				database->draw();
				// display gray screen with options.
				al_draw_filled_rectangle(0, 0, WIDTH, HEIGHT, al_map_rgba(100, 0, 100, 100));
				al_draw_textf(font, al_map_rgb(0, 0, 255), WIDTH/2, HEIGHT/2 - 30, ALLEGRO_ALIGN_CENTRE, 
					"Resume? [R]");
				al_draw_textf(font, al_map_rgb(0, 0, 255), WIDTH/2, HEIGHT/2 + 30, ALLEGRO_ALIGN_CENTRE, 
					"Stop Playing? [ESC]");
				displayScore(5, 5);
			}
			else if(state->getState() == GAMEOVER)
			{
				al_draw_filled_rectangle(0, 0, WIDTH, HEIGHT, al_map_rgb(100, 0, 100));
				al_draw_textf(font, al_map_rgb(255, 255, 255), WIDTH / 2, HEIGHT / 2 - 100, ALLEGRO_ALIGN_CENTRE, "GAME OVER!");
				al_draw_textf(font, al_map_rgb(0, 0, 255), WIDTH/2, HEIGHT/2 - 30, ALLEGRO_ALIGN_CENTRE, 
					"Restart? [R]");
				al_draw_textf(font, al_map_rgb(0, 0, 255), WIDTH/2, HEIGHT/2 + 30, ALLEGRO_ALIGN_CENTRE, 
					"Exit? [ESC]");
				displayScore(5, 5);
			}
			al_flip_display();
			al_clear_to_color(al_map_rgb(0,0,0));
		}
}