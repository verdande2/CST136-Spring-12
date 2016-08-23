#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#include <iostream>
#include <iomanip>
#include <cstring>
#include "Derived.h"

using std::cout;
using std::endl;
using std::ostream;
using std::cin;
using std::istream;

ostream& operator<<(ostream& output, Base &obj);
istream& operator>>(istream& input, Base &obj);

int main(){
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	cout << "Derived obj(1,2);" << endl;
	Derived obj(1,2);

	cout << "obj.Set(100, 200, 300);" << endl;
	obj.Set(100, 200, 300);

	cout << "obj.Show();" << endl;
	obj.Show();

	cout << "obj.ShowD();" << endl;
	obj.ShowD();

	cout << "Base baseobj;" << endl;
	Base baseobj;

	cout << "Base bObj1, bObj2;" << endl;
	Base bObj1, bObj2;

	cout << "cin >> bObj1;" << endl;
	cin >> bObj1;

	cout << "cin >> bObj2;" << endl;
	cin >> bObj2;

	cout << "cout << bObj1;" << endl;
	cout << bObj1;

	cout << "cout << bObj2;" << endl;
	cout << bObj2;

	cout << "Base bObj3 = bObj1 + bObj2;" << endl;
	Base bObj3 = bObj1 + bObj2;



	system("pause");
	return 0;
}

ostream& operator<<(ostream& output, Base &obj){
	output << "ba: " << obj.ba << "  bb: " << obj.bb << "  bc: " << obj.bc << endl;
	return output;
}
istream& operator>>(istream& input, Base &obj){
	input >> obj.ba;
	input >> obj.bb;
	input >> obj.bc;
	return input;
}