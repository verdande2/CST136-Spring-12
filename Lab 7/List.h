/****************************************************************
* Overview: A simple model of a doubly linked list. Has an append 
*			function (Add()) as well as a function to determine 
*			if the list has a value in it. It also has the ability 
*			to be inserted into a stream via <<.
*****************************************************************/
#ifndef LIST
#define LIST

#include "Container.h"
#include "Node.h"
#include <iostream>
using std::ostream;

class List : public Container{
	friend ostream& operator<<(ostream& s, List const& a);

	private:
		Node* m_head;
		Node* m_tail;
		
		const char* const m_type;

		virtual ostream& Print(ostream& s) const;

	protected:

	public:
		List();
		~List();

		void Add(int toAdd);
		//int Delete(int toDelete);
		bool Holds(int n);
		
};

#endif