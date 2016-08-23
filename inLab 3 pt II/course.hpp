#include <string>
#include <vector>
#include "student.hpp"
#include <iostream>

using std::string;
using std::vector;
using std::cout;
using std::endl;

#ifndef COURSE
#define COURSE

enum GRADE{
	A = 4,
	B = 3,
	C = 2,
	D = 1,
	F = 0,
	NOTSET = -1
};

struct Entry{
	Student* s;
	GRADE g;
};

class Course{
	public:
		Course(){
			m_name = new string;
			*m_name = "";
			m_credits = -1;
			m_studentCount = 0;
		}

		Course(string name, int credits);

		~Course(){	
			delete m_name;
		}

		inline int GetCredits() const {return m_credits;}

		void AddStudent(Student* s);
		void Print() const;
		void SetGrade(Student *s, GRADE g);

		string* m_name;
		int m_credits;
		Entry m_students[100];
		int m_studentCount;

	private:
		const char* PrintGrade(GRADE g) const;
};

#endif