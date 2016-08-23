/****************************************************************
* Overview: This class represents a game of video poker. It has 
*			methods dealing with each phase of a game of video 
*			poker, as well as some static variables that contain 
*			payout and displayname information. After 
*			instantiation, the game is started via a call to Start().
*    Input: Class will ask for player's bet, during the draw phase, 
*			player may toggle card holds, and there is also a menu 
*			after a hand is over.
*   Output: Output is all to console and handled mostly by 
*			PokerScreen.Display() calls.
*****************************************************************/
#pragma once
#include "CardCollection.h"
#include "Deck.h"
#include "Hand.h"
#include "Player.h"
#include "PokerScreen.h"
#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <iomanip>
using std::cout;
using std::cin;
using std::setw;
using std::setprecision;
using std::endl;
using std::ios;

class PokerGame{
	friend class PokerScreen;

	private:
		Deck m_deck;
		CardCollection m_discardPile;
		Hand m_playerHand;

		Player m_player;

		PokerScreen* m_screen;

		int m_bet;

		static enum pokerHands {HAND_ROYAL_FLUSH, HAND_STRAIGHT_FLUSH, HAND_FOUR_OF_A_KIND, HAND_FULL_HOUSE, HAND_FLUSH, HAND_STRAIGHT, HAND_THREE_OF_A_KIND, HAND_TWO_PAIR, HAND_PAIR, HAND_COUNT};
		static int payouts[];
		static const char* HandNames[];

	protected:
	public:
		PokerGame();
		~PokerGame();

		void Start();
		int Menu();
		void GetBet();
		void Deal();
		void Draw();
		void DetermineWinner();
		void DisplayPayouts();

		void DisplayTable();
};

