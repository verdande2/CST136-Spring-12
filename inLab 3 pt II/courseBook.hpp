#include "course.hpp"

#ifndef COURSE_H
#define COURSE_H



class CourseBook{
	public:
		CourseBook() : m_courseCount(0), m_courses(0) {}

		void LoadFile(string file);

		int NumberOfCourses() const {return m_courseCount;}

		Course* GetCourseById(const int &id);

	private:
		Course** m_courses;
		int m_courseCount;
};

#endif