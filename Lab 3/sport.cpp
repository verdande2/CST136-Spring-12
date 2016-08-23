#include "sport.h"
#include "player.h"
#include <iostream>

/****************************************************************
* Overview: Constructor (no arg) sets length and roster pointer = 0
*****************************************************************/
Sport::Sport() : m_length(0), m_roster(0) {}

/****************************************************************
* Overview: Destructor, deletes all players, and the roster
*****************************************************************/
Sport::~Sport(){
	while(m_length!=0){
		delete m_roster[--m_length];
	}
	delete [] m_roster;
}

/****************************************************************
* Overview: Short function to get user input from console
*****************************************************************/
char Sport::PromptUser(){
	char selection;
	std::cout << "Selection: ";
	std::cin >> selection;
	return selection;
}

/****************************************************************
* Overview: This function will display menu and handle the menu 
*			selection appropriately.
*****************************************************************/
void Sport::DisplayMenu(){
	char selection = '-';

	while(selection!='E'){
		system("cls");
		std::cout << "Menu:" << std::endl;
		std::cout << "A) Add a player" << std::endl;
		std::cout << "S) Search for/Display a player" << std::endl;
		std::cout << "D) Display all players" << std::endl;
		std::cout << "C) Display current count of players" << std::endl;
		std::cout << "E) Exit" << std::endl;
		std::cout << std::endl;
		selection = toupper(this->PromptUser());

		switch(selection){
			case 'A':
				this->Add();
				system("pause");
				break;
			case 'S':
				this->Search();
				system("pause");
				break;
			case 'D':
				this->List();
				system("pause");
				break;
			case 'C':
				std::cout << "Current number of players: " << this->m_length << std::endl;
				system("pause");
				break;
			case 'E':
				std::cout << "Exiting now..." << std::endl;
				break;
			default:
				std::cout << "Invalid menu selection" << std::endl;
				system("pause");
				break;
		}
	}
}

/****************************************************************
* Overview: This function will prompt for a player's data and 
*			then append them to the roster
*****************************************************************/
void Sport::Add(){
	Player* new_player = 0;
	char name[64];
	int grade;
	double gpa;

	std::cout << "Name: ";
	std::cin >> name;
	std::cout << "Grade: ";
	std::cin >> grade;
	std::cout << "GPA: ";
	std::cin >> gpa;

	new_player = new Player(name, grade, gpa);
	this->Add(new_player);
}

/****************************************************************
* Overview: This function will append a player to the roster.
*****************************************************************/
void Sport::Add(Player* new_player){
	Player** temp = new Player*[m_length+1];
	for(int i = 0; i < m_length; ++i){
		temp[i] = m_roster[i];
	}
	temp[m_length++] = new_player;
	delete [] m_roster;
	m_roster = temp;
	
	// display the most recent player added
	Player::DisplayHeaders();
	this->m_roster[m_length-1]->Display();
}

/****************************************************************
* Overview: This function lists the entire roster
*****************************************************************/
void Sport::List(){
	Player::DisplayHeaders();
	for(int i=0; i<m_length; i++){
		this->m_roster[i]->Display();
	}
}

/****************************************************************
* Overview: This function will search the roster for a search 
*			query and display results, if any.
*****************************************************************/
void Sport::Search() const{
	char buffer[32];
	bool found = false;

	std::cout << "Name to search for (case sensitive): ";
	std::cin >> buffer;

	std::cout << "Results:" << std::endl;
	Player::DisplayHeaders();
	for(int i=0; i<m_length; i++){
		if(this->m_roster[i]->Search(buffer)){
			found = true;
			this->m_roster[i]->Display();
		}
	}
	if(!found){
		std::cout << "No records match that string." << std::endl;
	}
}