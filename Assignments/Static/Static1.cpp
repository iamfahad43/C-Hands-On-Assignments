#include <iostream>
#include <string>

using namespace std;

// class College with static member CollegeNumber

class College {
	static int CollegeNumber;
	char Department[15];
	int Students;
	string CollegeName;

	public:
	    // I will define the SetDetails function outside the class
	    void SetDetails();
	    // Define the GetDetails Function outside the class
	    void GetDetails();
};

// Class Employee with static member Company

class Employee {
	static int CompanyNumber;
	int Salary;
	string Role;
	string Name;
	string CompanyName;

	public:
	    //Define this function outside the class
	    void SetDetails();
	    //Define this function outside the class
	    void History();
};

// define the SetDetails() of College Class
void College::SetDetails() {
	cout << "\nEnter your College Name Please: \n" << endl;
	cin >> CollegeName;
	cout << "\nEnter your Department: \n" << endl;
	cin >> Department;
	cout << "\nEnter the lenth of Students: \n" << endl;
	cin >> Students;
	//increase the static member
	CollegeNumber++;
}

// defination of GetDetails() of College Class

void College::GetDetails() {
	cout << "\n***********************************Printing Details****************************************\n" << endl;
	cout << "\nThe Length of : " << Department << " of " << CollegeName << " is: " << Students << endl;
	cout << "\nThe College Number is: \n" << CollegeNumber << endl;
}

// defination of SetDetails() of Employee class
void Employee::SetDetails() {
	cout << "\nEnter your Name: \n" << endl;
	cin >> Name;
	cout << "\nEnter your Company Name: \n" << endl;
	cin >> CompanyName;
	cout << "\nEnter your Role: \n" << endl;
	cin >> Role;
	cout << "\nEnter your Salary: \n" << endl;
	cin >> Salary;
	//increment the static value
	CompanyNumber++;

}

void Employee::History () {
	cout << "\n----------------------------------Printing Details-----------------------------------------\n" << endl;
	cout << "\nMr. " << Name << " is " << Role << " at " << CompanyName << " and getting Salary " << Salary << endl;
	cout << "\nThe Number of company in static variable is: " << CompanyNumber << endl;
}

// Now time to declare a static data member of both classes 

string College::CollegeNumber;
string Employee::CompanyNumber;

int main() {
	College Clg1;
	College Clg2;

	Employee Emp1;
	Employee Emp2;


	Clg1.SetDetails();
	Clg2.SetDetails();

	Emp1.SetDetails();
	Emp2.SetDetails();


	// printing Details
	
	Clg1.GetDetails();
	Emp1.History();

	Clg2.GetDetails();
	Emp2.History();

}














