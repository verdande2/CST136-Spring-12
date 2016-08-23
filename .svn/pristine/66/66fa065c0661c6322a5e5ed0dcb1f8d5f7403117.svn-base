#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#include <iostream>
using std::cout;
using std::endl;
#include <iomanip>
#include <string>

template <class T>
T average(T Tarray[], int size);

int main(){
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	int iArray[] = {0, 2, 4, 6, 8, 10};
	long lArray[] = {1L, 2L, 3L, 4L, 5L};
	double dArray[] = {0.0, 1.1, 3.2, 5.3};

	cout << "average(iArray): " << average(iArray, 6) << endl;
	cout << "average(lArray): " << average(lArray, 5) << endl;
	cout << "average(dArray): " << average(dArray, 4) << endl;

	system("pause");
	return 0;
}

template <class T>
T average(T Tarray[], int size){
	T sum(0); // assumes that T has an initial value for zero, aka numeric type
	for(int i=0; i<size; ++i){
		sum += Tarray[i];
	}
	sum /= size; // actually compute the average.
	return sum;
}