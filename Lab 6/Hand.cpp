#include "Hand.h"

/****************************************************************
* Overview: Basic constructor and destructor
*    Input: None.
*   Output: Constructor sets all the card holds to false, as 
*			well as starts the held card count at 0.
*****************************************************************/
Hand::Hand() : m_holdsCount(0) {
	// zero out all the card holds
	for(int i=0; i<5; ++i){
		m_holds[i] = false;
	}
}
Hand::~Hand(){}

/****************************************************************
* Overview: This function simply toggles the hold status of a card.
*    Input: i, the offset of the card in the hand.
*   Output: None.
*****************************************************************/
void Hand::ToggleHold(int i){
	if(m_holds[i]){
		// card is held, removing hold on it
		m_holdsCount--;
	}else{
		m_holdsCount++;
	}
	m_holds[i] = !m_holds[i];
}