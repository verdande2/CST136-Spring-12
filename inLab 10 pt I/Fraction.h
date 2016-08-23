#pragma once

#include <iostream>
using std::cout;
using std::endl;
using std::ostream;

class Fraction{

	friend Fraction operator+(Fraction const& t1, Fraction const& t2);
	friend Fraction operator-(Fraction const& minuend, Fraction const& subtrahend);
	friend Fraction operator*(Fraction const& f1, Fraction const& f2);
	friend Fraction operator/(Fraction const& dividend, Fraction const& divisor);
	friend ostream& operator<<(ostream& stream, Fraction const& fraction);

	public:
		inline Fraction(long num = 0, long denom = 1) : m_num(num), m_denom(denom) {
			if(!denom){
				throw "Tried to set 0 denominator";
			}
			Reduce();
		}
		inline Fraction(const Fraction& frac) : m_num(frac.m_num), m_denom(frac.m_denom) {
			Reduce();
		}

		Fraction Print();
		inline Fraction operator++(){
			Fraction temp((*this)++);
			return temp;
		}
		inline Fraction operator++(int){
			return *this + Fraction(1,1);
		}

	private:
		long m_num;
		long m_denom;

		void Reduce(); // private method to reduce fraction to lowest terms

		static long GCD(long m, long n); // static to keep it out of global namespace, private because only Fraction needs it
};