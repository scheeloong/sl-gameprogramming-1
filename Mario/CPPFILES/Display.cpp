#include "HFILES/Display.h"

bool done = false;
bool redraw = false;
bool isGameOver = false;
bool keys[] = {false, false, false, false, false};
bool lock[] = {false, false, false, false, false};
const float PI = 3.14159;
int xOff = 0;
int yOff = 0;

Display::Display(Database *database, State *state)
{
	Display::database = database;
	Display::state = state;
}

void Display::displayMessage(int posx, int posy, string message) // Display message at x and y position of screen
{
	//why does this work? try message..c_str()
	al_draw_textf(font, al_map_rgb(255, 255, 255), posx, posy, 0, "%s", message);
}

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
			//Layer 1 features foreground tiles such as coin and ? blocks.
			//Collision is detected on Layer 0 though.
			MapChangeLayer(1);
			MapDrawBG(xOff, yOff, 0, 0, WIDTH, HEIGHT);
			MapChangeLayer(0);
			redraw = false;
			if(state->getState() == PLAYING)
			{
				database->draw();
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
			}
			else if(state->getState() == GAMEOVER)
			{
				al_draw_filled_rectangle(0, 0, WIDTH, HEIGHT, al_map_rgb(100, 0, 100));
				al_draw_textf(font, al_map_rgb(0, 0, 255), WIDTH/2, HEIGHT/2 - 30, ALLEGRO_ALIGN_CENTRE, 
					"Restart? [R]");
				al_draw_textf(font, al_map_rgb(0, 0, 255), WIDTH/2, HEIGHT/2 + 30, ALLEGRO_ALIGN_CENTRE, 
					"Exit? [ESC]");
			}
			al_flip_display();
			al_clear_to_color(al_map_rgb(0,0,0));
		}
}