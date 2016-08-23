class Player;

/****************************************************************
* Overview: This class models a sport, it keeps a roster of 
*			players, and the count of those players. It has only 
*			a no argument constructor. DisplayMenu() is the menu 
*			driven portion. It will display menu, take a selection 
*			and perform the neccessary function. Add() will prompt 
*			user to type in player info and then append it to the 
*			roster. Add(Player*) does same sans the user prompt. 
*			List() will display all current players in roster. 
*			Search() will take a string and search out that player 
*			and if found display that player.
*****************************************************************/
class Sport{
	private:
		char PromptUser();
		Player** m_roster;
		int m_length;
	public:
		Sport();
		~Sport();
		void DisplayMenu();
		void Add();
		void Add(Player* new_player);
		void List();
		void Search() const;
};