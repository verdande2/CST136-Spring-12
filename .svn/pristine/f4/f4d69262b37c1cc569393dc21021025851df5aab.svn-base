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
void Publication::GetData(){
	char buffer[64];
	cout << "Enter Publication Title: " << endl;
	Publication::Flush(cin);
	cin.getline(buffer,64);
	Title(buffer);
	cout << "Enter Publication Price: " << endl;
	cin >> m_price;
}
void Publication::PutData(){
	cout << Title() << " $" << Price() << endl;
}
/****************************************************************
* Overview: This function flushes the keyboard buffer
*			Note: Taken directly from Nagler book pg 443
*****************************************************************/
std::istream& Publication::Flush(std::istream& stream){
	static std::streamsize const MAX_LINE_LENGTH = std::numeric_limits<std::streamsize>::max();
	stream.clear(stream.rdstate() & ~std::ios_base::failbit);
	if(stream.good())
	{
		std::streambuf *ptr = stream.rdbuf();
		std::streamsize charactersToIgnore = ptr->in_avail();
		if(charactersToIgnore > 0)
			stream.ignore(MAX_LINE_LENGTH, '\n');
	}
	return stream;
}