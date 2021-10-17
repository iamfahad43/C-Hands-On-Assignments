// practice sequence container in STL
// Vector is the form of sequence container
// Dynamic Array which can manage its length on memory automatically


#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Function that can take lenth of vector and save them into vector
void SetDetails(vector<int>vec, int len) {
	for (int i=1; i<=len; i++) {
		int val;
		cout << "\nEnter the " << i << " number: " << endl;
		cin >> val;
		vec.push_back(val);
	}
}

void GetDetails(vector<int>vec){
	cout << "\nThe Vector is: " << endl;
	for (auto it=vec.begin(); it!=vec.end(); ++it)
		cout << *it << endl;
}

int min() {
	vector<int>vec1;
	int len;
	cout << "Enter the lngth of vector : " << endl;
	cin >> len;

	SetDetails(vec1, len);
	GetDetails(vec1);

	cout << "The length of vector is: " << vec1.size() << endl;

	cout << "After adding some manual values to this vector, the vector is: " << endl;
        GetDetails(vec1);
	cout << "The length of vector after adding manual values is: " << vec1.size() << endl;

}
