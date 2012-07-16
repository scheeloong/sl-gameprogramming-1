//This file deals with keyboard input and links to player moving.

#ifndef KEYBOARD_H
#define KEYBOARD_H
//#pragma once

#include "HFILES\Classes.h"

extern bool done;

class Keyboard
{
public:
	//Keyboard(ALLEGRO_EVENT_QUEUE *event_queue);
	void updateKeyboard(ALLEGRO_EVENT *ev);
};

#endif KEYBOARD_H