#include <iostream>
#include <functional>

using namespace std;

double Multiply (double x, double y) {return x*y;}

int main() {
	auto Multiply2 = std::bind (Multiply, 4, 5);

	auto Multiply3 = std::bind (Multiply, 5, 8);

	auto Multiply4 = std::bind (Multiply, 2, 9);

	cout << "\nUsing Function: Multiply2 with 4 and 5 as a parameters: \n " << " The output is:  "  << Multiply2() << endl;
	cout << "\nUsing Function: Multiply3 with 5 and 8 as a parameters: \n " << " The output is:  "  << Multiply3() << endl;
	cout << "\nUsing Function: Multiply4 with 2 and 9 as a parameters: \n " << " The output is:  "  << Multiply4() << endl;
}
