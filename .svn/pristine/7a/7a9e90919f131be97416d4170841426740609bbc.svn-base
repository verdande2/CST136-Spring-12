#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#include <iostream>
using std::cout;
using std::endl;
#include <iomanip>
#include <cstring>

#include "Publication.h"
#include "Book.h"
#include "Video.h"

int main(){
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	//Publication publicationList[20]; // many constructors firing unneededly
	Publication** publicationList = 0;
	int publicationCount = 0;


	Publication** tempList = 0;
	char choice('a');
	Publication* tempPublication = 0;
	

	while(choice != 'q'){
		cout << "Enter q to quit, or any other character to enter another publication. " << endl;
		cin >> choice;

		if(choice=='q'){
			break;
		}

		system("cls");
		cout << "Enter b for a new book, or v for a new video: " << endl;
		cin >> choice;

		system("cls");
		switch(choice){
			case 'b':
				tempPublication = new Book;
				tempPublication->GetData();

				// add new element to the list
				tempList = new Publication*[publicationCount+1];
				for(int i=0; i<publicationCount; ++i){
					tempList[i] = publicationList[i];
				}
				tempList[publicationCount++] = tempPublication;
				delete [] publicationList;
				publicationList = tempList;

				break;
			case 'v':
				tempPublication = new Video;
				tempPublication->GetData();

				// add new element to the list
				tempList = new Publication*[publicationCount+1];
				for(int i=0; i<publicationCount; ++i){
					tempList[i] = publicationList[i];
				}
				tempList[publicationCount++] = tempPublication;
				delete [] publicationList;
				publicationList = tempList;

				break;
			default:
				cout << "Invalid input." << endl;
				system("pause");
				break;
		}
		

	}


	system("cls");
	cout << "Now displaying inventory of publications: " << endl;
	for(int i=0; i<publicationCount; ++i){
		publicationList[i]->PutData();
	}

	// kill everything
	for(int i=0; i<publicationCount; ++i){
		delete publicationList[i];
	}
	delete [] publicationList;

	


	system("pause");
	return 0;
}