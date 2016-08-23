#include "Array.h"

/****************************************************************
* Overview: Basic constructor and destructor. Only delete array 
*			if it contains elements (duh)
*****************************************************************/
Array::Array() : m_data(0), m_length(0), m_type("Array") {}
Array::~Array(){
	if(m_length>0){
		delete [] m_data;
	}
}

/****************************************************************
* Overview: Adds an int to the array
*    Input: x, the int to add
*****************************************************************/
void Array::Add(int x){
	int* temp = new int[m_length+1];
	for(int i=0; i<m_length; ++i){
		temp[i] = m_data[i];
	}
	temp[m_length++] = x;
	delete [] m_data;
	m_data = temp;
}

/****************************************************************
* Overview: Determines if a value is in the array, returning bool
*    Input: x, int to array search for
*****************************************************************/
bool Array::Holds(int x){
	bool found = false;
	for(int i=0; i<m_length; ++i){
		if(m_data[i]==x){
			found = true;
			break;
		}
	}
	return found;
}

/****************************************************************
* Overview: insertion operator for array class
*    Input: stream s and array object a
*   Output: ostream& of stream
*****************************************************************/
ostream& operator<<(ostream& s, Array const& a){
	return a.Print(s);
}

/****************************************************************
* Overview: Outputs formatted array to stream object
*    Input: s, stream object
*   Output: ostream& of stream
*****************************************************************/
ostream& Array::Print(ostream& s) const{
	bool outputStarted = false;
	s << "[";
	for(int i=0; i<m_length; ++i){
		if(outputStarted){
			s << " ";
		}
		s << m_data[i];
		outputStarted = true;
	}
	s << "]";
	return s;
}
