/****************************************************************
* Overview: Basic exception class. Has a string to record the error 
*			text, and a templated value to contain the value that 
*			triggered the exception (if applicable)
*****************************************************************/
#pragma once
#include <string>
using std::string;
using std::ostream;

template <class T>
class Exception{
	private:
		string m_text;
		T m_value;

	public:
		Exception(string error_text, T value);
		~Exception();

		string Text() const;
		T Value() const;
};

/****************************************************************
* Overview: Basic constructor, sets error text and value upon instantiation
*****************************************************************/
template <class T>
Exception<T>::Exception(string error_text, T value) : m_text(error_text), m_value(value) {}

/****************************************************************
* Overview: Basic destructor
*****************************************************************/
template <class T>
Exception<T>::~Exception(){}

/****************************************************************
* Overview: Returns the error text
*****************************************************************/
template <class T>
string Exception<T>::Text() const{
	return m_text;
}

/****************************************************************
* Overview: Returns the value that triggered the exception
*****************************************************************/
template <class T>
T Exception<T>::Value() const{
	return m_value;
}

/****************************************************************
* Overview: Overloaded << for exception class
*****************************************************************/
template <class T>
ostream& operator<<(ostream& stream, Exception<T> const& object){
	stream << "EXCEPTION: " << object.Text() << " Value: '" << object.Value() << "'";
	return stream;
}