#include "Derived.h"

Derived::Derived(int s, int t) : ds(s), dt(t) {
	cout << "Derived constructor firing." << endl;
}

Derived::~Derived(){
	cout << "Derived destructor firing." << endl;
}

void Derived::ShowD(){
	Show();
	cout << "ds: " << ds << "  dt: " << dt << endl;
}