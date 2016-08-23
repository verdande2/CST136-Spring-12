#ifndef CAR_H
#define CAR_H
#include <iostream>
using std::cout;
using std::endl;

class Car{
	public:
		virtual void identify() const;
		void tester(){
			cout << "INSIDE CAR - TESTER NON virtual function" << endl;
		}
		virtual void virtTester() {
			cout << "INSIDE CAR-VIRTUAL FUNCTION" << endl;
		}
		~Car();
};

#endif