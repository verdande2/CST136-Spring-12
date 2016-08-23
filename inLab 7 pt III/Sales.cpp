#include "Sales.h"


Sales::Sales(){}
Sales::~Sales(){}

void Sales::GetData(){
	cout << "Please enter the sales data (space delimited): ";
	cin >> m_sales[0] >> m_sales[1] >> m_sales[2];
}

void Sales::PutData(){
	cout << "Sales data:" << endl;
	for(int i = 0; i < 3; ++i){
		cout << i+1 << ": " << m_sales[i] << endl;
	}
}