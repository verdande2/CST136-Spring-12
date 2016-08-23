/****************************************************************
* Overview: Small class representing a doubly linked list node.
*			Has basic getters and setters and is basically an 
*			overglorified struct
*****************************************************************/
#pragma once

template <class T>
class Node{
	private:
		Node<T>* m_next;
		Node<T>* m_prev;

		T* m_data;

	protected:

	public:
		Node(Node<T>* prev = 0, Node<T>* next = 0);
		~Node();

		Node<T>* Next() const;
		void Next(Node<T>* next);

		Node* Prev() const;
		void Prev(Node* prev);

		T* Data() const;
		void Data(T* const& data);
};

/****************************************************************
* Overview: Basic constructor and destructor. 2 arg constructor 
*			takes prev and next Node*. Destructor does not delete 
*			anything, as deletion is handled by list class. This 
*			could (should?) have been a struct.
*****************************************************************/
template <class T>
Node<T>::Node(Node<T>* prev, Node<T>* next) : m_prev(prev), m_next(next) {}
template <class T>
Node<T>::~Node(){
	delete m_data;
}


/****************************************************************
* Overview: Basic getters and setters for m_next, m_prev, and m_data
*****************************************************************/
template <class T>
Node<T>* Node<T>::Next() const {return m_next;}
template <class T>
void Node<T>::Next(Node<T>* next){m_next = next;}

template <class T>
Node<T>* Node<T>::Prev() const {return m_prev;}
template <class T>
void Node<T>::Prev(Node<T>* prev){m_prev = prev;}

template <class T>
T* Node<T>::Data() const {return m_data;}
template <class T>
void Node<T>::Data(T* const& data){m_data = data;}