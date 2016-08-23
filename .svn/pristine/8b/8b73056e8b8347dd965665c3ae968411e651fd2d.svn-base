#include "Base.h"

Base::Base() : ba(0), bb(0), bc(0) {
	cout << "Base constructor firing." << endl;
}

Base::~Base(){
	cout << "Base destructor firing." << endl;
}

void Base::Set(int a, int b, int c){
	ba = a;
	bb = b;
	bc = c;
}

void Base::Show(){
	cout << "ba: " << ba << "  bb: " << bb << "  bc: " << bc << endl;
}


Base Base::operator+(const Base& r){
	Base ret;
	ret.Set(ba+r.ba, bb+r.bb, bc+r.bc);
	return ret;
}