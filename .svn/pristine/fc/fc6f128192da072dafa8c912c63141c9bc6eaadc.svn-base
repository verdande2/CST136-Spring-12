#pragma once

#include <iostream>
using std::cout;
using std::endl;
class Fraction{
	friend Fraction Add(Fraction const& t1, Fraction const& t2);
	friend Fraction Subtract(Fraction const& minuend, Fraction const& subtrahend);
	friend Fraction Multiply(Fraction const& f1, Fraction const& f2);
	friend Fraction Divide(Fraction const& dividend, Fraction const& divisor);

	public:
		inline Fraction(long num = 0, long denom = 1) : m_num(num), m_denom(denom) {
			if(!denom){
				m_denom = 1; // if denom is 0, set to 1
			}
			Reduce();
		}
		inline Fraction(const Fraction& frac) : m_num(frac.m_num), m_denom(frac.m_denom) {
			Reduce();
		}

		Fraction Print();
		inline Fraction Inc(){
			return Add(*this, Fraction(1,1));
		}
	private:
		long m_num;
		long m_denom;

		void Reduce(); // private method to reduce fraction to lowest terms

		static long GCD(long m, long n); // static to keep it out of global namespace, private because only Fraction needs it
};