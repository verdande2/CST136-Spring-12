/****************************************************************
* Overview: This class models a book, with specific attributes:
*				ISBN
*				Author's Last Name
*				Year Published
*				Price
*				Quantity
*			It has functions to modify each attribute individually,
*			as well as Add() and Remove() to adjust quantity 
*			relatively. TotalValue() returns quantity*price. 
*			The class also has a short ISBN validation function, 
*			to verify ISBN checksums.
*****************************************************************/
class Book{
	private:
		char* m_ISBN;
		char* m_authorLast;
		int m_yearPublished;
		long m_price;
		int m_quantity;

	public:
		Book();
		Book(char* isbn, char* authorLast, int yearPublished, long price, int quantity);
		Book(Book* book);
		~Book();

		void Add();
		void Add(int howMany);

		void Remove();
		void Remove(int howMany);

		// getters/setters
		void ISBN(char* isbn);
		char* ISBN() const;

		void AuthorLast(char* authorLast);
		char* AuthorLast() const;

		void YearPublished(int yearPublished);
		int YearPublished() const;

		void Price(long price);
		long Price() const;
		
		void Quantity(int quantity);
		int Quantity() const;

		long TotalValue();

		bool ValidateISBN();
};