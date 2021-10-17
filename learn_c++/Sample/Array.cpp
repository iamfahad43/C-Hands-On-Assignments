#include <iostream>
#include <string>

using namespace std;

int main() {
	string ar1[10] = {"Hi", "there, ", "I", "am", "working", "on", "array", "and", "loops", "checking"};

	for (int i = 0; i < 10; i++) {
		cout << endl << ar1[i] << endl;
	}
}
