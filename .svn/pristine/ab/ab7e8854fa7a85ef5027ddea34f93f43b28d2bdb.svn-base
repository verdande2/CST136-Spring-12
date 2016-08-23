/****************************************************************
* Author:					Andrew Sparkes
* Date Created:				5/3/11
* Last Modification Date:	5/30/11
* Lab Number:				CST 136 Lab 6
* Filename:					main.cpp
*
* Overview: This program models a video poker game in the console. 
*			Players can set their bet, draw 0-5 cards, view payout 
*			tables. It operates as a 1-5 coin video poker machine. 
*			Payout tables are slightly modified from a real video 
*			poker machine's payout tables.
*	Input:	All input is taken in via console.
*  Output:	All output is displayed to the console.
*****************************************************************/
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#include <iostream>
#include <iomanip>
#include <cstring>
#include "PokerGame.h"
#include <windows.h>
using std::cout;
using std::endl;


int main(){
	SetConsoleTitle(L"Console Video Poker!    by Andrew Sparkes");
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	PokerGame game;
	game.Start();

	return 0;
}