#ifndef BASE
#define BASE
#include <iostream>
using std::cout;
using std::endl;
using std::istream;
using std::ostream;

class Base{
	friend ostream& operator<<(ostream& output, Base &obj);
	friend istream& operator>>(istream& input, Base &obj);

	private:
	protected:
		int ba, bb, bc;
	public:
		Base();
		~Base();
		void Set(int a, int b, int c);
		void Show();
		Base operator+(const Base& r);
};
#endif