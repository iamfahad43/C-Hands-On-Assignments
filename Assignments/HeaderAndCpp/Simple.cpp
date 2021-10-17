#include <iostream>
#include "Simple.h"

using namespace std;

ShowSomething::ShowSomething() {
	cout << "\nI am Constructor...\n" << endl;
}

void ShowSomething::AuthorName() {
	cout << "\nHi there, I am Fahad\n" << endl;
}
void ShowSomething::Language() {
	cout << "\nWriting this code in c++\n" << endl;
}
ShowSomething::~ShowSomething() {
	cout << "\n>> I am Distructor....\n" << endl;
}
