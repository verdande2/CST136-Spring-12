#pragma once
#include <iostream>
#include <iomanip>
using std::cout;
using std::endl;
using std::setw;
using std::left;

class Jar{
	public:
		Jar();
		Jar(int count, int weight, char type);
		~Jar();

		char GetType() const;
		int GetMg() const;
		void TakeCandy(int howMuch);
		void RefillCandy(int howMuch); // making this const results in problems, as it is NOT a constant method. It changes a member of Jar
		int CheckInventory() const;
		int CheckWeight() const;

		static void DisplayHeaders();
		static const int TYPE_WIDTH = 6;
		static const int WEIGHT_WIDTH = 6;
		static const int INVENTORY_WIDTH = 6;
		static const int TOTAL_WEIGHT_WIDTH = 12;
		static void ShowCount();

	private:
		int m_count;
		int m_weight;
		char m_type;
		static int instanceCount;
};