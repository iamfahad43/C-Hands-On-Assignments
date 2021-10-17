#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {
	string key;
	int value;
	char ch;
	char choice;
	map<string, int> StudentDetails;
	map<string, int>::iterator it = StudentDetails.begin();

	do {
 		cout << "\nWould you like to log? (y/n) \n";
		cin >> choice;

		if (choice == 'y') {
			cout << "\n Enter Student Name:\n " << endl;
			cin >> key;
			cout << "\n Enter Roll Number: \n " << endl;
			cin >> value;
			//StudentDetails.insert (it, pair<string, int>(key, value));

			StudentDetails.insert ( make_pair(key, value));
			//StudentDetails.insert (make_pair<string, int>(key, value));

			//exchangeMap[galaxyOrderId] = exchOrderId;
			//galaxyMap.insert(make_pair<>(galaxyOrderId;

			cout << "\n Enter e to exit, y to log more, n to show result " << endl;
		}
	       	else {
			cout << "\n The details you loged is: \n" << endl;
			for (it=StudentDetails.begin(); it!=StudentDetails.end(); ++it)
				cout << it->first << " and its roll number: " << it->second << endl;
			cout << "\n Enter e to exit, y to log more, n to show result " << endl;
		}
	     cin >> ch;
	   }while (ch != 'e');
}


