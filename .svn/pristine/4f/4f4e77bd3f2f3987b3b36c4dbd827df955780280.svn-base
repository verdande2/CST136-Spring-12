// File mystring.h - used for inlab #4 and lab 4
// Is this an example of a UDC????  Meet the criteria?
// Some startup code
// NOTE:  If desired, you can find some examples of a search method 
//        in our text

#ifndef MYSTRING_H
#define MYSTRING_H

#include <iostream>
#include "player.h"
using std::ostream;
using std::cout;
using std::endl;

class String{
   friend ostream& operator<<(ostream& stream, String const& object){stream << object.ptr; return stream;} // please see note at bottom of this file
   public:
		inline String(const char* = "");
		inline String(char);
		inline String(const String&); // Copy constructor
		~String() { delete [] ptr; }
		inline void operator=(String const& right);
		inline bool operator==(String const& right);
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

// assignment operator for strings
inline void String::operator=(String const& right){
	ptr = new char[strlen(right.ptr)+1];
	strcpy(ptr,right.ptr);
}

// == operator for comparing two strings
inline bool String::operator==(String const& right){
	return strcmp(ptr,right.ptr)==0;
}

// originally had in this function, but had major problems with it working properly

//ostream& String::operator<<(ostream& stream, String const& object){
//	stream << object.ptr;
//	return stream;
//}

// this was paired with the the existing friend declaration above minus the {} definition of course.
// I tried multiple places for the prototype ostream& operator<<(ostream& stream, String const& object);
// Tried preceding it by class String; and throwing it above the String class definition. Tried putting prototype at top of file, above this function, etc, every combination I tried yielded the below error.
// The only way I was able to get it to work without skimping out by doing a friend class Player and letting player get access to ptr directly was to implicitly inline the operator function above. 
// The error I was getting was:
//player.obj : error LNK2005: "class std::basic_ostream<char,struct std::char_traits<char> > & __cdecl operator<<(class std::basic_ostream<char,struct std::char_traits<char> > &,class String const &)" (??6@YAAAV?$basic_ostream@DU?$char_traits@D@std@@@std@@AAV01@ABVString@@@Z) already defined in main.obj
//sport.obj : error LNK2005: "class std::basic_ostream<char,struct std::char_traits<char> > & __cdecl operator<<(class std::basic_ostream<char,struct std::char_traits<char> > &,class String const &)" (??6@YAAAV?$basic_ostream@DU?$char_traits@D@std@@@std@@AAV01@ABVString@@@Z) already defined in main.obj
// [file path hacked off]\CST136\Debug\Lab 4.exe : fatal error LNK1169: one or more multiply defined symbols found
#endif