/****************************************************************
* Author:					Andrew Sparkes
* Date Created:				5/3/11
* Last Modification Date:	5/7/11
* Lab Number:				CST 136 Lab 5
* Filename:					main.cpp
*
* Overview: This program models a basic deck of cards, and deals them out.
*****************************************************************/
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#include <iostream>
#include <iomanip>
#include <cstring>
#include "Deck.h"

using std::cout;
using std::endl;


int main(){
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	Deck deck;
	Card* drawnCard = 0;

	// try to add another ace of spades
	Card* aceOfSpades = new Card(Card::SPADES, Card::ACE);
	deck.Add(aceOfSpades); // does not get added to deck
	delete aceOfSpades;

	while(deck.RemainingCards()){
		drawnCard = deck.Draw();
		
		cout << "Drawing: ";
		drawnCard->Display();
		cout << ". Remaining Cards in deck: " << deck.RemainingCards();
		cout << endl;

		delete drawnCard;
	}

	system("pause");
	return 0;
}