//This file deals with keyboard input and links to player moving.
#pragma once
#include "Classes.h"

class Keyboard
{
private:
	enum KEYS{UP, DOWN, LEFT, RIGHT, SPACE};
	//fifth false necessary?
	bool keys[5];
	bool lock[5];
public:
	Keyboard()
	{
		//initialize both bool arrays
		for (int i = 0; i < 6; i++)
		{
			keys[i] = false;
			lock[i] = false;
		}

		al_install_keyboard();
		al_register_event_source(event_queue, al_get_keyboard_event_source());


	}

	void keyboardUpdate(ALLEGRO_EVENT_QUEUE &ev);

};