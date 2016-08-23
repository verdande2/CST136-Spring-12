#pragma once
#include <cstring>

class Book{
	public:
		Book(char* title, int id, bool checkedIn = false);
		Book(const Book &book);
		Book();
		~Book();


		void Title(char* title){
			m_title = new char[strlen(title)+1];
			strcpy(m_title, title);
		}
		char* Title() const {return m_title;}

		void Id(int id){m_id = id;}
		int Id() const {return m_id;}

		void CheckIn(){m_checkedIn = true;};
		void Checkout(){m_checkedIn = false;};
		bool CheckedIn() const {return m_checkedIn;};

		void Display() const;

		static void DisplayHeaders();
		static const int TITLE_WIDTH = 15;
		static const int ID_WIDTH = 8;
		static const int STATUS_WIDTH = 8;

	private:
		char* m_title;
		int m_id;
		bool m_checkedIn;
};

