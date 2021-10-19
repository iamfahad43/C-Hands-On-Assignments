#include <iostream>
#include <string>

using namespace std;
/*
template<typename T>
int ShowValue(T str, T token) {
	
	size_t pos1 = str.find(token);
	if (pos1==string::npos){
		return false;
	}

	cout << "Pos 1 is: " << pos1 << endl;

	size_t pos2 = str.find(":", pos1+1);
	if (pos2==string::npos) {
		return false;
	}

	size_t pos3 = str.find(",", pos2+1);
	if (pos3==string::npos){
		return false;
	}

	cout << "\nValue against " << token << " is: " << str.substr(pos2, (pos3-pos2)) << endl;
}
*/

int main() {
	string str = "{\"key1\":\"value1\",[\"key2\":\"value2\",\"key3\":\"value3\"],\"key4\":\"value4\"}";
        string token;
	//string str = "{ \"event\": \"subscribe\", \"channel\": \"book\", \"symbol\": \"tBTCUSD\", \"int\": \"4555\" }";
	cout << "\nHere is our json string\n" << str << endl;

	cout << "\nEnter key to print value: " << endl;
	cin >> token;
	
	size_t pos1 = str.find(token);
	if (pos1==string::npos){
		return false;
	}

	size_t pos2 = str.find(":", pos1+1);
	if (pos2==string::npos) {
		return false;
	}

	size_t pos3 = str.find("\"", pos2+1);
	if (pos3==string::npos){
		return false;
	}
	size_t pos4 = str.find("\"", pos3+1);
	if (pos3==string::npos){
		return false;
	}

	//cout << "\nValue against " << token << " is: " << str.substr(pos3+1, (pos4-pos3)) << endl;
	cout << "\nValue against " << token << " is: " << str.substr(pos3+1, ((pos4-1)-pos3)) << endl;

}
