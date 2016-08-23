/****************************************************************
* Overview: Straightforward class for a templated linked list. 
*			Has basic methods for output, appending to the list, 
*			removing items from the list. It is doubly linked, 
*			but the reverse links are not used in any current 
*			methods.
*****************************************************************/
#pragma once

#include "Node.h"
#include "Exception.h"
#include <iostream>
using std::ostream;

template <class T>
class LinkedList{
	private:
		Node<T>* m_head;
		Node<T>* m_tail;

		int m_length;
	public:
		LinkedList();
		~LinkedList();

		void Add(T const& item);
		int Delete(T const& toDelete);

		ostream& Print(ostream& stream) const;
		bool Holds(T const& needle) const;
		
};

/****************************************************************
* Overview: Basic constructor and destructor. Only 0-arg constructor.
*****************************************************************/
template <class T>
LinkedList<T>::LinkedList() : m_head(0), m_tail(0), m_length(0) {}
template <class T>
LinkedList<T>::~LinkedList(){
	if(m_length){
		Node<T>* traveling_ptr = m_head;
		Node<T>* trailing_ptr = 0;
		while(traveling_ptr!=0){
			trailing_ptr = traveling_ptr;
			traveling_ptr = traveling_ptr->Next();
			delete trailing_ptr;
			--m_length;
		}
	}else{
		throw Exception<const char*>("Attempted to delete from an empty linked list.","N/A");
	}
}

/****************************************************************
* Overview: Adds an int to the linked list (at the tail).
*
*    Input: toAdd, the int to append to the list
*****************************************************************/
template <class T>
void LinkedList<T>::Add(T const& item){
	Node<T>* newNode = new Node<T>;
	newNode->Data(new T);
	*(newNode->Data()) = item; // assumes whatever templated type is being thrown at list has an appropriate assignment operator
	newNode->Next(0);
	newNode->Prev(m_tail);

	// if inserting the first element
	if(m_head==0){
		m_tail = newNode;
		m_head = newNode;
	}else{ // for any other element
		m_tail->Next(newNode);
		m_tail = newNode;
	}
	
	++m_length;
}

/****************************************************************
* Overview: Function to determine if a value is in the linked list
*
*    Input: needle, the value to search the list for
*
*   Output: Bool representing if the needle was found in the list
*****************************************************************/
template <class T>
bool LinkedList<T>::Holds(T const& needle) const{
	bool found = false;
	Node<T>* traveling_ptr = m_head;
	while(traveling_ptr!=0){
		if(*(traveling_ptr->Data()) == needle){
			found = true;
			break;
		}
		traveling_ptr = traveling_ptr->Next();
	}
	return found;
}

/****************************************************************
* Overview: Print function to allow for polymorphic operator<<
*			Outputs the formatted list.
*
*    Input: s, ostream object to write to
*	Output:	returns ostream& s
*****************************************************************/
template <class T>
ostream& LinkedList<T>::Print(ostream& s) const{
	bool outputStarted = false;
	Node<T>* traveling_ptr = m_head;
	s << "[";
	while(traveling_ptr!=0){
		if(outputStarted){
			s << " ";
		}
		outputStarted = true;
		s << *(traveling_ptr->Data());
		traveling_ptr = traveling_ptr->Next();
	}
	s << "]";
	return s;
}

/****************************************************************
* Overview: operator<< to display a list. 
*
*    Input: s, stream to output to, list a to output
*
*   Output: returns ostream& of editted stream
*****************************************************************/
template <class T>
ostream& operator<<(ostream& s, LinkedList<T> const& a){
	return a.Print(s);
}


/****************************************************************
* Overview: deletes all instances of toDelete in the list. It will 
*			delete as many copies as there exist in the list and 
*			return the number that it deleted. It performs a == 
*			operator on toDelete and the current node's data, 
*			therefore assumed that == is overloaded for the 
*			templated type T. 
*
*    Input: toDelete, type T by const& of the value to remove 
*			from the list.
*
*   Output: returns count of how many entries were deleted.
*****************************************************************/
template <class T>
int LinkedList<T>::Delete(T const& toDelete){
	Node<T>* traveling_ptr = m_head;
	Node<T>* tempPtr = 0;
	int numDeleted(0);
	
	while(traveling_ptr!=0){
		if(*(traveling_ptr->Data()) == toDelete){
			traveling_ptr->Prev()->Next(traveling_ptr->Next()); // sets the previous node's next to current node's next
			traveling_ptr->Next()->Prev(traveling_ptr->Prev()); // sets the next node's prev to current node's prev

			tempPtr = traveling_ptr->Prev();
			delete traveling_ptr;
			traveling_ptr = tempPtr;

			++numDeleted;
			--m_length;
		}
		traveling_ptr = traveling_ptr->Next();
	}
	return numDeleted;
}