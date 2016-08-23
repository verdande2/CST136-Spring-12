#include "Deck.h"

/****************************************************************
* Overview: Basic constructor and destructor
*
*    Input: suit and rank for constructor
*
*   Output: 
*****************************************************************/
Card::Card(int suit, int rank) : m_suit(suit), m_rank(rank) {}
Card::~Card(){}

/****************************************************************
* Overview: determines if two cards are equal
*
*    Input: two cards
*
*   Output: bool representing equality
*****************************************************************/
bool Equal(Card const& card1, Card const& card2){
	return (card1.m_rank == card2.m_rank) && (card1.m_suit == card2.m_suit);
}

/****************************************************************
* Overview: returns a random number from 0 to n
*
*    Input: upper bound n
*
*   Output: unsigned psuedorandom int
*****************************************************************/
unsigned RandomNum(int n){
	srand(static_cast<unsigned> (time(0)));
	return rand() % n;
}
/****************************************************************
* Overview: Getter for suit and rank
*
*    Input: none
*
*   Output: returns the suit/rank
*****************************************************************/
int Card::Suit() const{
	return m_suit;
}

int Card::Rank() const{
	return m_rank;
}

/****************************************************************
* Overview: basic display function, outputs human readable
*
*    Input: none
*
*   Output: displays the card to console
*****************************************************************/
void Card::Display() const{
	const char* ranks[] = {"Ace","Two","Three","Four","Five","Six","Seven","Eight","Nine","Ten","Jack","Queen","King"};
	const char* suits[] = {"Clubs","Diamonds","Hearts","Spades"};
	std::cout << ranks[m_rank] << " of " << suits[m_suit];
}

/****************************************************************
* Overview: This function constructs a deck with 52 cards and shuffles
*
*    Input: none
*
*   Output: deck is 52 standard cards shuffled
*****************************************************************/
Deck::Deck() : m_cards(0), m_remainingCardCount(0) {
	Card* temp = 0;
	for(int suit=0; suit<4; ++suit){
		for(int rank=0; rank<13; ++rank){
			temp = new Card(suit,rank);
			Add(temp);
		}
	}
	Shuffle();
}

/****************************************************************
* Overview: deck destructor
*
*    Input: none
*
*   Output: deletes all the memory allocated for cards
*****************************************************************/
Deck::~Deck(){
	for(int i=0; i<m_remainingCardCount; ++i){
		delete m_cards[i];
	}
	delete [] m_cards;
}

/****************************************************************
* Overview: Shuffles the deck of cards. 
*
*    Input: none
*
*   Output: deck is shuffled.
*****************************************************************/
void Deck::Shuffle(){
	std::cout << "Fisher-Yates shuffling now." << std::endl;
	std::random_shuffle(m_cards, m_cards+m_remainingCardCount, RandomNum);
}

/****************************************************************
* Overview: This func draws a card from end of deck
*
*    Input: 
*
*   Output: returns a pointer to the card drawn
*****************************************************************/
Card* Deck::Draw(){
	Card** temp = 0;
	Card* drawnCard = m_cards[m_remainingCardCount-1];

	// remove the card from the deck
	temp = new Card*[m_remainingCardCount-1];
	for(int i=0; i<m_remainingCardCount-1; ++i){
		temp[i] = m_cards[i];
	}
	delete [] m_cards;
	m_cards = temp;

	m_remainingCardCount--;
	return drawnCard;
}

/****************************************************************
* Overview: This function adds a card to end of deck
*
*    Input: card* to card to be added
*
*   Output: card is added to end of deck
*****************************************************************/
void Deck::Add(Card* card){
	Card** temp = 0;

	if(!InDeck(*card)){
		temp = new Card*[m_remainingCardCount+1];
		for(int i=0; i<m_remainingCardCount; ++i){
			temp[i] = m_cards[i];
		}
		temp[m_remainingCardCount++] = card;
		delete [] m_cards;
		m_cards = temp;
	}else{
		std::cout << "That card already exists in the deck." << std::endl;
	}
}

/****************************************************************
* Overview: This function will check if card exists in deck
*
*    Input: card, card to check for
*
*   Output: bool representing if the card was found
*****************************************************************/
bool Deck::InDeck(Card const& card){
	bool found = false;
	for(int i=0; i<m_remainingCardCount; ++i){
		if(Equal(*m_cards[i],card)){
			found = true;
			break;
		}
	}
	return found;
}

/****************************************************************
* Overview: This function will return number of cards left in deck
*
*    Input: none
*
*   Output: returns int, representing number of cards left
*****************************************************************/
int Deck::RemainingCards(){
	return m_remainingCardCount;
}