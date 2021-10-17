#include <iostream>
#include <string>

using namespace std;

enum Test { Key = 1, Value2 = 2, Value3 = 3, Value4 = 4 };

int main(){
	cout << "\nI am enum Test.\n" << endl;

	Test tst;

	tst = Value3;

	cout <<"This is value aginst key3: \n"<<  tst << endl;

}
