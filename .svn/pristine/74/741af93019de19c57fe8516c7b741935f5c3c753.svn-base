#include "Fraction.h"
/*
Fraction::Fraction(long num, long denom) : m_num(num), m_denom(denom) {
	if(!denom){
		denom = 1; // if denom is 0, set to 1
	}
	Reduce();
}
Fraction::Fraction(const Fraction& frac) : m_num(frac.m_num), m_denom(frac.m_denom) {
	Reduce();
}*/

long Fraction::GCD(long m, long n){
	// uses Euclid's algorithm for GCD
	return (m==0L ? n : Fraction::GCD(n % m, m));
}

void Fraction::Reduce(){
	// calculate gcd and factor it out of the fraction to reduce it
	long gcd = Fraction::GCD(m_num,m_denom);
	m_num /= gcd;
	m_denom /= gcd;
}
/*
inline Fraction Fraction::Inc(){
	return Add(*this, Fraction(1,1));
}*/

Fraction Fraction::Print(){
	cout << m_num << "/" << m_denom << endl;
	return *this;
}