#include <iostream>
#include <string>
#include <functional>

int main() {
	using namespace std;

	function<int(int, int)> f1 = [](int x, int y) { return x*y; };

	int i, j;
	cout <<"\nEnter first number: \n" << endl;
	cin >> i;

	cout << "\nEnter second number: \n" << endl;
	cin >> j;

	cout << "\nMultiplication of " << i << ", and " << j << " is = " << f1(i, j) << endl;
}
