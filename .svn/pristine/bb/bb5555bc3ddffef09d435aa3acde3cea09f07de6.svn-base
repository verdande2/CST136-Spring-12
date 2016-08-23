#include "PokerGame.h"

int PokerGame::payouts[] = {800, 50, 25, 9, 6, 4, 3, 2, 1}; // associated with enum PokerGame::pokerHands
const char* PokerGame::HandNames[] = {"Royal Flush", "Straight Flush", "Four of a Kind", "Full House", "Flush", "Straight", "Three of a Kind", "Two Pair", "Pair"};

/****************************************************************
* Overview: Constructor/Destructor, constructor sets up screen 
*			and sets its game to this pokergame.
*    Input: None.
*   Output: Destructor kills the allocated screen
*****************************************************************/
PokerGame::PokerGame(){
	m_screen = new PokerScreen; // had to make pokerscreen dynamic due to the relationship between pokergame/pokerscreen and their friendships
	m_screen->m_game = this;
}
PokerGame::~PokerGame(){
	delete m_screen;
}

/****************************************************************
* Overview: Starts the poker game in motion
*    Input: Menu choices and bet selection done via console input
*   Output: Displays the poker table and all prompts via console.
*****************************************************************/
void PokerGame::Start(){
	int choice(0);

	m_player.SetMoney(100);

	GetBet();
	do{
		// play game
		
		m_player.m_money -= m_bet; // take bet
		
		Deal();
		Draw();
		DetermineWinner();

		// put player's hand in the discard pile
		for(int i=0; i<5; ++i){
			m_discardPile.Add(m_playerHand.Draw());
		}

		if(m_deck.Length() < 10){
			cout << "Not enough cards in deck. Shuffling." << endl;
			// not enough cards in the deck to continue, put all the cards in the discard pile back into the deck, reshuffle and continue
			while(m_discardPile.Length() > 0){
				m_deck.Add(m_discardPile.Draw());
			}
			m_deck.Shuffle();
		}

		choice = Menu();
	}while(choice!=0);
}

/****************************************************************
* Overview: Displays the menu and prompts for a choice, returns 
*			choice, if they wish to change bet, prompt for bet 
*			before continuing
*    Input: Takes console input
*   Output: Returns either 0 or 1 depending of it the user wishes to continue
*****************************************************************/
int PokerGame::Menu(){
	char choice(0);
	cout << endl << "Press spacebar to play again, b to change your bet and play again, or any other key to exit." << endl;
	choice = _getch();
	if(choice == ' '){
		return 1;
	}else if(choice == 'b'){
		GetBet();
		return 1;
	}else{
		return 0;
	}
}

/****************************************************************
* Overview: Prompts for bet and sets it
*    Input: Console input for bet, 1-5 are valid numbers
*   Output: Sets bet.
*****************************************************************/
void PokerGame::GetBet(){
	// clear screen, output prompt, set bet = input
	char buffer = 0;
	while(buffer<1+48 || buffer > 5+48){ //while buffer is not 1,2,3,4,5
		system("cls");
		cout << "Please input your bet: (1-5)" << endl;
		cin >> buffer;
		if(buffer<1+48 || buffer > 5+48){
			cout << "Your bet must be between 1 and 5." << endl;
			system("pause");
		}
	}
	m_bet = buffer-48;
}

/****************************************************************
* Overview: Deals 5 cards to the player
*    Input: None.
*   Output: player's hand now has 5 cards drawn from the deck
*****************************************************************/
void PokerGame::Deal(){
	// dealing 5 cards to player
	for(int i=0; i<5; ++i){
		m_playerHand.Add(m_deck.Draw());
	}
}

/****************************************************************
* Overview: Draw phase of video poker. Lets user toggle holds, 
*			view payout table
*    Input: Takes input from console to select holds/view payout 
*			table/continue
*   Output: Keeps an up to date screen of the poker table.
*****************************************************************/
void PokerGame::Draw(){
	char choice('i');
	
	do{
		system("cls");
		DisplayTable();
		cout << "1-5 Toggles card holds   v - View Payouts   Spacebar - Continue" << endl;
		cout << "You have $" << m_player.m_money << "   Current Bet: " << m_bet << endl;

		choice = _getch();
		switch(choice){
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
				m_playerHand.ToggleHold(choice-48-1); // parameter is choice converted from ascii to int
				break;
			case 'v':
				DisplayPayouts();
				break;
			case ' ':
				break;
		}
	}while(choice!=' ');

	// holds are set, replace cards now
	Card* tempCard = 0;

	for(int i = 0; i < m_playerHand.Length(); ++i){
		if(!m_playerHand.m_holds[i]){
			tempCard = m_deck.Draw();
			m_playerHand.Replace(m_playerHand.m_cards[i], tempCard);
			m_discardPile.Add(tempCard);
		}
		m_playerHand.m_holds[i] = false; // reset all holds, as for the current game they are no longer used and the next game will need them reset anyway
	}
}

