#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int main() {

	uint64_t GalaxyVal = 0xa1b2c3d4;
	uint32_t ExchangeVal = (uint32_t) GalaxyVal;
	unordered_map<uint64_t, uint32_t>exchange;
	unordered_map<uint32_t, uint64_t>galaxy;

	
	cout << "\nGiving value to Exchange,\t GalaxyValue: " << GalaxyVal << ", ExchangeValue: " << ExchangeVal << endl << endl;
	auto ret = exchange.insert(make_pair(GalaxyVal, ExchangeVal));
	if (ret.second) {
		cout << "Value Inserted......" << endl;
	} else {
		cout << "Value Failed....." << endl;
	}

	auto ret1 = exchange.insert(make_pair(GalaxyVal, ExchangeVal));
	if (ret1.second) {
		cout << "Value Inserted........" << endl;
	} else {
		cout << "Value Failed......" << endl;
	}

	// insert the values to Galaxy 
	

	// find, [], for-if
	cout << " \n Printing Values of exchange......\n" << endl;

	cout << exchange[GalaxyVal] << endl;

	cout << "\nand passing exchange value\n" << exchange[ExchangeVal] << endl;
}


