// here is the standard json file we are going to cover in this file  [{"key":"val", "key1":"key1"},{"key2":"val2", "key3":"val3"}]
// this will work for all the format of keyvalues and arrays

#include <iostream>
#include <string>
#include <ctype.h>



// function that can search index wise

void JsonParser(const std::string &json, int &idx, int level=0){
	size_t len = json.length();
	char ch;
	int begin = idx;
	std::string spcline;

	for (int i=0; i<level; i++) spcline += "\t";

	do {
		ch = json[idx];
		if (::isspace(ch)) { continue; }
		else if (ch == '[' || ch == '{') {
			//std::cout << "\nIn else if (ch==[ || ch=={)" << std::endl;
			std::cout << spcline << ch  << std::endl;
			// start searching for index after found once, using recursion technique
			JsonParser(json, ++idx, level+1);
			//std::cout << "\nIn Recursive Function" << std::endl;
			std::cout << spcline << json[idx] << std::endl;
			// increase the value of index after printing the level nth values
			begin = idx+1;
		// now search for next symbol
		} else if (ch == ',' ) {
			//std::cout << "\nIn else if (ch== , ) " << std::endl;
			std::cout << spcline << json.substr(begin, idx-begin) << std::endl;
			// increase the value of index
			begin = idx+1;
		// serching for ] or } to close the searching loop
		} else if (ch == '}' || ch == ']') {
			//std::cout << "\nIn else if (ch== }) " << std::endl;
			std::cout << spcline << json.substr(begin, idx-begin) << std::endl;
			begin = idx+1;
			break;
		}  
	// continue the search until the index read all the charcter from string
        }  while ( ++idx < len ); 
}

int main() {
	std::string str = "{\"session\": \"NORMAL\",\"duration\": \"GOOD_TILL_CANCEL\",\"orderType\": \"LIMIT\",\"price\": \"1310.00\",\"orderLegCollection\":[{\"instruction\": \"BUY\",\"instrument\": {\"assetType\": \"EQUITY\",\"symbol\": \"GOOG\"},\"quantity\": 1}],\"orderStrategyType\": \"TRIGGER\", \"childOrderStrategies\": [{\"orderStrategyType\": \"OCO\",\"childOrderStrategies\": [{\"session\": \"NORMAL\",\"duration\": \"GOOD_TILL_CANCEL\",\"orderType\": \"LIMIT\",\"price\": \"1400.00\",\"orderLegCollection\": [{\"instruction\": \"SELL\",\"instrument\": {\"assetType\": \"EQUITY\",\"symbol\": \"GOOG\"}, \"quantity\": 1}]},{\"session\": \"NORMAL\",\"duration\": \"GOOD_TILL_CANCEL\",\"orderType\": \"STOP_LIMIT\",\"stopPrice\": \"1250.00\",\"orderLegCollection\": [{\"instruction\": \"SELL\",\"instrument\": {\"assetType\": \"EQUITY\",\"symbol\": \"GOOG\"},\"quantity\": 1}]}]}]}";

	//std::string str = "[{\"12\":\"34\", \"key1\":\"key1\"},{\"key2\":\"val2\", \"key3\":\"val3\"}]";
	//std::string str = "[12345, [[89441,1631148456164,0.018,7254.7], [9441,1631148456164,0.019,7254.8]]";
        int idx = 0;
      	std::cout << "\nThe json array we are parsing is: \n\n" << str <<"\n" << std::endl;
	JsonParser(str, idx);
	std::cout << std::endl;
}



