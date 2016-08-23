#include "Book.h"

int Book::PageCount(){
	return m_pageCount;
}
void Book::PageCount(int pageCount){
	m_pageCount = pageCount;
}
int Book::Year(){
	return m_year;
}
void Book::Year(int year){
	m_year = year;
}
Book::Book() : m_pageCount(0), m_year(0) {
	std::cout << "Book Constructor" << std::endl;
}
Book::~Book(){
	std::cout << "Book Destructor" << std::endl;
}

void Book::GetData(){
	char buffer[64];
	cout << "Enter Book Title: " << endl;
	Publication::Flush(cin);
	cin.getline(buffer,64);
	Title(buffer);
	cout << "Enter Book Price: " << endl;
	cin >> m_price;
	cout << "Enter Book Page Count: " << endl;
	cin >> m_pageCount;
	cout << "Enter Book Publishing Year: " << endl;
	cin >> m_year;
}

void Book::PutData(){
	cout << Title() << " $" << Price() << " " << PageCount() << "pgs Printed: " << Year() << endl;
}