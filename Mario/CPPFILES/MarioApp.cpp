// This class is the User_Interface file. 
// It is used to test that the Mario Game is working

// Maybe the GameStates (Like StartGame, QuitGame can be handled here) 

#include "Mario.cpp"
class MarioApp
{
	private:
		Mario mario; 
	public: 
		// Constructor

		// Main Function
		int main(void)
		{
			mario.run(); 
		}
};