#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#include <iostream>
using std::cout;
using std::endl;
#include <iomanip>
#include <string>
using std::string;
#include "Stack.h"


int main(){
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	try{
		Stack<int> s1;
		cout << "s1.Push(1)" << endl;
		s1.Push(1);
		cout << "s1.Push(10)" << endl;
		s1.Push(10);
		cout << "s1.Push(100)" << endl;
		s1.Push(100);
	
		cout << "Part 1.1: " << s1.Pop() << endl;
		cout << "Part 1.2: " << s1.Pop() << endl;
		cout << "Part 1.3: " << s1.Pop() << endl;
	
		Stack<double> s2;
		cout << "s2.Push(.5)" << endl;
		s2.Push(.5);
		cout << "s2.Push(.8)" << endl;
		s2.Push(.8);
		cout << "s2.Push(.13)" << endl;
		s2.Push(.13);
	
		cout << "Part 2.1: " << s2.Pop() << endl;
		cout << "Part 2.2: " << s2.Pop() << endl;
		cout << "Part 2.3: " << s2.Pop() << endl;
	
		Stack<string> s3;
		cout << "s3.Push('Cat')" << endl;
		s3.Push("Cat");
		cout << "s3.Push('Dog')" << endl;
		s3.Push("Dog");
		cout << "s3.Push('House')" << endl;
		s3.Push("House");
	
		cout << "Part 3.1: " << s3.Pop() << endl;
		cout << "Part 3.2: " << s3.Pop() << endl;
		cout << "Part 3.3: " << s3.Pop() << endl;

		// test the exception throw
		Stack<string> exceptionStack;
		cout << "Attempting to pop off empty stack. Value: " << exceptionStack.Pop() << endl;
	}

	catch(Exception<int> const& e){
		cout << endl << e << endl;
	}
	catch(Exception<const char*> const& e){
		cout << endl << e << endl;
	}
	catch(...){
		cout << endl << "Caught unhandled exception." << endl;
	}
	system("pause");
	return 0;
}
