/****************************************************************
* Overview: Class representing a player. Has a getter and setter 
*			for money, but all other manipulations are done via 
*			friend class PokerGame.
*    Input: None.
*   Output: Just a model, no display functions.
*****************************************************************/
#pragma once
#include "Hand.h"

class Player{
	friend class PokerGame;

	private:
		int m_money;
		Hand hand;
		void SetMoney(int money);
	protected:
	public:
		Player();
		~Player();

		int GetMoney() const;
};