#include "sport.h"

std::istream& Flush(std::istream& istream);

/****************************************************************
* Overview: Constructor (no arg) sets length and roster pointer = 0
*****************************************************************/
Sport::Sport() : m_length(0), m_roster(0) {}

/****************************************************************
* Overview: Destructor, deletes all players, and the roster
*****************************************************************/
Sport::~Sport(){
	while(m_length!=0){
		delete m_roster[--m_length];
	}
	delete [] m_roster;
}

/****************************************************************
* Overview: Display Menu and get menu selection, and handle user choice
*****************************************************************/
void Sport::PromptUser(){
	char selection = '-';

	while(selection!='E'){
		system("cls");
		cout << "Menu:" << endl;
		cout << "A) Add a player" << endl;
		cout << "S) Search for/Display a player" << endl;
		cout << "D) Display all players" << endl;
		cout << "R) Remove a player" << endl;
		cout << "E) Exit" << endl;
		cout << endl;
		cout << "** Total Current Players: " << m_length << " **" << endl << endl;

		cout << "Selection: ";
		cin >> selection;

		selection = toupper(selection);

		switch(selection){
			case 'A':
				PlayerAdd();
				system("pause");
				break;
			case 'S':
				PlayerSearch();
				system("pause");
				break;
			case 'D':
				PlayerList();
				system("pause");
				break;
			case 'R':
				PlayerDelete();
				system("pause");
				break;
			case 'E':
				cout << "Exiting now..." << endl;
				break;
			default:
				cout << "Invalid menu selection" << endl;
				system("pause");
				break;
		}
	}
}

/****************************************************************
* Overview: This function will prompt for a player's data and 
*			then append them to the roster
*****************************************************************/
void Sport::PlayerAdd(){
	Player* new_player = 0;
	String name;
	char buffer[64];
	int grade;
	double gpa;

	
	cout << "Name: ";
	Flush(cin);
	cin.getline(buffer,64);
	cout << "Grade: ";
	cin >> grade;
	cout << "GPA: ";
	cin >> gpa;

	new_player = new Player(buffer, grade, gpa);
	PlayerAdd(new_player);
}

/****************************************************************
* Overview: This function will append a player to the roster.
*****************************************************************/
void Sport::PlayerAdd(Player* new_player){
	Player** temp = new Player*[m_length+1];
	for(int i = 0; i < m_length; ++i){
		temp[i] = m_roster[i];
	}
	temp[m_length++] = new_player;
	delete [] m_roster;
	m_roster = temp;
}

/****************************************************************
* Overview: This function will prompt for a player to remove and 
*			remove that player from the roster.
*****************************************************************/
void Sport::PlayerDelete(){
	char buffer[32];
	bool found = false;

	cout << "Name to search for (case insensitive): ";
	Flush(cin);
	cin.getline(buffer,32);

	for(int i=0; i<m_length; i++){
		if(m_roster[i]->Search(buffer)){
			found = true;
			PlayerDelete(m_roster[i]);
			cout << "Player '" << buffer << "' was successfully removed." << endl;
		}
	}
	if(!found){
		cout << "No records match that string." << endl;
	}
}
/****************************************************************
* Overview: This function will remove a player from the roster.
*****************************************************************/
void Sport::PlayerDelete(Player* player){
	Player** temp = new Player*[m_length-1];
	for(int i = 0, j=0; i < m_length; ++i){
		if(m_roster[i]!=player){
			temp[j++] = m_roster[i];
		}else{
			delete m_roster[i];
		}
	}
	m_length--;
	delete [] m_roster;
	m_roster = temp;
}

/****************************************************************
* Overview: This function lists the entire roster
*****************************************************************/
void Sport::PlayerList() const{
	Player::DisplayHeaders();
	for(int i=0; i<m_length; i++){
		m_roster[i]->Display();
	}
}

/****************************************************************
* Overview: This function will search the roster for a search 
*			query and display results, if any.
*****************************************************************/
void Sport::PlayerSearch() const{
	char buffer[32];
	bool found = false;

	cout << "Name to search for (case sensitive): ";
	Flush(cin);
	cin.getline(buffer,32);

	cout << "Results:" << endl;
	Player::DisplayHeaders();
	for(int i=0; i<m_length; i++){
		if(m_roster[i]->Search(buffer)){
			found = true;
			m_roster[i]->Display();
		}
	}
	if(!found){
		cout << "No records match that string." << endl;
	}
}


/****************************************************************
* Overview: This function flushes the keyboard buffer
*			Note: Taken directly from Nagler book pg 443
*****************************************************************/
std::istream& Flush(std::istream& stream){
	static std::streamsize const MAX_LINE_LENGTH = std::numeric_limits<std::streamsize>::max();
	stream.clear(stream.rdstate() & ~std::ios_base::failbit);
	if(stream.good())
	{
		std::streambuf *ptr = stream.rdbuf();
		std::streamsize charactersToIgnore = ptr->in_avail();
		if(charactersToIgnore > 0)
			stream.ignore(MAX_LINE_LENGTH, '\n');
	}
	return stream;
}