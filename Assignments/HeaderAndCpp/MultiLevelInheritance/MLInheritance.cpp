#include <iostream>
#include <string>
#include "MLInheritance.h"

using namespace std;

BaseClass::BaseClass() {
	cout << "\nI am constructor of Base class\n" << endl;
}

void BaseClass::BaseFunc() {
	cout << "\nI am \"Function\" of Base Class \n" << endl;
}

BaseClass::~BaseClass() {
	cout << "\nI am Distructor on Base Class \n" << endl;
}

// Defination of Child Class

ChildClass::ChildClass() {
	cout << "\n>>I am constructor of child class \n" << endl;
}

void ChildClass::ChildFunc() {
	cout << "\n>> I am \"Function\" of child class \n" << endl;
}

ChildClass::~ChildClass() {
	cout << "\n>>I am distructor of child class \n" << endl;
}

// Defination of GrandChild Class

GrandChild::GrandChild() {
	cout << "\n......I am constructor of grand child class\n" << endl;
}

void GrandChild::GrandChildFunc() {
	cout << "\n......I am \"Function\" of grand child class\n" << endl;
}

GrandChild::~GrandChild() {
	cout << "\n......I am distructor of grand child class\n" << endl;
}





