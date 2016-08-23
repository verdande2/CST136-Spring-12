#pragma once
#include "Exception.h"

const int MAX(128);

template <class T>
class Stack{
	private:
		T m_stk[MAX];
		int m_top;
	public:
		Stack() : m_top(-1){};
		~Stack();
		void Push(T const& var);
		T Pop();
};

template <class T>
Stack<T>::~Stack(){}

template <class T>
void Stack<T>::Push(T const& item){
	if(m_top < MAX-1){
		m_stk[++m_top] = item; // assumes assignment operator is set properly for T
	}else{
		throw Exception<T>("No more space on the stack. Tried to push()", item);
	}
}

template <class T>
T Stack<T>::Pop(){
	if(m_top>=0){
		return m_stk[m_top--];
	}else{
		throw Exception<const char*>("Tried popping off empty stack.", "N/A");
	}
	
}