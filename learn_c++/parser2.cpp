#include<iostream>
#include<string>
using namespace std;
int main() {

	string json = "[\"name\":\"Fahad\", \"class\":\"BS\"]";
	string token = ":";

	int pos=-1;

	do {
		pos = json.find(token, pos+1);
		if (pos!=string::npos)
			cout << "Token found at: " << pos << endl;
}	
	while(pos!=string::npos);


	while ((pos = json.find(token, pos+1))!=string::npos) cout << ">> token found at: " << pos << endl; 
}



