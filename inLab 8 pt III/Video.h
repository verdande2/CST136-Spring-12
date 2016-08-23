#ifndef VIDEO
#define VIDEO
#include "Publication.h"
#include <cstring>
#include <iostream>
using std::endl;
using std::cout;
using std::cin;

class Video : public Publication{
	private:
		double m_length;
	protected:
	public:
		Video();
		~Video();
		double Length();
		void Length(double length);

		void GetData();
		void PutData();
};

#endif