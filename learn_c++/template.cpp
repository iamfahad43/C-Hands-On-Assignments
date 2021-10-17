
#include<iostream>
#include<string>

using namespace std;

template <class T>
T sum(T a, T b) {
	return (a + b);
}

int main() {
	auto c = sum <int> (4, 5);
	auto z = sum <double> (4, 5);
	auto k = sum <string> ("4", "5");
	
	cout << "\nSum of integers is: " << c << endl;
	cout << "\nSum of double is: " << z << endl;
	cout << "\nSum of string is: " << k << endl;
}

