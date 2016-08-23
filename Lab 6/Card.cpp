#include "Card.h"

ostream& operator<<(ostream& stream, Card const& card);

const char* Card::suits[] = {"Clubs","Diamonds","Hearts","Spades"};
const char* Card::ranks[] = {"Ace","Deuce","Three","Four","Five","Six","Seven","Eight","Nine","Ten","Jack","Queen","King"};
const char* Card::short_suits[] = {"\5", "\4", "\3", "\6"};
const char* Card::short_ranks[] = {"A","2","3","4","5","6","7","8","9","10","J","Q","K"};

const char* Card::Rank() const {return Card::short_ranks[m_rank];}
const char* Card::Suit() const {return Card::short_suits[m_suit];}


/****************************************************************
* Overview: Basic constructor and destructors
*    Input: rank and suit of the card to be made. Note: Can be passed in either order.
*   Output: None.
*****************************************************************/
Card::Card(RANK rank, SUIT suit) : m_rank(rank), m_suit(suit) {}
Card::Card(SUIT suit, RANK rank) : m_suit(suit), m_rank(rank) {}
Card::~Card(){}

/****************************************************************
* Overview: Overloaded operator<< to display a card in console.
*    Input: stream, ostream ref, and card, Card const&
*   Output: card is displayed to console.
*****************************************************************/
ostream& operator<<(ostream& stream, Card const& card){
	stream << Card::short_suits[card.m_suit] << Card::short_ranks[card.m_rank];
	return stream;
}

/****************************************************************
* Overview: == comparison operator for two card objects
*    Input: right is the right hand side of the ==
*   Output: returns a bool representing equality
*****************************************************************/
bool Card::operator==(Card const& right){
	return (m_rank==right.m_rank && m_suit==right.m_suit);
}