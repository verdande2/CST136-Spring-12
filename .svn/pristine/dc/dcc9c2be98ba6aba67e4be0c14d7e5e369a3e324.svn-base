#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#include <iostream>
#include <iomanip>
#include <cstring>
#include "Publication.h"
#include "Book.h"
#include "Video.h"

using std::cout;
using std::endl;


int main(){
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	Book book;
	Video video;
	Publication publication;

	book.Title("Random Book Title");
	book.Price(24.95);
	book.PageCount(784);
	book.Year(2010);
	cout << "For book:" << endl;
	book.GetData();

	video.Title("Random Cheap Video");
	video.Length(94.25);
	video.Price(9.95);
	cout << "For video: " << endl;
	video.GetData();

	publication.Title("Generic publication");
	publication.Price(.99);

	cout << book.Title() << " $" << book.Price() << " " << book.PageCount() << "pgs Printed: " << book.Year() << endl;
	book.PutData();
	cout << video.Title() << " $" << video.Price() << " " << video.Length() << "mins" << endl;
	video.PutData();
	cout << publication.Title() << " $" << publication.Price() << endl;
	
	system("pause");
	return 0;
}