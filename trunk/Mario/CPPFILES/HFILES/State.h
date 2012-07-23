// This class deals with handling the present game state.

#ifndef STATE_H
#define STATE_H

//#pragma once

#include "HFILES/Classes.h"

class State
{
private: 
	int state;
public:
	State() {state = PLAYING;}
	int getState() {return state;}
	void setState(int state) {State::state = state;}

	

/*
	private:
		enum modes{NORMAL, STRONG, SUPER, DEAD};
		int state; 
	public:
		// Constructor
		State(); 

		// Methods
		void changeState(State &state, State newState); */
};
#endif STATE_H