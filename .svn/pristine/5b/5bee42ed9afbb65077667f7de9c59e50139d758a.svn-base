#include "MathFuncs.h"

/****************************************************************
* Overview: Calculates factorial of x
*    Input: x, integer
*   Output: factorial of x
*****************************************************************/
int Factorial(int x){
	int factorial(1);
	for(int i=2; i<=x; ++i){
		factorial *= i;
	}
	return factorial;
}

/****************************************************************
* Overview: Function to calculate combinations of n choose r at 
*			a time
*    Input: n and r, ints
*   Output: number of ways to choose r things from n objects
*****************************************************************/
int nCr(int n, int r){
	return Factorial(n) / Factorial(n-r) / Factorial(r);
}

/****************************************************************
* Overview: Function to calculate permutations of n permute r at 
*			a time
*    Input: n and r, ints
*   Output: number of ways to permute r things from n objects
*****************************************************************/
int nPr(int n, int r){
	return Factorial(n) / Factorial(n-r);
}