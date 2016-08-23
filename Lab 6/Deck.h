/****************************************************************
* Overview: Class representing a standard 52 card playing card 
*			deck. No jokers. Has all the methods a standard 
*			cardcollection has, as well as shuffle, and a debug 
*			function to display the deck. When constructed, the 
*			deck is filled with the standard 4 suits and 13 ranks 
*			and given an intial shuffle.
*    Input: None.
*   Output: Display is a debug function that can display the deck's 
*			contents.
*****************************************************************/
#pragma once
#include "CardCollection.h"

#include <algorithm>
#include <ctime>
#include <cstdlib>

class Deck : public CardCollection{
	friend class PokerGame;

	private:
	protected:
	public:
		Deck();
		~Deck();

		void Shuffle();

		void Display();
};