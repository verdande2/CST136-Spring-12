// File part2.cpp  - with a few modifications

// Make sure you watch how/when the ctor/dtor's fire
// NOTE:  sorry guys, looks like we got a bit of a problem here!  Please fix -
// and feel free to comment out any 'bad' code / problems at this point!  Just make 
// sure you know WHY you are copying it out...  The .h file is just fine.
#include <iostream>
using namespace std;

#include "mystring.h"


void foo(const String& obj1)  
{
   String obj2(obj1);

}

void WillThisFireCopyCtor(String x)
{
	cout << "\nWell, did it Fire Copy Ctor ?";
}

int main()
{	String s1('A');	// what constructor gets called? 1arg

	String s2("Joe");

	WillThisFireCopyCtor(s2);

	char name[20];
	cout << "\nWhat is your name: ";
	cin >> name;
	cout << "\nHello " << name << "!\n\n";
	foo(name); // notice this - look whats passed - and how it
			   // will need to be converted - and impact upon the
			   // constructor - this gets a bit deep but is interesting
			   // REVIEW IT NOW!
	
	//String s3();	// What is this supposed to be for?  Is it ok? No. It's declaring a function s3 that returns a String.
	String s4("WillEMakit");
	String s5;		// Who gets called and why - or is this a problem? String(const char* p) gets called
	//s5 = s4;		// commented out by me. op= is not overloaded, so this line fails.
	
	system("pause");
	return 0;
}

