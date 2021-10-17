#include <iostream>
#include <string>
#include "MLInheritance.h"

using namespace std;

int main() {
	cout << "\n&&&&__ Calling Functions with Base Class _____&&&&&&&&&\n" << endl;
	BaseClass BaseObj;
	BaseObj.BaseFunc();

	cout << "\n&&&&___ Calling Functions with Child class _____ &&&&&&&&&\n" << endl;
	ChildClass ChildObj;
	ChildObj.BaseFunc();
	ChildObj.ChildFunc();

	cout << "\n&&&&_____ Calling Functions with Grand Child Class _____&&&&&&&&\n" << endl;
	GrandChild GCObj;
	GCObj.BaseFunc();
	GCObj.ChildFunc();
	GCObj.GrandChildFunc();

}
