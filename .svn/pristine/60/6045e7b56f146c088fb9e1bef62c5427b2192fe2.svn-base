#include "Node.h"

/****************************************************************
* Overview: Basic constructor and destructor. 2 arg constructor 
*			takes prev and next Node*. Destructor does not delete 
*			anything, as deletion is handled by list class. This 
*			could (should?) have been a struct.
*****************************************************************/
Node::Node(Node* prev, Node* next) : m_prev(prev), m_next(next) {}
Node::~Node(){}


/****************************************************************
* Overview: Basic getters and setters for m_next, m_prev, and m_data
*****************************************************************/
Node* Node::Next() const {return m_next;}
void Node::Next(Node* next){m_next = next;}

Node* Node::Prev() const {return m_prev;}
void Node::Prev(Node* prev){m_prev = prev;}

int Node::Data() const {return m_data;}
void Node::Data(int data){m_data = data;}