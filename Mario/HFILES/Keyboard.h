//This file deals with keyboard input and links to player moving.
#pragma once
//#include "Classes.h"

class Keyboard
{
private:
	enum KEYS{UP, DOWN, LEFT, RIGHT, SPACE};
	//fifth false necessary?
	bool keys[5];
	bool lock[5];

public:
	Keyboard(ALLEGRO_EVENT_QUEUE * event_queue);
	void keyboardUpdate(ALLEGRO_EVENT &ev);

};