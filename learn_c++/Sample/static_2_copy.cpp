#include<iostream>
#include<string>
using namespace std;

void callable() {
	static int static_variable = 1;
	int simple_variable = 1;

	cout << " Before increasing...   Static variable:  " << static_variable << " and non_static is: " << simple_variable << endl;

	static_variable++;
	simple_variable++;

	cout << " \n After increasing...  \nStatic: " << static_variable << "  and non_static: " << simple_variable << endl;
}


int main() {
	// loop through this to check exactly what they should do
	
	int i;
	cout << " Enter a number up to there the loop will continue: \n ";
	cin >> i;

	for (int j=1; j<i; j++) {

		callable();

	}

}


