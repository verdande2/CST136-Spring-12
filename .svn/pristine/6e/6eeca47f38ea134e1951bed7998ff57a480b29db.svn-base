#include "player.h"

const int Player::WIDTH_NAME = 20;
const int Player::WIDTH_GRADE = 8;
const int Player::WIDTH_GPA = 8;

/****************************************************************
* Overview: 3 arg constructor
*****************************************************************/
Player::Player(String name, int grade, double gpa) : m_name(name), m_grade(grade), m_gpa(gpa) {}

/****************************************************************
* Overview: Destructor 
*****************************************************************/
Player::~Player(){}

/****************************************************************
* Overview: This function returns if the player is named 'name'
*****************************************************************/
bool Player::Search(String name){
	return m_name==name;
}

/****************************************************************
* Overview: This function displays the formatted player's data
*****************************************************************/
void Player::Display() const {
	cout << left << setw(Player::WIDTH_NAME) <<  m_name << setw(Player::WIDTH_GRADE) << m_grade << setw(Player::WIDTH_GPA);
	cout.precision(2);
	cout.setf(std::ios_base::fixed);
	cout << m_gpa << endl;
}

/****************************************************************
* Overview: This function prints out headers in prep for displaying 
*			a player or players.
*****************************************************************/
void Player::DisplayHeaders(){
	cout << left << setw(Player::WIDTH_NAME) << "Name"  << setw(Player::WIDTH_GRADE) << "Grade" << setw(Player::WIDTH_GPA) << "GPA" << endl;
}