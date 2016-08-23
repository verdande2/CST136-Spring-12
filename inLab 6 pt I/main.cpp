// YOU NEED TO DO SOME FIXING UP HERE!  Nothing major but just for fun!

#include "mystring.h"


// Don't forget you will need to edit/change this to make it look
// like our lab sheet for this week!
int main(){
	String s1("Test");
	String s2(s1 + "ing"); 
	String s3(s2);
	cout << "s1: ";
	cout << s1 << endl;
	cout << "s2: ";
	cout << s2 << endl;
	cout << "s3: ";
	cout << s3 << endl;

	cout << "After appending 'the stringclass to s3: ";
	s3 += " the String class";
	cout << s3 << endl;
	
	cout << "Checking if s3 is null" << endl;
	if(!s3){
		cout << "s3 is null\n";
	}
	
	cout << "assigning blank str to s1" << endl;
	s1 = "";
	
	cout << "checking if s1 is null" << endl;
	if(!s1){
		cout << "s1 is null\n" << endl;
	}
	
	String s4(" World");
	cout << "s4: ";
	cout << s4 << endl;

	String s5;
	cout << "s5: ";
	cout << s5 << endl;
	
	cout << "prepending hello to s4: ";
	s5 = "Hello" + s4;
	cout << s5 << endl;

	system("pause");
	return 0;
}


