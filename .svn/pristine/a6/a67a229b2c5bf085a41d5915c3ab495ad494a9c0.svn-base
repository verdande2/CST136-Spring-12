#ifndef DSTRING_H
#define DSTRING_H

#include "mystring.h"

class DString : public String
{
	friend inline ostream& operator << (ostream&, const DString&);

	public:
		DString(): String(), length(strlen(ptr)) {
			cout << "call to DString()" << endl;
		}
		DString(const char* p): String(p), length(strlen(ptr)) {
			cout << "call to DString(const char*)" << endl;
		}
		DString(const DString& d) : String(d), length(d.length) {
			cout << "call to DString(const DString&)" << endl;
		}
		~DString() {
			cout << "call to ~DString()" << endl;
		}
		inline DString& operator= (const DString&);

	private:
		unsigned length;
};

inline ostream& operator<< (ostream& str, const DString& d){
	cout << "call to <<DString" << endl;
	return str << static_cast<const String&>(d) << " length = " << d.length;
}

inline DString& DString::operator=(const DString& d){
	cout << "call to DString=" << endl;
	if(this != &d){
		String::operator=(d); // could also be called via static_cast<String*>(this)->operator=(d);
		length = d.length;
	}
	return *this;
}

#endif
