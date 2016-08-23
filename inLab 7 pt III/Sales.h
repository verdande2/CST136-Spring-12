#pragma once
#include <iostream>
using std::cout;
using std::endl;
using std::cin;

class Sales{
	private:
		double m_sales[3];

	protected:

	public:
		Sales();
		~Sales();
		void GetData();
		void PutData();
};