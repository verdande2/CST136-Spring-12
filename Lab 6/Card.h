/****************************************************************
* Overview: The Card class models a standard playing card.
*    Input: On instantiation, it takes in a rank and suit and 
*			they remain const.
*   Output: Has a operator<< to display a card, and has static 
*			arrays of const char*s to display rank/suit names in 
*			a human readable form.
*****************************************************************/
#pragma once
#include <string>
#include <iostream>
using std::string;
using std::ostream;

class Card{
	friend ostream& operator<<(ostream& stream, Card const& card);
	public:
		static enum SUIT{SUIT_CLUBS, SUIT_DIAMONDS, SUIT_HEARTS, SUIT_SPADES, SUIT_COUNT};
		static enum RANK{RANK_ACE, RANK_DEUCE, RANK_THREE, RANK_FOUR, RANK_FIVE, RANK_SIX, RANK_SEVEN, RANK_EIGHT, RANK_NINE, RANK_TEN, RANK_JACK, RANK_QUEEN, RANK_KING, RANK_COUNT};
		
		Card(RANK rank, SUIT suit);
		Card(SUIT suit, RANK rank);
		~Card();

		bool operator==(Card const& right);

		const char* Card::Rank() const;
		const char* Card::Suit() const;

		static const char* suits[];
		static const char* ranks[];
		static const char* short_suits[];
		static const char* short_ranks[];

		const SUIT m_suit;
		const RANK m_rank;
	private:
	protected:
};