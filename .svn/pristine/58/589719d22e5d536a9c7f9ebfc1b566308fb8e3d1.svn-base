#include "book.h"
#include "cstring"
#include <iostream>

using std::cout;
using std::endl;

/****************************************************************
* Overview: The following are:
*				No parameter constructor
*				5 parameter constructor
*				Copy constructor
*				Destructor
*
*    Input: Book class itself.
*
*   Output: None.
*****************************************************************/
Book::Book(){
	this->m_authorLast = 0;
	this->m_ISBN = 0;
	this->m_price = 0;
	this->m_quantity = 0;
	this->m_yearPublished = 0;
}
Book::Book(char* isbn, char* authorLast, int yearPublished, long price, int quantity){}
Book::Book(Book* book){
	this->AuthorLast(book->AuthorLast());
	this->ISBN(book->ISBN());
	this->m_price = book->Price();
	this->m_quantity = book->Quantity();
	this->m_yearPublished = book->YearPublished();
}
Book::~Book(){
	delete [] this->m_authorLast;
	delete [] this->m_ISBN;
}

/****************************************************************
* Overview: The following functions add or remove from the 
*			quantity of books.
*
*    Input: howMany, int representing number to add/remove if not 1.
*
*   Output: quantity is changed according to add/remove
*****************************************************************/
void Book::Add(){
	this->m_quantity++;
}
void Book::Add(int howMany){
	this->m_quantity += howMany;
}

void Book::Remove(){
	this->m_quantity--;
}
void Book::Remove(int howMany){
	this->m_quantity -= howMany;
}

/****************************************************************
* Overview: This following functions are simple getters and 
*			setters for each attribute of the Book class.
*
*    Input: Each setter takes a single parameter to set its 
*			respective attribute to.
*
*   Output: None.
*****************************************************************/
void Book::ISBN(char* isbn){
	int ISBNLength = strlen(isbn);
	this->m_ISBN = new char[ISBNLength+1];
	strcpy(this->m_ISBN,isbn);
}
char* Book::ISBN() const {
	return this->m_ISBN;
}

void Book::AuthorLast(char* authorLast){
	int authorLastLength = strlen(authorLast);
	this->m_authorLast = new char[authorLastLength+1];
	strcpy(this->m_authorLast,authorLast);
}
char* Book::AuthorLast() const {
	return this->m_authorLast;
}

void Book::YearPublished(int yearPublished){
	this->m_yearPublished = yearPublished;
}
int Book::YearPublished() const {
	return this->m_yearPublished;
}

void Book::Price(long price){
	this->m_price = price;
}
long Book::Price() const {
	return this->m_price;
}
		
void Book::Quantity(int quantity){
	this->m_quantity = quantity;
}
int Book::Quantity() const {
	return this->m_quantity;
}

/****************************************************************
* Overview: This function will calculate the total value of that 
*			book on hand.
*
*    Input: None.
*
*   Output: Returns the total value of that book on hand.
*****************************************************************/
long Book::TotalValue(){
	return this->m_price * this->m_quantity;
}

/****************************************************************
* Overview: This function will validate a book's ISBN number.
*
*    Input: None.
*
*   Output: Returns true if the ISBN is valid, false otherwise.
*****************************************************************/
bool Book::ValidateISBN(){
	bool valid = false;
	int sum = 0;
	int currentDigit = 1;
	int calcChecksum = 0;
	int ISBNLength = static_cast<int>(strlen(this->m_ISBN));
	
	// get checksum from current ISBN
	int givenChecksum = this->m_ISBN[ISBNLength-1];
	if(givenChecksum==88 || givenChecksum==120){
		// If checksum is X, replace with 10.
		givenChecksum = 10;
	}else{
		// regular integer
		givenChecksum -= 48;
	}

	// calculate checksum 
	for(int i=0; i<ISBNLength-1; ++i){
		//cout << i << ": " << m_ISBN[i] << endl;
		if(this->m_ISBN[i]>=48 && this->m_ISBN[i]<=57){
			calcChecksum += (currentDigit++)*(this->m_ISBN[i]-48);
		}
	}
	calcChecksum %= 11;

	// compare given and calculated checksums
	valid = (givenChecksum==calcChecksum);

	return valid;
}