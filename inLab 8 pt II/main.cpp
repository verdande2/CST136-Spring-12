#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#include <iostream>
using std::cout;
using std::endl;
#include <iomanip>
#include <cstring>

#include "ford.h"
#include "toyota.h"

int main(){
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	Car* inventory[] = {new Car, new Ford, new Toyota };
	Ford f1;
	//f1.identify(); // unsure why this was in here, as program output does not match below with this line uncommented...
	const int size = sizeof(inventory) / sizeof(*inventory);   /n/ BEST MAKE SENSE => calculates the size of the array via taking the size of the whole divided by the size of the first element
	
	for(int i = 0; i < size; ++i){
		inventory[i]->identify();		// WATCH THIS - CHECK OUT THE VPTR & VTABLE!
		delete inventory[i];
	}

	system("pause");
	return 0;
}
/* The output of this program is:

I am a car
Car destructor
I am a Ford
Car destructor
I am a Toyota
Car destructor

*/
