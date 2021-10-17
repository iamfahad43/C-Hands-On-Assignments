#include <iostream>
#include <string>
#include <map>


using namespace std;

int main() {
	string sal;
	string key;
	int val;
	char choice;
	multimap<string, int> mymultimap;
	mymultimap.insert(make_pair("Ali", 34000));
	mymultimap.insert(make_pair("Hamza", 33220));
	mymultimap.insert(make_pair("Umair", 31000));
       
       	cout << "Would you want to log? (y/n) " << endl;
	cin >> choice;
	if (choice == 'y'){
		cout << "\nEnter the name: " << endl;
		cin >> key;
		cout << "\nEnter the Salaray: " << endl;
		cin >> val;
		mymultimap.insert(make_pair(key, val));
	        cout << "\nHere is the list of employes: " << endl;
	        for (auto it=mymultimap.begin(); it!=mymultimap.end(); it++)
		        cout << (*it).first << endl;
        
	        cout << "\nEnter the Employee name to check the salary: " << endl;
	        cin >> sal;

	        cout << "\nSalary of: " << sal << " is = " << mymultimap.find(sal)->second << endl;
	} else {
		
	         cout << "\nHere is the list of employes: " << endl;
	         for (auto it=mymultimap.begin(); it!=mymultimap.end(); it++)
		         cout << (*it).first << endl;
        
	         cout << "\nEnter the Employee name to check the salary: " << endl;
	         cin >> sal;

	         cout << "\nSalary of: " << sal << " is = " << mymultimap.find(sal)->second << endl;
	}

}
	

