#include "Video.h"

double Video::Length(){
	return m_length;
}
void Video::Length(double length){
	m_length = length;
}
Video::Video() : m_length(0) {
	std::cout << "Video Constructor" << std::endl;
}
Video::~Video(){
	std::cout << "Video Destructor" << std::endl;
}
void Video::GetData(){
	char buffer[64];
	cout << "Enter Video Title: " << endl;
	Publication::Flush(cin);
	cin.getline(buffer,64);
	Title(buffer);
	cout << "Enter Video Price: " << endl;
	cin >> m_price;
}

void Video::PutData(){
	cout << Title() << " $" << Price() << " " << Length() << "mins" << endl;
}