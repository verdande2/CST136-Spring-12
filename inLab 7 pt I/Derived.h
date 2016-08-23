#ifndef DERIVED
#define DERIVED

#include "Base.h"
class Derived : public Base { // changing to private inheritance causes many access problems
	private:
		int ds, dt;
	protected:
	public:
		Derived(int s, int t);
		~Derived();
		void ShowD();
};
#endif