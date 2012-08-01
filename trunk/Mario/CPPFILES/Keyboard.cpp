#include "HFILES/Keyboard.h"

//=================
// Methods
//=================

// This function updates the input from the keyboard.
void Keyboard::updateKeyboard(ALLEGRO_EVENT *ev)
{
	// Key pressed
	if(ev->type == ALLEGRO_EVENT_KEY_DOWN)
	{
		switch(ev->keyboard.keycode)
		{
		case ALLEGRO_KEY_ESCAPE:
			keys[ESC] = true;
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
		case ALLEGRO_KEY_R:
			keys[R] = true;
			break;
		}
	}
	// Key released
	else if(ev->type == ALLEGRO_EVENT_KEY_UP)
	{
		switch(ev->keyboard.keycode)
		{
		case ALLEGRO_KEY_ESCAPE:
			keys[ESC] = false;
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
		case ALLEGRO_KEY_R:
			keys[R] = false;
			break;
		}
	}
}