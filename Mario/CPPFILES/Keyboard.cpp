#include "HFILES/Keyboard.h"

void Keyboard::updateKeyboard(ALLEGRO_EVENT *ev)
{
	cout << "updating keyboard" <<endl;
	if(ev->type == ALLEGRO_EVENT_KEY_DOWN)
	{
		switch(ev->keyboard.keycode)
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
	else if(ev->type == ALLEGRO_EVENT_KEY_UP)
	{
		switch(ev->keyboard.keycode)
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