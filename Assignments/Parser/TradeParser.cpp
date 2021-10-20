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

int main() {
	vector<string> avec;
	string msg1 = R"({"jsonrpc":"2.0","method":"subscription","params":{"channel":"trades.future.BTC.raw","data":[{"trade_seq":56891999,"trade_id":"84563160","timestamp":1634662756067,"tick_direction":1,"price":63181.5,"mark_price":63146.89,"instrument_name":"BTC-PERPETUAL","index_price":63127.5,"direction":"buy","amount":209578.89}]}})";
	string msg2 = R"({"jsonrpc":"2.0","method":"subscription","params":{"channel":"trades.future.BTC.raw","data":[{"trade_seq":56891999,"trade_id":"84563160","timestamp":1634662756067,"tick_direction":1,"price":345091.5,"mark_price":63146.89,"instrument_name":"BTC-NEW-RAW","index_price":63127.5,"direction":"buy","amount":5420985.0}]}})";
	string msg3 = R"({"jsonrpc":"2.0","method":"subscription","params":{"channel":"trades.future.BTC.raw","data":[{"trade_seq":56891999,"trade_id":"84563160","timestamp":1634662756067,"tick_direction":1,"price":89765.23,"mark_price":63146.89,"instrument_name":"DUMY-NAME","index_price":63127.5,"direction":"buy","amount":98700.0}]}})";
	avec.push_back(msg1);
	avec.push_back(msg2);
	avec.push_back(msg3);

	for (auto itr = avec.begin(); itr != avec.end(); ++itr){
		cout << "\nMessage we are going to parse is: \n" << * itr << endl;
		cout << "\nPrice of trade is: " << RetPrice(* itr ) << "\n" << endl;
		cout << "Amount of trade is: " << RetAmount(* itr ) << "\n" << endl;
		cout << "Instrument Name is: " << RetName(* itr ) << "\n" << endl;
	}
}
