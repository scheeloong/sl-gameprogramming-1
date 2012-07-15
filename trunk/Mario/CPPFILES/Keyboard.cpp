/*//
#include "HFILES/Keyboard.h"

Keyboard::Keyboard(ALLEGRO_EVENT_QUEUE *event_queue)
{
	al_install_keyboard();
	al_register_event_source(event_queue, al_get_keyboard_event_source());
}

void Keyboard::updateKeyboard(ALLEGRO_EVENT &ev)
{
	
	if(ev.type == ALLEGRO_EVENT_KEY_DOWN)
	{
		switch(ev.keyboard.keycode)
		{
		case ALLEGRO_KEY_ESCAPE:
			done = true;
			break;
		case ALLEGRO_KEY_LEFT:
			keys[LEFT] = true;
			break;
		case ALLEGRO_KEY_RIGHT:
			keys[RIGHT] = true;
			break;
		case ALLEGRO_KEY_UP:
			keys[UP] = true;
			break;
		case ALLEGRO_KEY_DOWN:
			keys[DOWN] = true;
			break;
		case ALLEGRO_KEY_SPACE:
			keys[SPACE] = true;
			break;
		}
	}
	else if(ev.type == ALLEGRO_EVENT_KEY_UP)
	{
		switch(ev.keyboard.keycode)
		{
		case ALLEGRO_KEY_ESCAPE:
			done = true;
			break;
		case ALLEGRO_KEY_LEFT:
			keys[LEFT] = false;
			break;
		case ALLEGRO_KEY_RIGHT:
			keys[RIGHT] = false;
			break;
		case ALLEGRO_KEY_UP:
			keys[UP] = false;
			break;
		case ALLEGRO_KEY_DOWN:
			keys[DOWN] = false;
			break;
		case ALLEGRO_KEY_SPACE:
			keys[SPACE] = false;
			break;
		}
	}
}
//*/