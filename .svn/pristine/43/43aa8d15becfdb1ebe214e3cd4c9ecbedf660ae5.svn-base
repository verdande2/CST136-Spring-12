/****************************************************************
* Author:					Andrew Sparkes
* Date Created:				5/28/11
* Last Modification Date:	5/29/11
* Lab Number:				CST 136 Lab 8 pt I
* Filename:					main.cpp
*
* Overview: This program demos templates and exceptions via 
*			implementation of a safe array.
*****************************************************************/
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <windows.h>
using std::cout;
using std::endl;
#include "SafeArray.h"


int main(){
	SetConsoleTitle(L"CST136 Lab 8 pt I    by Andrew Sparkes");
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	try{
		SafeArray<int, 5> iArray;
		SafeArray<double> dblArray;
		SafeArray<> defArray;

		cout << endl << endl << "My Int Array: ";
		for(int x=0; x < 5; ++x){
			iArray[x] = x;
		}

		for(int x=0; x < 5; ++x){
			cout << iArray[x] << " ";
		}
	
		cout << endl << endl << "My Double Array: ";
		for(int x=0; x < 10; ++x){
			dblArray[x] = x+100;
		}

		for(int x=0; x <= 10; ++x){ // throws exception
			cout << dblArray[x] << " ";
		}

		cout << endl << endl << "My Default Array: ";
		for(int x=0; x < 5; ++x){
			defArray[x] = x;
		}

		for(int x=0; x < 5; ++x){
			cout << defArray[x] << " ";
		}
	}
	catch(Exception<int> e){
		cout << endl << e << endl;
	}
	catch(...){
		cout << endl << "Caught unhandled exception." << endl;
	}


	cout << endl;
	system("pause");
	return 0;
}