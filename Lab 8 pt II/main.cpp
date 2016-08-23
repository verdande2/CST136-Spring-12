/****************************************************************
* Author:					Andrew Sparkes
* Date Created:				5/28/11
* Last Modification Date:	5/29/11
* Lab Number:				CST 136 Lab 8 pt II
* Filename:					main.cpp
*
* Overview: This program demos templates and exceptions via 
*			implementation of a linked list.
*****************************************************************/
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <windows.h>
using std::cout;
using std::endl;
#include "LinkedList.h"
#include "Exception.h"


int main(){
	SetConsoleTitle(L"CST136 Lab 8 pt II    by Andrew Sparkes");
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	try{
		LinkedList<int> myList;
		myList.Add(1);
		myList.Add(1);
		myList.Add(2);
		myList.Add(3);
		myList.Add(5);
		myList.Add(8);
		myList.Add(13);
		cout << "LinkedList<int>" << endl;
		cout << myList << endl;
	
		cout << "Removing any entries that are between 4 and 11" << endl;
		for(int i=4; i<=11; ++i){
			myList.Delete(i); 
		}
		cout << myList << endl;

		LinkedList<double> myListD;
		myListD.Add(0.1);
		myListD.Add(0.1);
		myListD.Add(0.2);
		myListD.Add(0.3);
		myListD.Add(0.5);
		myListD.Add(0.8);
		myListD.Add(0.13);
		cout << "LinkedList<double>" << endl;
		cout << myListD << endl;

		cout << "Removing entries that are between .2 and .5 (with a step of .1)" << endl;
		for(double i=.2; i<=.5; i+=.1){
			myListD.Delete(i); 
		}
		cout << myListD << endl;

		// now, to test the exception throw.
		cout << "Making a new, empty list and attempting to delete it. " << endl;
		LinkedList<int>* ExceptionTestList = new LinkedList<int>;
		delete ExceptionTestList; // will throw exception, trying to delete an empty list, will also call memory leak, as the delete never actually fires.
	}
	catch(Exception<const char*> e){
		cout << endl << e << endl;
	}
	catch(...){
		cout << endl << "Caught unhandled exception." << endl;
	}
	system("pause");
	return 0;
}