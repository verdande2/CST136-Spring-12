#ifndef PLAYER
#define PLAYER
#include <iostream>
#include <iomanip>
#include "mystring.h"
using std::cout;
using std::cin;
using std::endl;
using std::setprecision;
using std::setw;
using std::left;

/****************************************************************
* Overview: This class models a player with 3 attributes: name, 
*			grade and gpa. It has a 3 arg constructor that takes 
*			name, grade, gpa in that order. Display() will output 
*			the current player via formatted console output. 
*			DisplayHeaders() displays headers in preparation of 
*			Display() being called on players. Search() hunts a 
*			string in the name field and returns true if a 
*			match is found.
*****************************************************************/
class Player{
	private:
		String m_name;
		int m_grade;
		double m_gpa;
	public:
		Player(String name, int grade, double gpa);
		~Player();

		bool Search(String name);

		void Display() const;

		static void DisplayHeaders();
		
		static const int WIDTH_NAME;
		static const int WIDTH_GRADE;
		static const int WIDTH_GPA;

};
#endif