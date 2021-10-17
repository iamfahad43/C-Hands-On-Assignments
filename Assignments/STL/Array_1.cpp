#include <iostream>
#include <string>
#include <array>

using namespace std;

int main() {
	int LEN;
	cout << "\n Enter the Length of class between 1-100 : \n ";
	cin >> LEN;
	string user_inp;

	array<string, 100> myarray;
	for (int i=1; i<=LEN; i++) {
		cout << "\nEnter Student " << i << " name : " << endl;
		cin >> myarray[i];
	}

	for (int j=1; j<=LEN; j++) {
		cout << "\nThe Student " << j << " name is: " << myarray[j] << endl;
	}
}

