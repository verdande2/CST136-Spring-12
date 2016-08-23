#include "courseBook.hpp"
#include <fstream>

using std::ifstream;

void CourseBook::LoadFile(std::string file){
	char buffer[100];
	Course* buffer_course = 0;
	Course** temp_courses = 0;
	ifstream inFile(file.c_str());

	if(inFile.is_open()){
		while(inFile.getline(buffer, 100, '\n')){
			char* name = strtok(buffer, ",");
			char* creditsstr = strtok(0, ",");
			int c = atoi(creditsstr);

			buffer_course = new Course(name, c);

			temp_courses = new Course*[m_courseCount+1];
			for(int i=0; i<m_courseCount; ++i){
				temp_courses[i] = m_courses[i];
			}
			temp_courses[m_courseCount++] = buffer_course;
			delete [] m_courses;
			m_courses = temp_courses;
		}
		inFile.close();
	}
}

Course* CourseBook::GetCourseById(const int &id){
	return m_courses[id];
}