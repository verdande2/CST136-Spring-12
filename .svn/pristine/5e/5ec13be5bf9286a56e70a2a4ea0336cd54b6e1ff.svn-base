/****************************************************************
* Overview: Small class representing a doubly linked list node.
*			Has basic getters and setters and is basically an 
*			overglorified struct
*****************************************************************/
#ifndef NODE
#define NODE

class Node{
	private:
		Node* m_next;
		Node* m_prev;

		int m_data;

	protected:

	public:
		Node(Node* prev = 0, Node* next = 0);
		~Node();

		Node* Next() const;
		void Next(Node* next);

		Node* Prev() const;
		void Prev(Node* prev);

		int Data() const;
		void Data(int data);
};

#endif