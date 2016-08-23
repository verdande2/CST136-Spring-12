#include "Fraction.h"

Fraction Add(Fraction const& t1, Fraction const& t2);
Fraction Subtract(Fraction const& minuend, Fraction const& subtrahend);
Fraction Multiply(Fraction const& f1, Fraction const& f2);
Fraction Divide(Fraction const& dividend, Fraction const& divisor);

int main(){
	Fraction f1;
	Fraction f2(2L, 0L);
	Fraction f3(f2);
	f1.Print();
	f2.Print();
	f3.Print();
	f3 = Add(f3, Fraction(-5, 4));
	f1 = Add(f2, f3);
	f1.Print();
	f1 = Subtract(f2, f3);
	f1.Print();
	f1 = Multiply(f2, f3);
	f1.Print();
	f1.Inc().Inc().Print();  // What’s going on – notice the chaining
	f1 = Divide(f2, f3);
	f1.Print();
	system("pause");
	return 0;
}

Fraction Add(Fraction const& t1, Fraction const& t2){
	return Fraction(t1.m_num * t2.m_denom + t2.m_num * t1.m_denom, t1.m_denom * t2.m_denom);
}
Fraction Subtract(Fraction const& minuend, Fraction const& subtrahend){
	return Fraction(minuend.m_num * subtrahend.m_denom - subtrahend.m_num * minuend.m_denom, minuend.m_denom * subtrahend.m_denom);
}
Fraction Multiply(Fraction const& f1, Fraction const& f2){
	return Fraction(f1.m_num * f2.m_num, f1.m_denom * f2.m_denom);
}
Fraction Divide(Fraction const& dividend, Fraction const& divisor){
	return Fraction(dividend.m_num * divisor.m_denom, dividend.m_denom * divisor.m_num);
}