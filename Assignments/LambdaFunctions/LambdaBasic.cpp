#include <iostream>
#include <functional>
#include <string>

int main() {
	using namespace std;

	auto f1 = [](int x, int y) { return x+y; };

	int i, j;
	cout << "\nEnter first number: \n";
	cin >> i;
	cout << "\nEnter secord number: \n";
	cin >> j;

        cout << f1(i, j) << endl;
}

