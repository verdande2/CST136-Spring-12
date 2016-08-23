/****************************************************************
* Overview: PokerScreen models the output screen for a PokerGame.
*    Input: On instantion, takes in a pointer to the game 
*			associated with it.
*   Output: Has a Display method that will update the display screen.
*****************************************************************/
#pragma once

#include "Card.h"
#include "Hand.h"

#include <iostream>
using std::endl;
using std::cout;

#include "PokerGame.h"

const int SCREEN_WIDTH = 50;
const int SCREEN_HEIGHT = 4;
const int CARD_WIDTH = 5;

class PokerScreen{
	friend class PokerGame;

	private:
		char m_screen[SCREEN_HEIGHT][SCREEN_WIDTH];

		PokerGame* m_game;

		void UpdateScreen();
		char Prompt(const char* promptText);

	protected:

	public:
		PokerScreen();
		~PokerScreen();

		void Display();
		
		void SetCard(int i, Card const& card);
		void ToggleHold(int i);
};

