#include <iostream>
#include <string>
#include <vector>

using namespace std;

// @Get Price
template<typename F>
F RetPrice(F aMsg) {
	F price = "price";
	size_t pos1 = aMsg.find(price);
	if (pos1==string::npos)
		return 0;
	size_t pos2 = aMsg.find(':', pos1+1);
	if (pos2==string::npos)
		return 0;

	size_t pos3 = aMsg.find(',', pos2+1);
	if (pos3==string::npos)
		return 0;

	//cout << "\nPrice: " << aMsg.substr(pos2+1, (pos3-pos2)) << endl;
	return aMsg.substr(pos2+1, ((pos3-pos2)-1));
}

// @Get Amount
template<typename T>
T RetAmount(T aMsg) {
	T amount = "amount";
	size_t pos1 = aMsg.find(amount);
	if (pos1==string::npos)
		return 0;
	size_t pos2 = aMsg.find(':', pos1+1);
	if (pos2==string::npos)
		return 0;

	//size_t pos3 = aMsg.find(',' || ']' || '}', pos2+1);    // this will terminate the program because if found the all three chracters at same level
	size_t pos3 = aMsg.find('}', pos2+1);
	if (pos3==string::npos)
		return 0;

	return aMsg.substr(pos2+1, ((pos3-pos2)-1));
}

// @Get Instrument Name
template<typename F>
F RetName(F aMsg) {
	F name = "instrument_name";
	size_t pos1 = aMsg.find(name);
	if (pos1==string::npos)
		return 0;
	size_t pos2 = aMsg.find(':', pos1+1);
	if (pos2==string::npos)
		return 0;

	size_t pos3 = aMsg.find(',', pos2+1);
	if (pos3==string::npos)
		return 0;

	return aMsg.substr(pos2+1, ((pos3-pos2)-1));
}
// @Get ASKS
template<typename F>
F RetAsks(F aMsg) {
	F name = "asks";
	size_t pos1 = aMsg.find(name);
	if (pos1==string::npos)
		return 0;
	size_t pos2 = aMsg.find('[', pos1+1);
	if (pos2==string::npos)
		return 0;

	size_t pos3 = aMsg.find(']', pos2+1);
	if (pos3==string::npos)
		return 0;

	return aMsg.substr(pos2+1, ((pos3-pos2)));
}
// @Get BIDS
template<typename F>
F RetBids(F aMsg) {
	F name = "bids";
	size_t pos1 = aMsg.find(name);
	if (pos1==string::npos)
		return 0;
	size_t pos2 = aMsg.find('[', pos1+1);
	if (pos2==string::npos)
		return 0;

	size_t pos3 = aMsg.find(']', pos2+1);
	if (pos3==string::npos)
		return 0;

	return aMsg.substr(pos2+1, ((pos3-pos2)));

}

int main() {
	vector<string> avec;
	std::string msg = R"(
{"jsonrpc":"2.0","method":"subscription","params":{"channel":"book.BTC-PERPETUAL.raw","data":{"type":"change","timestamp":1635255541010,"prev_change_id":6786952192,"instrument_name":"BTC-PERPETUAL","change_id":6786952193,"bids":[["new",62346.0,57520.0]],"asks":[["delete",62345.5,0.0]]}}}
)";
	std::string msg1 = R"(
{"jsonrpc":"2.0","method":"subscription","params":{"channel":"book.BTC-PERPETUAL.raw","data":{"type":"change","timestamp":1635262162243,"prev_change_id":6787514783,"instrument_name":"BTC-PERPETUAL","change_id":6787514789,"bids":[],"asks":[["new",62271.0,50.0]]}}}
)";
	avec.push_back(msg);
	avec.push_back(msg1);

	for (auto itr = avec.begin(); itr != avec.end(); ++itr){
		cout << "\nMessage we are going to parse is: \n" << * itr << endl;
		//cout << "\nPrice of trade is: " << RetPrice(* itr ) << "\n" << endl;
		//cout << "Amount of trade is: " << RetAmount(* itr ) << "\n" << endl;
		cout << "Instrument Name is: " << RetName(* itr ) << "\n" << endl;
		cout << "Asks are: " << RetAsks(* itr ) << "\n" << endl;
		cout << "Bids are: " << RetBids(* itr ) << "\n" << endl;
	}
}
