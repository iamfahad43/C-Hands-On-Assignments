#include <iostream>
#include <string>

using namespace std;

void YesFunc() {
	cout << "Your information is logged successfully " << endl;
}

int main() {
	char ch;
	cout << " Enter your choice (y/n)  " << endl;
	cin >> ch;
	if (ch == 'y') {
		YesFunc();
		cout << "Would you want to log again? (y/n) " << endl;
		cin >> ch;
	} else {
		cout << "Else statement" << endl;
	}
}


