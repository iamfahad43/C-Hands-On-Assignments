#include<iostream>
#include<string>
using namespace std;

int main() {
	//string parser = "{\\"event\\":\\"subscribe\\", \\"channel\\":\\"book\\":, \\"symbol\\":\\":tBTCUSD\\"}";
	
	string parser = "\n[\"key1\":\"value1\", \"key2\":\"value2\", \"key3\":\"value3\"]\n";
	cout << "The string we use as a parser is: "  << parser << endl;

	string token = "[";

	size_t match = parser.find(token);
	if (match!=string::npos)
		cout << "The first occurance of: " << token << ", is found at: " << match << endl;

	match = parser.find(token,match+1);
	if (match!=string::npos);
	cout << "The second occurance of: " << token << ", is found at: " << match << endl;

	match = parser.find(token, match+1);
	if (match!=string::npos)
		cout << "Third occurance of: " << token << ", is found at: " << match << endl;
}
