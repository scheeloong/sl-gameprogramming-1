#include "HFILES/Display.h"

Display::Display(ALLEGRO_EVENT_QUEUE *event_queue, Player *player)
{
	Display::player = player;
	display = NULL;
	display = al_create_display(WIDTH, HEIGHT);
	//immediately stop program should an error occur
	if(!display)										
		exit (-1);
	al_register_event_source(event_queue, al_get_display_event_source(display));
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



void Display::updateDisplay(ALLEGRO_EVENT_QUEUE *event_queue)
{
	if(redraw && al_is_event_queue_empty(event_queue))
		{
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