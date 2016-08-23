/****************************************************************
* Overview: Container class is an ABC representing a basic 
*			container with 3 basic functions: Add(), Holds(), 
*			and operator<<(). Print is used to allow for 
*			polymorphism for operator<< (aka black magic).
*****************************************************************/
#ifndef CONTAINER
#define CONTAINER

#include <iostream>
using std::ostream;

class Container{
	friend ostream& operator<<(ostream& s, Container const& a);

	private:
		virtual ostream& Print(ostream& s) const = 0;

	protected:

	public:
		Container();
		virtual ~Container();

		virtual void Add(int toAdd) = 0;
		virtual bool Holds(int n) = 0;
};

#endif