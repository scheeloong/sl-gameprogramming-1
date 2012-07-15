#include "HFILES/State.h"

// defining methods
//*/

State::State()
{
	state = NORMAL; 
}

void State::changeState(State &state, State newState)
{
	// Entering State



	state = newState;

	// Leaving state 
}