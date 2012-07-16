#include "HFILES/Display.h"

bool done = false;
bool redraw = false;
bool isGameOver = false;
bool keys[] = {false, false, false, false, false};
bool lock[] = {false, false, false, false, false};
int xOff = 0;
int yOff = 0;

Display::Display(Player *player)
{
	//kill this soon
	al_init_primitives_addon();
	Display::player = player;
	al_init_font_addon();
	al_init_ttf_addon();
	font18 = al_load_font("arial.ttf", 18, 0);
}
//

void Display::Init()
{
	cout << "DISPLAY INIT";
//modify this to print to display. 
//	cout << "Please enter your name: " << endl;
//	cin >> name;
//	cout << "Hi, " << name << " !" << endl;
}

void Display::displayMessage(int posx, int posy, string message) // Display message at x and y position of screen
{
	//why does this work? try message..c_str()
	al_draw_textf(font18, al_map_rgb(255, 255, 255), posx, posy, 0, "%s", message);
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
			redraw = false;
			if(!isGameOver)
			{
			//Draw Mario here, currently a STUB
			//TODO: insert sprite animations for all GameObjects. currently displays a white box for Mario.
				al_draw_filled_rectangle(player->getX() - 10, player->getY() - 10, 
					player->getX() + 10,player->getY() + 10, al_map_rgb(255, 255, 255));
			}
			else
			{
			//When Mario dies, execute here.
			}
			al_flip_display();
			al_clear_to_color(al_map_rgb(0,0,0));
		}
}