#include <iostream>
#include <string>
#include <typeinfo>

using namespace std;

template<class Fahad>

class BaseClass {
	public:
		void PrintType(Fahad F) {
			cout << "\nThe type of " << F << " is: " <<typeid(F).name() << endl;
		}
		void PrintSum(Fahad F, Fahad K);
		void PrintDot(Fahad F, Fahad K);
	private:
		Fahad F;
};

// function defination outside the class
template<typename Fahad>
void BaseClass<Fahad>::PrintSum(Fahad F, Fahad K) {
	cout << "\nThe Sum of " << F << " and " << K << " is = " << (F+K) << endl;
}

template<typename Fahad>
void BaseClass<Fahad>::PrintDot(Fahad F, Fahad K) { 
	cout << "\nThe Multiply of " << F << " and " << K << " is = " << (F*K) << endl;
}



int main() {
	BaseClass<int> Obj1;
	BaseClass<float> Obj2;

	Obj1.PrintSum(5, 9);
	Obj1.PrintDot(5, 9);
	Obj2.PrintSum(98, 9);
	Obj2.PrintDot(98, 9);


}

