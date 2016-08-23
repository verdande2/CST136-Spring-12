/****************************************************************
* Overview: A templated class to make a safe array, essentially a 
*			standard array that will do bounds checking.
* Templated
*   Params: T is class that the array will be made of.
*			size is the length of the array
*****************************************************************/
#pragma once
#include <iostream>
#include "Exception.h"
using std::cout;
using std::endl;


template <class T = int, int size = 10>
class SafeArray{
	private:
		T m_array[size];

	public:
		SafeArray();
		~SafeArray();

		T& operator[](int offset);
		T const& operator[](int offset) const;

};

/****************************************************************
* Overview: Basic constructor and destructor.
*****************************************************************/
template <class T, int size>
SafeArray<T, size>::SafeArray(){}

template <class T, int size>
SafeArray<T, size>::~SafeArray(){}

/****************************************************************
* Overview: Overloaded [] to have bounds checking in addition to 
*			their old purpose, two versions, one for accessing 
*			elements, another for resolving an address for assignment
*****************************************************************/
template <class T, int size>
T& SafeArray<T, size>::operator[](int offset){
	if(offset > size-1 || offset < 0){
		// out of bounds
		throw Exception<int>("Index out of bounds.", offset);
	}else{
		return m_array[offset];
	}
}
template <class T, int size>
T const& SafeArray<T, size>::operator[](int offset) const{
	if(offset > size-1 || offset < 0){
		// out of bounds
		throw Exception<int>("Index out of bounds.", offset);
	}else{
		return m_array[offset];
	}
}