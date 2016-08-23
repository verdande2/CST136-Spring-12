#ifndef DECK
#define DECK

#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <ctime>

class Card{
	friend bool Equal(Card const& card1, Card const& card2);

	private:
		const int m_suit;
		const int m_rank;
	
	public:
		Card(int suit, int rank);
		~Card();
		
		int Suit() const;
		int Rank() const;

		void Display() const;

		bool operator==(Card rhs) const;
		
		static enum SUIT{CLUBS, DIAMONDS, HEARTS, SPADES};
		static enum RANK{ACE, DEUCE, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING};
};

class Deck{
	private:
		Card** m_cards;
		int m_remainingCardCount;

	public:
		Deck();
		~Deck();
		
		void Shuffle();
		Card* Draw();
		void Add(Card* card);

		bool InDeck(Card const& card);

		int RemainingCards();
};

#endif