/****************************************************************
* Overview: An object representing an array of ints, has basic 
*			functionality to add values and to determine if values 
*			exist inside it, as well as stream insertion support.
*****************************************************************/
#ifndef ARRAY
#define ARRAY

#include "Container.h"
#include <iostream>
using std::ostream;

class Array : public Container{
	friend ostream& operator<<(ostream& s, Array const& a);

	private:
		int* m_data;
		int m_length;

		const char* const m_type;

		virtual ostream& Print(ostream& s) const;

	protected:

	public:
		Array();
		~Array();

		void Add(int x);
		bool Holds(int x);
};

#endif