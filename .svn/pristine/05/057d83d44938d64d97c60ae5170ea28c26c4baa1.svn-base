#include <iostream>
#define NOMCX
#include <windows.h>
#include "courseBook.hpp"

using std::cin;

#define _CRTDBG_MAP_ALLOC 
#include <stdlib.h>
#include <crtdBG.h>

const int MAX_STUDENTS = 100;
enum MENU_CHOICE{PRINT_ALL_COURSES = 1, PRINT_COURSE_GRADES = 2, ADD_SYSTEM_STUDENT = 3, ADD_COURSE_STUDENT = 4, CHANGE_STUDENT_GRADE = 5, EXIT = 6};

int Menu();
int GetCoursePick(CourseBook &cb);
int GetStudentPick(Student s[], const int count);
GRADE GetGrade();

//TODO still could use some ui clean up, validation could use some work too
int main()
{
	SetConsoleTitle(L"Grade Book");
	CourseBook cb;
	cb.LoadFile("courses.txt");
	Student students[MAX_STUDENTS];
	int studentCount = 0;

	while(1){
		int choice = Menu();
		system("cls");
		string name;

		switch(static_cast<MENU_CHOICE>(choice)){
			case PRINT_ALL_COURSES:
				for(int x = 0; x < cb.NumberOfCourses(); x++)
					cout << *(cb.GetCourseById(x)->m_name) << endl;
				system("pause");
				break;
			case PRINT_COURSE_GRADES:
				cb.GetCourseById(GetCoursePick(cb))->Print();
				system("pause");
				break;
			case ADD_SYSTEM_STUDENT:
				cout << "Enter name: ";
				cin >> name;
				students[studentCount] = Student(name);
				studentCount++;
				break;
			case ADD_COURSE_STUDENT:
				if(studentCount > 0){
					cb.GetCourseById(GetCoursePick(cb))->AddStudent(&(students[GetStudentPick(students, studentCount)]));
				}else{
					cout << "ERROR: There are no students" << endl;
					system("pause");
				}
				break;
			case CHANGE_STUDENT_GRADE:
				if(studentCount > 0){
					cb.GetCourseById(GetCoursePick(cb))->SetGrade(&(students[GetStudentPick(students, studentCount)]), GetGrade());
				}else{
					cout << "ERROR: There are no students" << endl;
					system("pause");
				}
				break;
			case EXIT:
				return 0;
			default:
				cout << "Invalid menu choice." << endl;
				system("pause");
		}
		
	}

	return 0;
}

int Menu(){
	int choice = -1;

	system("cls");
	cout << "MAIN MENU\n" << endl;
	cout << "1) Print out all available courses" << endl;
	cout << "2) Print the grades for a course" << endl;
	cout << "3) Add a student to the system" << endl;
	cout << "4) Add a student to a course" << endl;
	cout << "5) Change a students grade" << endl;
	cout << "6) Exit" << endl;

	cin >> choice;

	return choice;
}

int GetCoursePick(CourseBook &cb){
	int choice;

	for(int x = 0; x < cb.NumberOfCourses(); x++)
	{
		cout << x << ") " << *cb.GetCourseById(x)->m_name << endl;
	}
	cout << "Enter course selection: " << endl;
	cin >> choice;

	return choice;
}

int GetStudentPick(Student s[], const int count){
	int choice;

	for(int x = 0; x < count; x++)
		cout << x << ") " << *(s[x].GetName()) << endl;

	cout << "Enter student selection: ";
	cin >> choice;

	return choice;
}

GRADE GetGrade(){
	GRADE g;
	int choice;

	cout << endl << "4) A" << endl;
	cout << "3) B" << endl;
	cout << "2) C" << endl;
	cout << "1) D" << endl;
	cout << "0) F" << endl;
	cout << "-1) Not Set" << endl;

	cout << "Enter grade selection: " << endl;
	cin >> choice;
	g = static_cast<GRADE>(choice);

	return g;
}
