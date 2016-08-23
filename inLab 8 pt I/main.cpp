#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#include <iostream>
using std::cout;
using std::endl;
#include <iomanip>
#include <cstring>
#include "dstring.h"


int main(){
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	DString n1;
	DString n2("C++ test string");
	DString n3(n2);
	DString n4;
	n4 = "A different string";
	cout << n1 << endl;
	cout << n2 << endl;
	cout << n3 << endl;
	cout << n4 << endl;

	
	system("pause");
	return 0;
}

/* A typical run would yield:

"" length = 0
"C++ test string" length = 15
"C++ test string" length = 15
"A different string" length = 18

*/