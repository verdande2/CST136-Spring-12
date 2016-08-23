#define _CRTDBG_MAP_ALLOC
#include "../Shared/Book.h"
#include <iostream>
#include <crtdbg.h>
using namespace std;

void CheckBook(Book book);
void CheckBookByRef(Book& book);
void CheckTemp(Book temp);
Book CheckReturn();

int main(){
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	Book b1("Petzlod", 100, false);
	Book b2("Nagler", 101, true);
	Book b3("Eckel", 103);
	Book b4(b2);

	Book::DisplayHeaders();
	b4.Display();

	CheckBook(b4); // fires copy constructor
	CheckBookByRef(b4); // no constructors fired

	cout << "About to use temp as value to a function:" << endl;
	CheckTemp(Book("Using C++", 123)); // 3 arg constructor called

	cout << "About to use return Book/Object from function:" << endl; 		
	Book b10 = CheckReturn();  // copy constructor called

	system("pause");
	return 0;
}

void CheckBook(Book book){
	cout << "In CheckBook()" << endl;
}

void CheckBookByRef(Book& book){
	cout << "In CheckBookByRef()" << endl;
}

void CheckTemp(Book temp){
	cout << "In CheckTemp()" << endl;
}

Book CheckReturn(){
	cout << "In CheckReturn()" << endl;
	Book r;
	return r;
}