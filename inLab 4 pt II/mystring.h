// File mystring.h - used for inlab #4 and lab 4
// Is this an example of a UDC????  Meet the criteria?
// Some startup code
// NOTE:  If desired, you can find some examples of a search method 
//        in our text

#ifndef MYSTRING_H
#define MYSTRING_H

#include <cstring> // new header (rather than string.h)
using namespace std;


class String
{
   public:
		inline String(const char* = "");
		inline String(char);
		inline String(const String&); // Copy constructor
		~String() { delete [] ptr; }
   private:
		char* ptr;
};

inline String::String(const char* p)
{
	cout << "1 arg const char* constructor: creating " << p << endl;
	p = p ? p : "";	// What is this doing???  A: if p isn't set, set it to ""
	ptr = new char[strlen(p) + 1];
	strcpy(ptr, p);
}

inline String::String(char ch)
{
	cout << "1arg char constructor: creating " << ch << endl;
	ptr = new char[2];
	ptr[0] = ch;
	ptr[1] = 0;
}

inline String::String(const String& obj) // Copy constructor
{
	cout << "copy constructor" << obj.ptr << endl;
	// ptr = obj.ptr; // What the DEFAULT copy ctor would do
	ptr = new char[strlen(obj.ptr) + 1];
	strcpy(ptr, obj.ptr);
}

#endif