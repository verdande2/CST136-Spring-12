#include <iostream>
#include <cstring>
#include <iomanip>
#include "Jar.h"
using std::cout;
using std::endl;
using std::left;
using std::setw;

void Print(Jar const& jar);

int main(){
	cout << "Making a jar." << endl;
	Jar DonnasCandyJar(200,100,'C');

	Jar::DisplayHeaders();
	Print(DonnasCandyJar);
	cout << endl;

	// attempting to change a private member
	//DonnasCandyJar.m_type = 'M'; // inaccessible, will not compile.

	// making a const Jar object and attempting to use const and nonconst methods on it
	cout << "Making a const jar. " << endl;
	const Jar AndrewsCandyJar(100, 500, 'S'); 
	
	Jar::DisplayHeaders();
	Print(AndrewsCandyJar); // This tests GetType(), GetMg(), CheckInventory() and CheckWeight(), all 4 are const
	cout << endl;

	// testing the nonconst methods. both will not compile.
	//AndrewsCandyJar.RefillCandy(5); // try to add 5 candies to jar
	//AndrewsCandyJar.TakeCandy(5); // try to remove 5 candies from jar
	
	Jar::ShowCount();
	//Jar::instanceCount++; // doesn't work, as instanceCount is private.
	//Jar::ShowCount();

	// making sure the static member is counting correctly.
	cout << "Making another jar of slices. " << endl;
	Jar AnotherRandomCandyJarFullOfSlices(100, 200, 'S');
	Jar::ShowCount();

	cout << "Creating an array of 3 Jars." << endl;
	Jar* ArrayOfCandyJars[] = { (new Jar(5, 125, 'C')), (new Jar(25, 150, 'S')), (new Jar(50, 85, 'C'))}; 
	Jar::ShowCount();

	cout << "Deleting array of 3 Jars" << endl;
	for(int i=0; i<3; ++i){
		delete ArrayOfCandyJars[i];
	}
	Jar::ShowCount();

	system("pause");
	return 0;
}

void Print(Jar const& jar){
	cout << setw(Jar::TYPE_WIDTH) << left << jar.GetType();
	cout << setw(Jar::WEIGHT_WIDTH) << left << jar.GetMg();
	cout << setw(Jar::INVENTORY_WIDTH) << left << jar.CheckInventory();
	cout << setw(Jar::TOTAL_WEIGHT_WIDTH) << left << jar.CheckWeight() << endl;
}