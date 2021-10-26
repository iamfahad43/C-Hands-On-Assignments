#include <iostream>
#include <map>
#include <string>

using namespace std;

int SetDetails(multimap<string, int> mlmap) {
	string key;
	int val;
	cout << "\nEnter your name: " << endl;
	cin >> key;
	cout << "\nEnter your salary: " << endl;
	cin >> val;
	mlmap.insert(make_pair(key,val));
	cout << "\nYour information is logged Successfully" << endl;
	return 1;
}

void GetDetails(multimap<string, int> mlmap) {
	string local;
	cout << "\nHere is the list of employee: " << endl;
	for (auto it = mlmap.begin(); it!=mlmap.end(); it++) {
		cout << (*it).first << endl;
	}
	cout << "\nEnter the name of employee you want to see the salary: " << endl;
	cin >> local;
	cout << "Salary of " << local << " is: " << mlmap.find(local)->second;
}

int main() {
	multimap<string, int> mltimap;
	char choice;
	char bahir;
	cout << "\nWould you want to log? (y/n) " << endl;
	cin >> choice;

	if (choice=='y'){
		SetDetails(mltimap);
		cout << "\nWould you want to log more? (y/n) " << endl;
		cin >> choice;
		if (choice == 'y'){
			SetDetails(mltimap);
		} else {
			GetDetails(mltimap);
		}
	} else if (choice=='n'){
		cout << "You want to see the details? (y/n) " << endl;
		cin >> bahir;
		if (bahir=='y'){
			GetDetails(mltimap);
		} else {
			cout << " Thank you for your time " << endl;
		}
     }

}




