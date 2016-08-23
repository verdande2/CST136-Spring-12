#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#include <iostream>
using std::cout;
using std::endl;
#include <iomanip>
#include <string>
using std::string;
#include "Fraction.h"


int main(){
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	try{
		Fraction f1;
		Fraction f2(2L, 0L);
		Fraction f3(f2);
		cout << f1 << endl;
		cout << f2 << endl;
		cout << f3 << endl;
		f3 = f3 + Fraction(-5, 4);
		f1 = f2 + f3;
		cout << f1 << endl;
		f1 = f2 - f3;
		cout << f1 << endl;
		f1 = f2 * f3;
		cout << f1 << endl;
		cout << (f1++)++ << endl;  // What’s going on – notice the chaining
		f1 = f2 / f3;
		cout << f1 << endl;
	}
	catch(const char* text){
		cout << text << endl;
	}
	catch(...){
		cout << "Caught unhandled exception." << endl;
	}
	system("pause");
	return 0;
}
