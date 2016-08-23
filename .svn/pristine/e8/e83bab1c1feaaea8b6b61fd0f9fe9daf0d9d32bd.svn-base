#include "Jar.h"


int Jar::instanceCount = 0;

Jar::Jar(int count, int weight, char type) : m_count(count), m_weight(weight), m_type(type) {
	++Jar::instanceCount;
}

Jar::~Jar(){
	--Jar::instanceCount;
}

char Jar::GetType() const{
	return m_type;
}

int Jar::GetMg() const{
	return m_weight;
}

void Jar::TakeCandy(int howMuch){
	int error = 0;
	if(howMuch < 0){
		error = 1; // adding a negative amount
	}
	if(howMuch > m_count){
		error = 2; // too much candy trying to be removed
	}
	if(!error){
		m_count -= howMuch;
	}
}

void Jar::RefillCandy(int howMuch){
	m_count += howMuch;
}

int Jar::CheckInventory() const{
	return m_count;
}

int Jar::CheckWeight() const{
	return m_count*GetMg();
}

void Jar::DisplayHeaders(){
	cout << setw(Jar::TYPE_WIDTH) << left << "Type";
	cout << setw(Jar::WEIGHT_WIDTH) << left << "Weight";
	cout << setw(Jar::INVENTORY_WIDTH) << left << "Count";
	cout << setw(Jar::TOTAL_WEIGHT_WIDTH) << left << "Total Weight" << endl;
}

void Jar::ShowCount(){
	// this function cannot access members of a jar, as it is static, and therefore has no this pointer.
	cout << "Current Jar Count : " << Jar::instanceCount << endl;
}