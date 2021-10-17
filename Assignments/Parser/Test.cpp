#include <iostream>
#include <ctype.h>
#include <string>

using namespace std;

void ParseTree(const std::string &aMsg, int &idx, int level=0) {
	size_t len = aMsg.length();
	int begin = idx;
	char ch;
	std::string pedding;

	for (int i=1; i<=level; i++) pedding += "\t";

	do {
		ch = aMsg[idx];
		if (::isspace(ch)) { continue; }
		else if (ch == '[' || ch == '{') {
			std::cout << pedding << ch << std::endl;
			ParseTree(aMsg, ++idx, level+1);
			std::cout << pedding << aMsg[idx] << std::endl;
			begin = idx+1;
		} else if(ch == ',') {
			std::cout << pedding << ch << std::endl;
			begin = idx+1;
		} else if(ch == ':') {
			std::cout << pedding << ch << std::endl;
			begin = idx+1;
		} else if(ch == ']' || ch == '}') {
			std::cout << pedding << ch << std::endl;
			begin = idx+1;
			break;
		}
	} while ( ++idx < len);
}


int main() {
	//string str = "[{\"12\":\"34\", \"key1\":\"key1\"},{\"key2\":\"val2\", \"key3\":\"val3\"}]";
        std::string str = "[12345, [[89441,1631148456164,0.018,7254.7], [9441,1631148456164,0.019,7254.8]]";
        int idx = 0;
        std::cout << "The json array we are parsing is: \n" << str << std::endl;
        ParseTree(str, idx);
        std::cout << std::endl;
}

