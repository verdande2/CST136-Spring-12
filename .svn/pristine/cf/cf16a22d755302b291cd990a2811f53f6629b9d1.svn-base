#include "Book.h"
#include <iostream>
#include <iomanip>

using namespace std;

Book::Book(const Book &book){
	Title(book.Title());
	Id(book.Id());
	m_checkedIn = book.CheckedIn();
	cout << "COPY CONSTRUCTOR: Creating " << Title() << " (" << Id() << ") Status: " << (CheckedIn()?"In":"Out") << endl;
}
Book::Book(char* title, int id, bool checkedIn){
	Title(title);
	Id(id);
	m_checkedIn = checkedIn;
	cout << "3ARG CONSTRUCTOR: Creating " << Title() << " (" << Id() << ") Status: " << (CheckedIn()?"In":"Out") << endl;
}

Book::Book(){
	Title("UNKNOWN");
	Id(0);
	m_checkedIn = false;
	cout << "0ARG CONSTRUCTOR: Creating " << Title() << " (" << Id() << ") Status: " << (CheckedIn()?"In":"Out") << endl;
}

Book::~Book(){
	cout << "DESTRUCTOR: Destroying " << m_title << endl;
	delete [] m_title;
}

void Book::Display() const{
	cout << left << setw(Book::TITLE_WIDTH) << Title();
	cout << left << setw(Book::ID_WIDTH) << Id();
	cout << left << setw(Book::STATUS_WIDTH) << CheckedIn() << endl;
}

void Book::DisplayHeaders(){
	cout << left << setw(Book::TITLE_WIDTH) << "Title";
	cout << left << setw(Book::ID_WIDTH) << "ID";
	cout << left << setw(Book::STATUS_WIDTH) << "Status" << endl;
}