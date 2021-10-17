// in this file I will cover the access specifier fundamental, how to access in child class and which members are accessed 

#include <iostream>
#include <string>

using namespace std;

class Base {
	private:
		int Bprv = 1;
	protected:
		int Bpro = 2;
	public:
		int Bpub = 3;

		// function to access the private member of same class
		int getPrv() {
			return Bprv;
		}
};
/*
// Publically Inherited Child Class
class ChildPub : public Base {
	// as private members should not be called from outside the class, I am not calling the privated member
	
	public:
		// function to access the protected member of base class
		int ChildPubPro() {
			return Bpro;
		}

		// function to access the public member of base class
		int ChildPubPub() {
			return Bpub;
		}
};
*/

// Protectedly Inherited Child Class
class ChildPro : protected Base {
	// as private members should not be called from outside the class, I am not calling the privated member
	
	public:
		// function to access the protected member of base class
		int ChildProPro() {
			return Bpro;
		}

		// function to access the public member of base class
		int ChildProPub() {
			return Bpub;
		}
};

int main() {
	ChildPro myObj;

        cout <<	myObj.ChildProPro() << endl;
	cout << myObj.ChildProPub() << endl;

	// direct acces the public member of base class
	// working for public inheritance, not working for protected inheritance
	//cout << myObj.getPrv() << endl;

	// working for public inheritance, not for protected inheritance
	//cout << "\nProlic variable of base class value is: " << myObj.Bpub << endl;
}


