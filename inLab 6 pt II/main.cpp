#include "Fraction.h"

int main(){
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
	system("pause");
	return 0;
}