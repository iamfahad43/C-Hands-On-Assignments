#include <iostream>
#include <string>

using namespace std;

class ParentClass {
	public:

		ParentClass() {
			cout << " I am contructor of parent class " << endl;
		}
		void parentclass() {
			cout << " I am function of parent class \n" << endl;
		}

};

class ChildClass : public ParentClass {
	public:
		ChildClass() {
			cout << "\nI am contructor of child class\n" << endl;
		}

		void childclass() {
			cout << "\nI am function of child class\n" << endl;
		}
};

class GrandChild : public ChildClass {
	public:
		GrandChild() {
			cout << "\nI am constructor of grand child class\n" << endl;
		}

		void grandchild() {
			cout << "\nI am function of grand child class\n" << endl;
		}
};

int main() {
	cout << "\nAccessing with grandchild class...........................\n" << endl;
	GrandChild obj;

	obj.parentclass();
	obj.childclass();
	obj.grandchild();

	cout << "\nNow trying to access with child class...............................\n" << endl;

	ChildClass obj1;
	obj1.parentclass();
	obj1.childclass();
	//obj1.grandchild();

	cout << "\n>>>>>Accesing with parest class....................................\n" << endl;
        
	ParentClass obj2;
	obj2.parentclass();
	//obj2.childclass();
	//obj2.grandchild();


	
}

