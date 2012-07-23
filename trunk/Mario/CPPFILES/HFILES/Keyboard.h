//This file deals with keyboard input and links to player moving.

#ifndef KEYBOARD_H
#define KEYBOARD_H
//#pragma once

#include "HFILES\Classes.h"
#include "State.h"
class Keyboard
{
private:
	State *state;
public:
	Keyboard(State *state) {Keyboard::state = state;}
	void updateKeyboard(ALLEGRO_EVENT *ev);
};

#endif KEYBOARD_H