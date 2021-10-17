#include<iostream>
#include<string>
using namespace std;


int sum(int a, int b) {
	return a + b;
}

double sum(double a, double b) {
	return a + b;
}

int sum(string a, string b) {
	return atoi(a.c_str()) + atoi(b.c_str());
}

int main() {
	cout << "Sum of int is: " << sum( 4, 5 ) << endl;
	cout << "Sum of Double is: " << sum( 4.0, 5.0 ) << endl;
	cout << "Sum of String is: " << sum( "4", "5" ) << endl;
}


