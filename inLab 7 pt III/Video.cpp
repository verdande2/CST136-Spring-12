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