/****************************************************************
* Overview: Determines if the player has won or lost and doles 
*			out the payout appropriately.
*    Input: None.
*   Output: Displays the winning hand, how much money you have 
*			and how much you've won.
*****************************************************************/
void PokerGame::DetermineWinner(){
	// small assortment of flags to help determine what hand the player has
	bool straight = false;
	bool flush = false;
	bool fourofakind = false;
	bool threeofakind = false;
	bool pair = false;
	bool fullhouse = false;
	bool twopair = false;
	bool royal = false;

	int winningHand = -1;

	int suitCounts[Card::SUIT_COUNT] = {0};
	int rankCounts[Card::RANK_COUNT] = {0};

	// count suits
	for(int i=0; i<Card::SUIT_COUNT; ++i){
		suitCounts[i] = m_playerHand.Count(static_cast<Card::SUIT>(i));
	}
	
	// count ranks
	for(int i=0; i<Card::RANK_COUNT; ++i){
		rankCounts[i] = m_playerHand.Count(static_cast<Card::RANK>(i));
	}

	// checking for flush
	for(int i=0; i<Card::SUIT_COUNT; ++i){
		if(suitCounts[i] == 5){
			flush = true;
		}
	}
	
	// checking for 2/3/4 of a kind
	for(int i=0; i<Card::RANK_COUNT; ++i){
		if(rankCounts[i] == 4){
			fourofakind = true;
			break; // leaves only one card, which obviously can't be a 2/3 of a kind
		}

		if(rankCounts[i] == 3){
			threeofakind = true;
		}

		if(rankCounts[i] == 2){
			if(pair){
				// if we already have a pair, we now have two pair
				pair = false;
				twopair = true;
			}else{
				pair = true;
			}
		}
	}
	if(pair && threeofakind){
		fullhouse = true;
	}

	// checking for straight
	for(int i=0; i<Card::RANK_COUNT-5; ++i){
		if(rankCounts[i] && rankCounts[i+1] && rankCounts[i+2] && rankCounts[i+3] && rankCounts[i+4]){
			straight = true;
		}
	}
	
	// special case for AKQJ10, due to ace being able to be high/low and my model represents an ace as low
	if(rankCounts[Card::RANK_ACE] && rankCounts[Card::RANK_KING] && rankCounts[Card::RANK_QUEEN] && rankCounts[Card::RANK_JACK] && rankCounts[Card::RANK_TEN]){
		straight = true;
		royal = true;
	}

	// determine the appropriate payout
	if(straight && flush){
		if(royal){
			winningHand = PokerGame::HAND_ROYAL_FLUSH;
		}else{
			winningHand = PokerGame::HAND_STRAIGHT_FLUSH;
		}
	}else if(straight){
		winningHand = PokerGame::HAND_STRAIGHT;
	}else if(flush){
		winningHand = PokerGame::HAND_FLUSH;
	}else if(fullhouse){
		winningHand = PokerGame::HAND_FULL_HOUSE;
	}else if(fourofakind){
		winningHand = PokerGame::HAND_FOUR_OF_A_KIND;
	}else if(threeofakind){
		winningHand = PokerGame::HAND_THREE_OF_A_KIND;
	}else if(twopair){
		winningHand = PokerGame::HAND_TWO_PAIR;
	}else if(pair){
		winningHand = PokerGame::HAND_PAIR;
	}

	// display screen
	system("cls");
	DisplayTable();

	if(winningHand != -1){
		m_player.m_money += PokerGame::payouts[winningHand] * m_bet;
		cout << "Congratulations, you have won $" << m_bet*PokerGame::payouts[winningHand] << " with a " << PokerGame::HandNames[winningHand] << "!" << endl;
	}else{
		// player lost; don't award anything.
		cout << "You lost. " << endl;
	}
	cout << "You have $" << m_player.m_money << endl;

	cout << "Cards remaining in deck: " << m_deck.Length() << endl;

}

/****************************************************************
* Overview: Display a table of payouts for each winning hand.
*    Input: None.
*   Output: None.
*****************************************************************/
void PokerGame::DisplayPayouts(){
	system("cls");
	cout << "Payouts table:" << endl;
	for(int i=0; i<PokerGame::HAND_COUNT; ++i){
		cout << PokerGame::HandNames[i] << ": " << PokerGame::payouts[i]*m_bet << endl;
	}
	system("pause");
	system("cls");
}

/****************************************************************
* Overview: Displays the poker table on the screen.
*    Input: None.
*   Output: None.
*****************************************************************/
void PokerGame::DisplayTable(){
	m_screen->Display();
}