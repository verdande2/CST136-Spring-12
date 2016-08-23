#define _CRTDBG_MAP_ALLOC
#include "../Shared/Book.h"
#include <iostream>
#include <crtdbg.h>
using namespace std;

void Append(Book** &collection, Book* single, int &count);
void Check(Book &bookParam);

int main(){
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	Book** bookCollection = 0;
	int bookCount = 0;
	Book randomBook;

	Append(bookCollection, new Book("Deitel",100,false), bookCount);
	Append(bookCollection, new Book("Nagler",101,true), bookCount);
	Append(bookCollection, new Book("Meyers",102,false), bookCount);
	Append(bookCollection, new Book("Eckel",103), bookCount);

	cout << "Making another collection of books, 5 in total. 5 constructors get called." << endl;
	Book anotherBookCollection[5];

	Check(randomBook); // two constructor/destructor pairs get called

	// firing 4 destructors
	for(int i = 0; i < bookCount; ++i){
		delete bookCollection[i];
	}
	delete [] bookCollection;

	system("pause");

	// when main returns, anotherBookCollection gets destroyed
	return 0;
}

void Append(Book** &collection, Book* single, int &count){
	Book** temp = new Book*[count+1];
	for(int i = 0; i < count; ++i){
		temp[i] = collection[i];
	}
	temp[count++] = single;
	delete [] collection;
	collection = temp;
}

void Check(Book &bookParam){
	cout << "Just entered Check()" << endl;
	Book book1; // these books get destroyed upon exit of Check()
	Book book2;

	cout << "About to leave Check()" << endl;
}