/****************************************************************
* Author:					Andrew Sparkes
* Date Created:				4/17/11
* Last Modification Date:	4/18/11
* Lab Number:				CST 136 Lab 4
* Filename:					main.cpp
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


void InitializeRoster(Sport& sport);


int main(){
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	
	Sport basketball;
	InitializeRoster(basketball);
	basketball.PromptUser();

	return 0;
}

/****************************************************************
* Overview: This function will set the initial values for 
*			basketball roster.
*
*    Input: sport, Sport to initialize 
*
*   Output: sport is properly intialized to initial values.
*****************************************************************/
void InitializeRoster(Sport& sport){
	sport.PlayerAdd(new Player("AndyTaylor", 14, 3.50));
	sport.PlayerAdd(new Player("Opey Taylor", 13, 2.95));
	sport.PlayerAdd(new Player("EarnestTBass", 15, 3.00));
	sport.PlayerAdd(new Player("FrankZappa", 16, 2.0));
	sport.PlayerAdd(new Player("I.M.Sample", 15, 3.21));
}
