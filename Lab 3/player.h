#include <cstring>
#include <iostream>
#include <iomanip>

extern const int WIDTH_NAME, WIDTH_GRADE, WIDTH_GPA;

/****************************************************************
* Overview: This class models a player with 3 attributes: name, 
*			grade and gpa. It has a 3 arg constructor that takes 
*			name, grade, gpa in that order. Display() will output 
*			the current player via formatted console output. 
*			DisplayHeaders() displays headers in preparation of 
*			Display() being called on players. Search() hunts a 
*			substring in the name field and returns true if a 
*			match is found.
*****************************************************************/
class Player{
	private:
		char* m_name;
		int m_grade;
		double m_gpa;
	public:
		Player(const char* name, int grade, double gpa) : m_name(0), m_grade(grade), m_gpa(gpa) {
			m_name = new char[strlen(name)+1];
			strcpy(m_name,name);
		};

		~Player(){
			delete [] m_name;
		};

		bool Search(const char* name) const {
			return strstr(m_name, name)!=0;
		};

		void Display() const {
			std::cout << std::left << std::setw(WIDTH_NAME) << m_name << std::setw(WIDTH_GRADE) << m_grade << std::setw(WIDTH_GPA) << m_gpa << std::endl;
		};

		static void DisplayHeaders(){
			std::cout << std::left << std::setw(WIDTH_NAME) << "Name"  << std::setw(WIDTH_GRADE) << "Grade" << std::setw(WIDTH_GPA) << "GPA" << std::endl;
		};
};