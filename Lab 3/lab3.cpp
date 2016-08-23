/****************************************************************
* Author:					Andrew Sparkes
* Date Created:				4/12/11
* Last Modification Date:	4/14/11
* Lab Number:				CST 136 Lab 3
* Filename:					lab3.cpp
*
* Overview: This program models a sport and its players, and 
*			provides basic functionality to add, display and 
*			search players.
*****************************************************************/
#define _CRTDBG_MAP_ALLOC
#include <iostream>
#include "player.h"
#include "sport.h"  
#include <iomanip>
#include <crtdbg.h>

const int WIDTH_NAME = 20;
const int WIDTH_GRADE = 8;
const int WIDTH_GPA = 8;

void DisplayHeaders();
void InitializeRoster(Sport * sport);

int main(){
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	Sport* basketball = new Sport;
	InitializeRoster(basketball);
	basketball->DisplayMenu();

	delete basketball;
	return 0;
}

/****************************************************************
* Overview: This function will set the initial values for 
*			basketball roster.
*
*    Input: sport, Sport* of the Sport pointer to initialize
*
*   Output: sport is properly intialized to initial values.
*****************************************************************/
void InitializeRoster(Sport * sport){
	sport->Add(new Player("ShakOTeal", 14, 3.50));
	sport->Add(new Player("WillyEMakit", 13, 3.15));
	sport->Add(new Player("EarnestTBass", 15, 3.00));
	sport->Add(new Player("FrankZappa", 16, 2.4));
	sport->Add(new Player("I.M.Sample", 15, 3.21));
	sport->Add(new Player("RickBarry", 14, 2.75));
}

