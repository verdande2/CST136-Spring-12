#include "Deck.h"

#include <iostream>

/****************************************************************
* Overview: Basic constructor and destructor
*    Input: None
*   Output: Constructor sets the contents of m_cards to the 
*			standard 52 cards, with an initial shuffle.
* Important Note: The destruction of the cards is handled 
*			ONLY by the CardCollection parent's destructor. The 
*			CardCollection's destructor is NOT virtual and does 
*			not need to be in this application.
*****************************************************************/
Deck::Deck(){
	// populate m_cards with a full 52 card deck and give it an intial shuffle
	Card* temp = 0;
	for(int suit=0; suit<Card::SUIT_COUNT; ++suit){
		for(int rank=0; rank<Card::RANK_COUNT; ++rank){
			temp = new Card(static_cast<Card::RANK>(rank), static_cast<Card::SUIT>(suit));
			m_cards.push_back(temp);
		}
	}
	Shuffle();
}

Deck::~Deck(){}


/****************************************************************
* Overview: returns a random number from 0 to n
*    Input: upper bound n
*   Output: unsigned psuedorandom int
*****************************************************************/
unsigned RandomNum(int n){
	srand(static_cast<unsigned> (time(0)));
	return rand() % n;
}

/****************************************************************
* Overview: Shuffles the cards in the deck.
*    Input: None.
*   Output: None.
*****************************************************************/
void Deck::Shuffle(){
	//std::cout << "Fisher-Yates shuffling now." << std::endl;
	std::random_shuffle(m_cards.begin(), m_cards.end(), RandomNum);
}

/****************************************************************
* Overview: Function to display the deck
*    Input: None.
*   Output: Outputs the contents of the deck, in order, to the 
*			console.
*****************************************************************/
void Deck::Display(){
	for(vector<Card*>::iterator i = m_cards.begin(); i != m_cards.end(); ++i){
		std::cout << **i << std::endl;
	}
}