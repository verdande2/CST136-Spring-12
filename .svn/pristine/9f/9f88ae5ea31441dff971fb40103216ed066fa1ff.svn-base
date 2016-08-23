#include "Fraction.h"

Fraction operator+(Fraction const& t1, Fraction const& t2);
Fraction operator-(Fraction const& minuend, Fraction const& subtrahend);
Fraction operator*(Fraction const& f1, Fraction const& f2);
Fraction operator/(Fraction const& dividend, Fraction const& divisor);
ostream& operator<<(ostream& stream, Fraction const& object);

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

ostream& operator<<(ostream& stream, Fraction const& object){
	stream << object.m_num << "/" << object.m_denom;
	return stream;
}

Fraction operator+(Fraction const& t1, Fraction const& t2){
	return Fraction(t1.m_num * t2.m_denom + t2.m_num * t1.m_denom, t1.m_denom * t2.m_denom);
}
Fraction operator-(Fraction const& minuend, Fraction const& subtrahend){
	return Fraction(minuend.m_num * subtrahend.m_denom - subtrahend.m_num * minuend.m_denom, minuend.m_denom * subtrahend.m_denom);
}
Fraction operator*(Fraction const& f1, Fraction const& f2){
	return Fraction(f1.m_num * f2.m_num, f1.m_denom * f2.m_denom);
}
Fraction operator/(Fraction const& dividend, Fraction const& divisor){
	return Fraction(dividend.m_num * divisor.m_denom, dividend.m_denom * divisor.m_num);
}

