#ifndef PUBLICATION
#define PUBLICATION
#include <cstring>
#include <iostream>
using std::endl;
using std::cout;
using std::cin;
using std::istream;

class Publication{
	private:
	protected:
		char* m_title;
		double m_price;
	public:
		Publication();
		~Publication();
		char* Title();
		void Title(char* title);
		double Price();
		void Price(double price);
		virtual void GetData();
		virtual void PutData();

		
		static istream& Flush(istream& istream);
};
#endif