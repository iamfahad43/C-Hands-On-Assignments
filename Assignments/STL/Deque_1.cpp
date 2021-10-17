#include <iostream>
#include <string>
#include <deque>

using namespace std;

int main() {
	deque<int> mydeque;
	int size;
	cout << "\nEnter the length of Queue: \n" << endl;
	cin >> size;
	int user_val;
	char inp_type;

	for (int i=1; i<=size; ++i) {
	       cout << "\nWould you like to enter in beggining? (y/n) " << endl;
	       cin >> inp_type;
	       switch (inp_type) {
	       	       case 'y':
	                       cout << "\nEnter the number: \n" << endl;
	                       cin >> user_val;
                               mydeque.push_front(user_val);
		               break;
	 	       case 'n':
		               cout << "\nEnter number to add at the end: \n" << endl;
		               cin >> user_val;
		               mydeque.push_back(user_val);
		               break;
	       }
	}
	// display the results
	cout << "\nYou entered \n";
	for (auto it=mydeque.begin(); it!=mydeque.end(); ++it) {

		cout << * it ;
	}

	//trying some hard core values at the end of this container
	cout << "\nTrying to add some hardcore values\n" << endl;
	mydeque.push_back(55);
	mydeque.push_front(55);

	for (auto r=mydeque.begin(); r!=mydeque.end(); ++r)
		cout << *r ;
	        cout << endl;

}





