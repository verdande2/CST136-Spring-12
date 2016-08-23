/****************************************************************
* Author:					Andrew Sparkes
* Date Created:				3/29/11
* Last Modification Date:	3/31/11
* Lab Number:				CST 136 Lab 1
* Filename:					main.cpp
*
* Overview: This program will make change from a userinputted 
*			value and display the result.
*
*    Input: The program takes user input from the console.
*
*   Output: The program outputs the change made from the 
*			inputted value.
*****************************************************************/
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

struct Coin{
	int denom;
	long count;
	const char* single;
	const char* multiple;
};

void defaultValues(Coin coins[]);
void Change(long &change, Coin &coin);
void Print(const Coin &coin);

int main(){
	Coin coins[4];
	defaultValues(coins);

	long value = 0;

	while(value != -1){
		cout << "Please enter the value: ";
		cin >> value;

		if(value!=-1){
			for(int i=0; i<4; ++i){
				Change(value, coins[i]);
			}
			cout << "Change would be: ";
			
			bool outputStarted = false;
			for(int i=0; i<4; ++i){
				// intelligently put commas in.
				if(outputStarted && coins[i].count){
					cout << ", ";
				}else{
					outputStarted = true;
				}
				Print(coins[i]);
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

/****************************************************************
* Overview: This function will set the default values for the 
*			coins array.
*
*    Input: coins, array of 4 Coin structs
*
*   Output: coins is properly intialized to default values.
*****************************************************************/
void defaultValues(Coin coins[]){
	for(int i=0; i<4; ++i){
		coins[i].count = 0;
	}

	coins[0].denom = 25;
	coins[0].single = "Quarter";
	coins[0].multiple = "Quarters";
	
	coins[1].denom = 10;
	coins[1].single = "Dime";
	coins[1].multiple = "Dimes";
	
	coins[2].denom = 5;
	coins[2].single = "Nickel";
	coins[2].multiple = "Nickels";
	
	coins[3].denom = 1;
	coins[3].single = "Penny";
	coins[3].multiple = "Pennies";
}

/****************************************************************
* Overview: This function will make change from passed in value.
*
*    Input: change, long representing the amount*100 (to account 
*				for precision problems)
*			coin, a Coin struct
*
*   Output: The function breaks change into as many coins as 
*			possible and stores the count.
*****************************************************************/
void Change(long &change, Coin &coin){
	int temp = 0;
	// take the floor of change/denom, store it in temp
	temp = change/coin.denom;

	// the count for this denom is temp
	coin.count = temp;

	// subtract off the denomination*count, leaving change as the remainder
	change -= temp*coin.denom;
}

/****************************************************************
* Overview: This function will print out the given coin in human 
*			readable form.
*
*    Input: coin, a Coin struct (const ref)
*
*   Output: Outputs the coin to the console.
*****************************************************************/
void Print(const Coin &coin){	
	// only output if >0
	if(coin.count){
		// display count and appropriate string if single or multiple
		if(coin.count==1){
			cout << coin.count << " " << coin.single;
		}else{
			cout << coin.count << " " << coin.multiple;
		}
	}
}