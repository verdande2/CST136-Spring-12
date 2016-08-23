#include <iostream>
using std::cout;
using std::cin;
using std::endl;

class Coin{
	private:
		int m_denom;
		long m_count;
		const char* m_single;
		const char* m_multiple;
	public:
		Coin(int denom, long count);
		~Coin();
		void Change(long &change);
		void Print();
		long Count();
		void Count(long count);
		int Denom();
};

long Coin::Count(){
	return m_count;
}
void Coin::Count(long count){
	m_count = count;
}
int Coin::Denom(){
	return m_denom;
}
Coin::Coin(int denom, long count=0) : m_denom(denom), m_count(count) {
	switch(denom){
		case 1:
			m_single = "Penny";
			m_multiple = "Pennies";
			break;
		case 5:
			m_single = "Nickel";
			m_multiple = "Nickels";
			break;
		case 10:
			m_single = "Dime";
			m_multiple = "Dimes";
			break;
		case 25:
			m_single = "Quarter";
			m_multiple = "Quarters";
			break;
	}
	cout << "Constructing Coin" << endl;
}
Coin::~Coin(){
	cout << "Destructing Coin" << endl;
}

void Coin::Change(long &change){
	int temp = 0;
	// take the floor of change/denom, store it in temp
	temp = change/m_denom;

	// the count for this denom is temp
	m_count = temp;

	// subtract off the denomination*count, leaving change as the remainder
	change -= temp*m_denom;
}
void Coin::Print(){	
	// only output if >0
	if(m_count){
		// display count and appropriate string if single or multiple
		if(m_count==1){
			cout << m_count << " " << m_single;
		}else{
			cout << m_count << " " << m_multiple;
		}
	}
}
int main(){
	Coin coins[] = {Coin(25), Coin(10), Coin(5), Coin(1)};

	long value = 0;

	while(value != -1){
		cout << "Please enter the value: ";
		cin >> value;

		if(value!=-1){
			for(int i=0; i<4; ++i){
				coins[i].Change(value);
			}
			cout << "Change would be: ";
			
			bool outputStarted = false;
			for(int i=0; i<4; ++i){
				// intelligently put commas in.
				if(outputStarted && coins[i].Count()){
					cout << ", ";
				}else{
					outputStarted = true;
				}
				coins[i].Print();
			}
			cout << endl << endl;

			system("pause");
		}

		system("cls");
	}
	cout << "Good day!" << endl;

	system("pause");
	return 0;
}

