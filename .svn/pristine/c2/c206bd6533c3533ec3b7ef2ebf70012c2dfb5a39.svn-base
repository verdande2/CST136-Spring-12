/****************************************************************
* Overview: Standard 5 card poker hand. Essentially a 5 card 
*			CardCollection, with the addition of methods of 
*			dealing with held cards.
*    Input: None.
*   Output: None.
*****************************************************************/
#pragma once

#include "CardCollection.h"

class Hand : public CardCollection {
	friend class PokerGame;
	friend class PokerScreen;
	
	private:
		bool m_holds[5];
		short m_holdsCount;
	protected:
	public:
		Hand();
		~Hand();

		void ToggleHold(int i);
};