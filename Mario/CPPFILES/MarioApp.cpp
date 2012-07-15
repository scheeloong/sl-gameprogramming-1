//
// This class is the User_Interface file. 
// It is used to test that the Mario Game is working
// Maybe the GameStates (Like StartGame, QuitGame can be handled here) 

// TEMPORARY FILE FOR TRYING OUT BUILD IS WORKING IN VISUAL STUDIO 2010
//#include <stdio.h>
//int main()
//{
//	printf("hahahaa\n");
//}


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
