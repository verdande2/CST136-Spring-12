#include "course.hpp"


Course::Course(std::string name, int credits){
	m_name = new string(name);
	m_credits = credits;
	m_studentCount = 0;
}

void Course::AddStudent(Student* s){	
	m_students[m_studentCount].g = NOTSET;
	m_students[m_studentCount].s = s;
	m_studentCount++;
}

void Course::Print() const{
	cout << this->m_name->c_str() << "\nCredits: " << this->m_credits << endl;
	if(m_studentCount){
		cout << "Student Name  Grade" << endl;
	}else{
		cout << "No students enrolled." << endl;
	}
	for(int x = 0; x < m_studentCount; x++){
		cout << *(m_students[x].s->GetName()) << " " << PrintGrade(m_students[x].g) << endl;
	}
}

void Course::SetGrade(Student *s, GRADE g){
	for(int x = 0; x < m_studentCount; x++){
		if(m_students[x].s == s){
			m_students[x].g = g;
		}
	}
}

const char* Course::PrintGrade(GRADE g) const {
	switch(g){
		case A:
			return "A";
		case B:
			return "B";
		case C:
			return "C";
		case D:
			return "D";
		case F:
			return "F";
		case NOTSET:
			return "(Not Set)";
	}
}
