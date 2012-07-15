//This file deals with keyboard input and links to player moving.
#pragma once
#include "HFILES\Classes.h"

class Keyboard
{
public:
	Keyboard(ALLEGRO_EVENT_QUEUE *event_queue);
	void updateKeyboard(ALLEGRO_EVENT &ev);
};