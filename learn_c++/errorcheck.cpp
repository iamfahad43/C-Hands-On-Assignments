#include<iostream>
#include<string>
using namespace std;

// when use string as type of function and call integer --> error pop up "could not convert int to str" 
// the solution is that convert the integer values to string by using to_string function, it takes an integer value as a parameter and convert this into string
// the result is that it concatinate the integer, because strings only be concatinate
int Sum(int a, int b) {
	return (a) + (b);
}

double Sum(double a, double b) {
	return a + b;
}

int Sum(string a, string b) {
	return atoi(a.c_str()) + atoi(b.c_str());
}

int main() {
	cout << "Sum of int is: " << Sum( 4, 5 ) << endl;
	cout << "Sum of Double is: " << Sum( 4.0, 5.0 ) << endl;
	cout << "Sum of String is: " << Sum( "4", "5" ) << endl;
}


