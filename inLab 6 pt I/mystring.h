// YEP - put a few errors in here for you too!
// Start Up Code for In-Lab #6 - Part II -- BIT BUGGY NOW THOUGH - FIX IT!

// Filename:  mystring.h

#ifndef MYSTRING
#define MYSTRING

#include <iostream>
using std::cout;
using std::endl;
using std::ostream;

class String {

	friend bool operator!(String const& string);
	friend ostream& operator<<(ostream& stream, String const& string);
	friend String operator+(String const& string1, String const& string2);

	public:
		String(const char* s = "");
		String(char* s);
		String(const String&);
		~String();
		
		String& operator=(const String& rhs);
		String& operator+=(String const& string);
		
		void Display() const;

	private:
		char* m_ptr;
};

#endif