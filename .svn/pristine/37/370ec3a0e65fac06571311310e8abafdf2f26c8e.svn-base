#ifndef MYSTRING_H
#define MYSTRING_H

#include <iostream>
using std::ostream;

class String{

	friend inline ostream& operator<< (ostream&, const String&);

    public:
		inline String(const char* = "");
		inline String(const String&);
		~String() {
			cout << "call to ~String()" << endl;
			delete [] ptr;
		}
		inline String& operator= (const String&);

    protected:
		char* ptr;
};

inline ostream& operator<< (ostream& str, const String& s){
	cout << "call to <<String" << endl;
	const char quote = '"';
	return str << quote << s.ptr << quote;
}

inline String::String(const char* p) : ptr(0){
	cout << "call to String(const char*)" << endl;
	p = p ? p : "";
	ptr = new char[strlen(p) + 1];
	strcpy(ptr, p);
}

inline String::String(const String& s) : ptr(0){
	cout << "call to String(const String&)" << endl;
	ptr = new char[strlen(s.ptr) + 1];
	strcpy(ptr, s.ptr);
}

inline String& String::operator= (const String& s){
	cout << "call to String=" << endl;
	if(this != &s){
		unsigned length = strlen(s.ptr);
		if(strlen(ptr) != length){
			delete [] ptr;
			ptr = new char[length + 1];
		}
		strcpy(ptr, s.ptr);
	}
	return *this;
}

#endif
