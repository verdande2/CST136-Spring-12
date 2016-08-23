#include "PokerScreen.h"


/****************************************************************
* Overview: Basic constructor/destructors
*    Input: None.
*   Output: Constructor defaults the character array to blank screen.
*****************************************************************/
PokerScreen::PokerScreen(){
	for(int r=0; r<SCREEN_HEIGHT; ++r){
		for(int c=0; c<SCREEN_WIDTH; ++c){
			m_screen[r][c] = ' ';
		}
	}
}
PokerScreen::~PokerScreen(){}

/****************************************************************
* Overview: Displays the screen after updating the data in char array.
*    Input: None.
*   Output: Displays the screen to the console.
*****************************************************************/
void PokerScreen::Display(){
	system("cls");
	UpdateScreen();
	for(int i=0; i<SCREEN_HEIGHT; ++i){
		for(int j=0; j<SCREEN_WIDTH; ++j){
			cout << m_screen[i][j];
		}
		cout << endl;
	}
}

/****************************************************************
* Overview: Sets the card at position i to the values of card
*    Input: i, 0 based position on screen, and card, Card const& 
*			of card to set it to.
*   Output: Sets the appropriate places in char array to match card.
*****************************************************************/
void PokerScreen::SetCard(int i, Card const& card){
	int rowOffset = 1;
	int colOffset = 1+CARD_WIDTH*i;
	m_screen[rowOffset][colOffset] = *(card.Suit()); // indirection to turn const char* into a char
	m_screen[rowOffset][colOffset+1] = *(card.Rank());
	m_screen[rowOffset][colOffset+2] = *(card.Rank()+1); // to account for 0 in 10

}

/****************************************************************
* Overview: Toggles the visual hold on the card at position i
*    Input: i, 0 based position of card
*   Output: toggles display of H under card
*****************************************************************/
void PokerScreen::ToggleHold(int i){
	int rowOffset = 2;
	int colOffset = 1+CARD_WIDTH*i;
	if(m_screen[rowOffset][colOffset] == ' '){
		m_screen[rowOffset][colOffset] = 'H';
	}else{
		m_screen[rowOffset][colOffset] = ' ';
	}
	
}

/****************************************************************
* Overview: Updates the screen char array with uptodate information.
*    Input: None.
*   Output: m_screen has matching data to the pokergame.
*****************************************************************/
void PokerScreen::UpdateScreen(){
	int count = 0; // zero based
	for(std::vector<Card *>::iterator i = m_game->m_playerHand.m_cards.begin(); i != m_game->m_playerHand.m_cards.end(); i++){
		SetCard(count, **i);

		// if the card is being held, toggle the visual hold indicator
		if(m_game->m_playerHand.m_holds[count] != (m_screen[2][1+CARD_WIDTH*count] == 'H')){
			ToggleHold(count);
		}
		count++; // bump up counter
	}
}