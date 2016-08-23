#include "List.h"

/****************************************************************
* Overview: Basic constructor and destructor. Only 0-arg constructor.
*****************************************************************/
List::List() : m_head(0), m_tail(0), m_type("List") {}
List::~List(){
	Node* traveling_ptr = m_head;
	Node* trailing_ptr = 0;
	while(traveling_ptr!=0){
		trailing_ptr = traveling_ptr;
		traveling_ptr = traveling_ptr->Next();
		delete trailing_ptr;
	}
}

/****************************************************************
* Overview: Adds an int to the linked list (at the tail).
*
*    Input: toAdd, the int to append to the list
*****************************************************************/
void List::Add(int toAdd){
	Node* newNode = new Node;
	newNode->Data(toAdd);
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
	
}

// deletes ALL instances of toDelete
/*int List::Delete(int toDelete){
	Node* traveling_ptr = m_head;
	int numDeleted(0);
	
	while(traveling_ptr!=0){
		if(traveling_ptr->Data() == toDelete){
			traveling_ptr->Prev()->Next(traveling_ptr->Next()); // sets the previous node's next to current node's next
			traveling_ptr->Next()->Prev(traveling_ptr->Prev()); // sets the next node's prev to current node's prev

			delete traveling_ptr;

			++numDeleted;
		}
		traveling_ptr = traveling_ptr->Next();
	}
	return numDeleted;
}*/

/****************************************************************
* Overview: Function to determine if a value is in the linked list
*
*    Input: needle, the value to search the list for
*
*   Output: Bool representing if the needle was found in the list
*****************************************************************/
bool List::Holds(int needle){
	bool found = false;
	Node* traveling_ptr = m_head;
	while(traveling_ptr!=0){
		if(traveling_ptr->Data() == needle){
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
ostream& List::Print(ostream& s) const{
	bool outputStarted = false;
	Node* traveling_ptr = m_head;
	s << "[";
	while(traveling_ptr!=0){
		if(outputStarted){
			s << " ";
		}
		outputStarted = true;
		s << traveling_ptr->Data();
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
ostream& operator<<(ostream& s, List const& a){
	return a.Print(s);
}
