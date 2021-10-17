#include<iostream>
#include<string>
using namespace std;

int main() {
	string json = "{\"key1\":\"value1\", \"key2\":\"value2\", \"key3\":\"value3\", \"key4\":\"value4\"}";
	string token;
	cout << "Enter a key I will show its value: \n";
	cin >> token;

	cout << "Our json file is: " << json << endl;

	size_t pos1 = json.find(token);
	if (pos1 == string::npos){
		return 0;
	}
	cout << "\nPosition 1 is: " << pos1 << endl;

	size_t pos2 = json.find(":", pos1+1);
	if (pos2 == string::npos){
		return 0;
	}
	cout<< "\nPosition 2 is: " << pos2 << endl;

	size_t pos3 = json.find("\"", pos2+1);
	if (pos3 == string::npos) {
		return 0;
	}

	cout << "\nPosition 3 is: " << pos3 << endl;

	size_t pos4 = json.find("\"", pos3+1);
	if (pos4 == string::npos) {
		return 0;
	}
	cout << "\nPosition 4 is: " << pos4 << endl;

	cout << "\nYou Entered: " << token << "\nand the value aginst this key is: \n" << json.substr(pos3, (pos4 - pos3)) << endl;

}
