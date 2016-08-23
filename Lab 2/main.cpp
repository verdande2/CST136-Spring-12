/****************************************************************
* Author:					Andrew Sparkes
* Date Created:				3/29/11
* Last Modification Date:	3/31/11
* Lab Number:				CST 136 Lab 2
* Filename:					main.cpp
*
* Overview: This program models a small inventory of books and 
*			select information about them. It demos adding and 
*			removing copies, and related methods.
*
*    Input: The program takes no input save a system pause after 
*			class has been demonstrated.
*
*   Output: The program outputs the book inventory, a brief 
*			statement of what it is doing, and then the inventory 
*			after the statement has been executed.
*****************************************************************/
#define _CRTDBG_MAP_ALLOC
#include <iostream>
#include "book.h"  
#include <iomanip>
#include <crtdbg.h>
#include <ctime>
#include <cstdlib>

using namespace std;

const int NUM_BOOKS = 3;

void InitializeBooks(Book* &books);
long InventoryValue(Book* books);
void DisplayInventory(Book* books);
void Demo(Book* books);

int main(){
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	Book* books = 0;
	
	InitializeBooks(books);
	
	Demo(books);

	delete [] books;
	system("pause");
	return 0;
}

/****************************************************************
* Overview: This function will set the initial values for the 
*			inventory.
*
*    Input: books, array of Book*
*
*   Output: books is properly intialized to initial values.
*****************************************************************/
void InitializeBooks(Book* &books){
	char* isbn[] = {"0-13-917709-4","0-314-20039-8","0-12-345671-7"};
	char* authorLast[] = {"Cleaver","Fife","Zappa"};
	int yearPublished[] = {2007, 1994, 2005};
	long price[] = {7450, 1675, 2150};
	int quantity[] = {3, 4, 14};

	books = new Book[NUM_BOOKS];
	for(int i=0; i<NUM_BOOKS; ++i){
		books[i].ISBN(isbn[i]);
		books[i].AuthorLast(authorLast[i]);
		books[i].YearPublished(yearPublished[i]);
		books[i].Price(price[i]);
		books[i].Quantity(quantity[i]);
	}
}

/****************************************************************
* Overview: This function will calculate the total value of the 
*			whole inventory.
*
*    Input: books, array of Book*
*
*   Output: Returns the total value of the inventory.
*****************************************************************/
long InventoryValue(Book* books){
	long sum = 0;
	for(int i=0; i<NUM_BOOKS; ++i){
		sum += books[i].TotalValue();
	}
	return sum;
}

/****************************************************************
* Overview: This function will output the current inventory.
*
*    Input: books, array of Book*
*
*   Output: Inventory is outputted to console.
*****************************************************************/
void DisplayInventory(Book* books){
	cout << endl << "Inventory Listing:" << endl;
	for(int i=0; i<NUM_BOOKS; ++i){
		cout << books[i].Quantity() << " copies of " << books[i].AuthorLast() << " (" << books[i].ISBN() << " published " << books[i].YearPublished() << ") @ $" << setiosflags(ios::fixed) << setprecision(2) << books[i].Price()/100.0 << " totaling: $" << books[i].TotalValue()/100.0 << endl;
	}
	cout << "Total inventory value: $" << setiosflags(ios::fixed) << setprecision(2) << InventoryValue(books)/100.0 << endl;
}

/****************************************************************
* Overview: This function will demo the basic functions of the 
*			Book class.
*
*    Input: books, array of Book*
*
*   Output: Outputs a demonstration of the class methods to the 
*			console.
*****************************************************************/
void Demo(Book* books){
	int i = 0;
	srand(time(0));

	DisplayInventory(books);

	i = rand() % NUM_BOOKS;
	cout << endl << "Adding a copy of " << books[i].AuthorLast() << endl;
	books[i].Add();

	DisplayInventory(books);

	i = rand() % NUM_BOOKS;
	cout << endl << "Removing two copies of " << books[i].AuthorLast() << endl;
	books[i].Remove(2);

	DisplayInventory(books);

	i = rand() % NUM_BOOKS;
	cout << endl << "Changing price to $1.00 for " << books[i].AuthorLast() << endl;
	books[i].Price(100);

	DisplayInventory(books);
	
	i = rand() % NUM_BOOKS;
	cout << endl << "Changing ISBN to 123456789 for " << books[i].AuthorLast() << endl;
	books[i].ISBN("123456789");
	
	DisplayInventory(books);

	i = rand() % NUM_BOOKS;
	cout << endl << "Setting year published to 2012 for " << books[i].AuthorLast() << endl;
	books[i].YearPublished(2012);
	
	DisplayInventory(books);
}