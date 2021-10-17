#include <iostream>
#include <string>

using namespace std;

// class College with static member ClgNumber

class College {
	static int ClgNumber;
	int ClgNumberCpy;
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
	int CompanyNumberCpy;
	int Salary;
	string Role;
	string Name;
	string CmpName;

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
	ClgNumber++;
	ClgNumberCpy = ClgNumber;
}

// defination of GetDetails() of College Class

void College::GetDetails() {
	cout << "\n***********************************Printing Details****************************************\n" << endl;
	cout << "\nThe Length of : " << Department << " of " << CollegeName << " is: " << Students << endl;
	cout << "\nThe College Number is: \n" << ClgNumberCpy << endl;
	cout << "\nTotal College Number is: \n" << ClgNumber << endl;
}

// defination of SetDetails() of Employee class
void Employee::SetDetails() {
	cout << "\nEnter your Name: \n" << endl;
	cin >> Name;
	cout << "\nEnter your Company Name: \n" << endl;
	cin >> CmpName;
	cout << "\nEnter your Role: \n" << endl;
	cin >> Role;
	cout << "\nEnter your Salary: \n" << endl;
	cin >> Salary;
	//increment the static value
	CompanyNumber++;
	CompanyNumberCpy = CompanyNumber;

}

void Employee::History () {
	cout << "\n----------------------------------Printing Details-----------------------------------------\n" << endl;
	cout << "\nMr. " << Name << " is " << Role << " at " << CmpName << " and getting Salary " << Salary << endl;
	cout << "\nThe Number of company in static variable is: " << CompanyNumberCpy << endl;
	cout << "\nThe Total Number of company in static variable is: " << CompanyNumber << endl;
}

// Now time to declare a static data member of both classes 

int College::ClgNumber;
int Employee::CompanyNumber;

int main() {

	int clg;
	int emp;
	cout << "\nHow many istances of College you want to log? " << endl;
	cin >> clg;
	cout << "\nHow many istances of Employee you want to log? " << endl;
	cin >> emp;

	College Clg[sizeof(clg)];
	Employee Emp[sizeof(emp)];

	for (int i=1; i<=clg; i++) {
		cout << "\nEnter the details for College instance no. " << i << endl;
		Clg[i].SetDetails();
	}

	Clg[clg].GetDetails();     // show only the last instance details
	//cout << "\nloops for employee class---------------------------------------\n";

	//for (int j=1; j<=emp; emp++) {
	//	cout << "\nEnter the details for Employee instance no. " << j << endl;
	//	mp.SetDetails();
	//}
	//Emp[emp].History();
	
}






