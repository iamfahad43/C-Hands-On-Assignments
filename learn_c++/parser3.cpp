#include<iostream>
#include<string>
using namespace std;

int main() {
	string json;
	string token;

	cout << "Enter a string to be search for: " << endl;
	getline (cin, json);

	cout << "Enter any word, i will tell you the next one." << endl;
	cin >> token;

	cout << "Searching " << token << " in str: " << json << endl;

	//first find the index of token
	size_t pos1 = json.find(token);
	if (pos1 == string::npos) {
	       return 0;
	}	       
	size_t pos2 = json.find(" ", pos1+1);

	if (pos2 == string::npos){
		return 0;
	}
 	size_t pos3 = json.find(" ", pos2+1);

	if (pos3 == string::npos){
		return 0;
	}

	cout << "\nThe next word is: " << json.substr(pos2, (pos3-pos2)) << endl;
}


		
