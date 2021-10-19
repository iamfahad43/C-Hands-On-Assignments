#include <iostream>
#include <string>

using namespace std;

int main() {
	string json = "[{\"key1\":\"val1\",\"key2\":\"val2\"},{\"key3\":\"val3\",\"key4\":\"val4\"}]";
        cout << "Json: " <<json << endl;

	size_t pos1 = json.find("[");
	if (pos1 == string::npos) {
		return 0;
	}

	size_t pos2 = json.find("{", pos1+1);
	if (pos2 == string::npos) {
		return 0;
	}

	size_t pos3 = json.find(",", pos2+1);
	if (pos2 == string::npos) {
		return 0;
	}
	
	size_t pos4 = json.find(",", pos3+1);
	if (pos3 == string::npos) {
		return 0;
	}
	
	size_t pos5 = json.find("]", pos3+1);
	if (pos4 == string::npos) {
		return 0;
	}

       	cout << "\n" << "[" << "\n\t" <<  json.substr(pos2+1, (pos3-pos2)) << endl;
	cout << "\t" << json.substr(pos3, (pos4-pos3)) << endl;

	cout << "\t" << "\n" << json.substr(pos4)<< "\n" <<json.substr(pos5) << endl;

}
	
