#include "Publication.h"

char* Publication::Title(){
	return m_title;
}
void Publication::Title(char* title){
	m_title = new char[strlen(title)+1];
	strcpy(m_title, title);
}
double Publication::Price(){
	return m_price;
}
void Publication::Price(double price){
	m_price = price;
}
Publication::Publication() : m_title(0), m_price(0) {
	std::cout << "Publication Constructor" << std::endl;
}
Publication::~Publication(){
	delete [] m_title;
	std::cout << "Publication Destructor" << std::endl;
}