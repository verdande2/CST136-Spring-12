// Start Up Code for In-Lab #6 - Part II -- NEED TO FIX FIRST!
// These errors were added for fun - and to help keep you on your toes.
// Have fun!
#include "mystring.h"

bool operator!(String const& string);
ostream& operator<<(ostream& stream, String const& string);
String operator+(String const& string1, String const& string2);

String::String(const char* p) : m_ptr(0){
	m_ptr = new char[strlen(p) + 1];
	strcpy(m_ptr, p);
}

String::String(char* p) : m_ptr(0){
	m_ptr = new char[strlen(p) + 1];
	strcpy(m_ptr, p);
}

String::String(const String& s) : m_ptr(0){
	m_ptr = new char[strlen(s.m_ptr) + 1];
	strcpy(m_ptr, s.m_ptr);
}

String::~String(){
	if(m_ptr != 0){
		delete [] m_ptr;
	}
}

//HEY - CHECK THIS OUT CAREFULLY!  Pretty nice and YOU must be able to explain every line!
String& String::operator=(const String& s){			// s by const ref
	if(this != &s){									// checks for self assignment, and if it is, just return *this
		if(strlen(s.m_ptr) != strlen(m_ptr)){		// checks to see if we can reuse the current allocated char[]
			delete [] m_ptr;						// if we can't use it, delete it,
			m_ptr = new char[strlen(s.m_ptr) + 1];	// and allocate another one of appropriate size
		}
		strcpy(m_ptr, s.m_ptr);						// copy the right hand side's string to the current object's
	}
	return *this;									// return the object for assignment
}

String& String::operator+=(String const& string){
	return (*this = String(*this + string)); // abusing (clever usage of mechanics) my = operator 
}

void String::Display() const {
	cout << " Here is the string: " << m_ptr << endl;
}

bool operator!(String const& string){
	return string.m_ptr==0 || strlen(string.m_ptr)==0;
}
ostream& operator<<(ostream& stream, String const& string){
	stream << string.m_ptr;
	return stream;
}
String operator+(String const& string1, String const& string2){
	char* temp = new char[strlen(string1.m_ptr)+strlen(string2.m_ptr)+1];
	strcpy(temp,string1.m_ptr);
	strcat(temp, string2.m_ptr);
	String tempString(temp);
	//delete [] temp;
	return tempString;
}