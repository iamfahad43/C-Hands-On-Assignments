#include <iostream>
#include <string>
#include <list>

using namespace std;

int main() {
	list <string> mylist;
	int len;
	string user_input;
	cout << "\nEnter the length of list:\n";
	cin >> len;

	for (int i=1; i<=len; i++){
		cout << "\nEnter the " << i << " no. :\n" << endl;
		cin >> user_input;
		mylist.push_back(user_input);
	}

	for (auto it=mylist.begin(); it!=mylist.end(); ++it)
		cout << * it ;
}

