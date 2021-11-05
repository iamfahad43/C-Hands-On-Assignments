
#include <iostream>
#include <string>

using namespace std;

// function that return the instrument name
std::string Instrument(std::string aMsg) {
	std::string null = "NULL";
	std::string token = "instrument_name";
	size_t pos1 = aMsg.find(token);
	if (pos1==string::npos)
		return null;
	size_t pos2 = aMsg.find(':', pos1+1);
	if (pos2==string::npos)
		return null;
	size_t pos3 = aMsg.find(',', pos2+1);
	if (pos3==string::npos)
		return null;

	std::string MakePrint = aMsg.substr(pos2+1, ((pos3-pos2)-1));
	return MakePrint;
}

// function that return the Bids
std::string Bids(std::string aMsg) {
	std::string null = "NULL";
	std::string token = "bids";
	size_t pos1 = aMsg.find(token);
	if (pos1==string::npos)
		return null;
	size_t pos2 = aMsg.find(':', pos1+1);
	if (pos2==string::npos)
		return null;
	size_t pos3 = aMsg.find(']', pos2+1);
	if (pos3==string::npos)
		return null;
	size_t pos4 = aMsg.find(',', pos3+1);
	if (pos4==string::npos)
		return null;

	std::string MakePrint = aMsg.substr(pos2+1, ((pos4-pos2)-1));
	return MakePrint;
}
// function that return the Asks
std::string Asks(std::string aMsg) {
	std::string null = "NULL";
	std::string token = "asks";
	size_t pos1 = aMsg.find(token);
	if (pos1==string::npos)
		return null;
	size_t pos2 = aMsg.find(':', pos1+1);
	if (pos2==string::npos)
		return null;
	size_t pos3 = aMsg.find(']', pos2+1);
	if (pos3==string::npos)
		return null;
	size_t pos4 = aMsg.find('}', pos3+1);
	if (pos4==string::npos)
		return null;

	std::string MakePrint = aMsg.substr(pos2+1, ((pos4-pos2)-1));
	return MakePrint;
}

int main() {
	std::string str = R"(
{"jsonrpc":"2.0","method":"subscription","params":{"channel":"book.BTC-PERPETUAL.raw","data":{"type":"change","timestamp":1635513739435,"prev_change_id":6807100702,"instrument_name":"BTC-PERPETUAL","change_id":6807100703,"bids":[["new",60772.0,50.0]],"asks":[]}}}
)";

	std::cout << "Asks: " << Asks(str) << std::endl;
	std::cout << "Bids: " << Bids(str) << std::endl;
	std::cout << "Instrument: " << Instrument(str) << std::endl;
	
}


