// This class deals with keeping track of scores of the players
#pragma once
#include "Classes.h"

class Score
{
	private:
		int score; 
		int highestScore; // Keep track of highest score
		//Display *display(x, y); 
		//Collision *collision;

		// Methods (Known as Helper Methods), not used outside this class
		void addScore(); // add score by 1
		void InitScore(); // initialize score to 0

	public: 
		// Constructor
		Score(); // Initialize score to 0 for each player

		// Methods
		void displayScore(); // Use Display class to display score
		void updateScore(); // Update own score
};