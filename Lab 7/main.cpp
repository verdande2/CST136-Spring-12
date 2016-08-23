/****************************************************************
* Author:					Andrew Sparkes
* Date Created:				5/13/11
* Last Modification Date:	5/20/11
* Lab Number:				CST 136 Lab 7
* Filename:					main.cpp
*
* Overview: This program models a linked list and array classes 
*			and then does a basic demo w/ inheritance, 
*			polymorphism and ABCs.
*
*    Note:	Original main copied from lab document. Only edits 
*			were 1) added a endl after cout<<*ptr[i], 3) added 
*			memory leak detection and 2) cosmetic (whitespace) 
*			changes.
*****************************************************************/
#define _CRTDBG_MAP_ALLOC

#include <crtdbg.h>
#include <iostream>
using namespace std;
#include "Container.h"
#include "Node.h"
#include "List.h"
#include "Array.h"

int main(){
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	
	Container* ptr[] = { (new Array), (new List) };

	const int size = sizeof(ptr) / sizeof(*ptr);

	for(int i=0; i<size; ++i){
		const int limit = 3;

		for(int j=0; j<limit; ++j){
			ptr[i]->Add(j*2);
		}

		cout << *ptr[i] << endl;

		for(int k=0; k<limit*2; ++k){
			cout << k << " is " << (ptr[i]->Holds(k)? "present." : "not present.") << endl;
		}

		delete ptr[i];

		cout << "\t======== THE END ========" << endl;
	}


	system("pause");
	return 0;
}