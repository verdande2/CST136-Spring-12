/****************************************************************
* Overview: Base class for a collection of cards, such as a hand, 
*			a deck or a discard pile, etc. Has several utility 
*			functions such as Add/Draw (which work like push and 
*			pop), Replace, and Counting function to count instances 
*			of cards.
*    Input: None required. 
*   Output: This class is just a base model, it doesn't contain 
*			any output methods.
*****************************************************************/
#pragma once
#include "Card.h"
#include <vector>
using std::vector;

class CardCollection{
	private:
	protected:
		std::vector<Card*> m_cards;
	public:
		CardCollection();
		~CardCollection();

		void Add(Card* card);
		Card* Draw();

		void Replace(Card*& search, Card*& replacement);

		int Count(Card const& needle, bool invert = false);
		int Count(Card::RANK rank, Card::SUIT suit, bool invert = false);
		int Count(Card::SUIT suit, Card::RANK rank, bool invert = false);
		int Count(Card::RANK rank, bool invert = false);
		int Count(Card::SUIT suit, bool invert = false);

		int Length() const;
};

