#include<iostream>
#include<string>
using namespace std;

int main() {
//	string jsonstr = "{\\"event\\":\\"subscribe\\", \\"channel\\":\\"book\\":, \\"symbol\\":\\":tBTCUSD\\"}";
	
	string jsonstr = "\n[\"key1\":\"value1\", \"key2\":\"value2\", \"key3\":\"value3\"]\n";
	cout << "The string we use as a jsonstr is: "  << jsonstr << endl;

	string token = ":";
	int pos = -1;
	do {
		pos = jsonstr.find(token, pos+1);
		if (pos != string::npos) cout << "Token found at: " << pos << endl;
	} while( pos != string::npos );

			
        pos = -1;
	while((pos = jsonstr.find(token, pos+1)) != string::npos ) {
		cout << ">> Tocken found at: " << pos << endl;
	}
}

