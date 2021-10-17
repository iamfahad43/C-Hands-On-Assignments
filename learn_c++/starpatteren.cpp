#include <iostream>
#include <string>

using namespace std;

int main() {
	int user_inp;
	cout << "\nEnter a number: \n" << endl;
	cin >> user_inp;
	
	for (int i=1; i<=user_inp; i++) {
	      cout << endl; 	
	    for (int j=1; j<=i; j++)
		cout << "* ";
		

	}
}


