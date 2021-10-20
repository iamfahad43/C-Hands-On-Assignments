#include <iostream>
#include <string>
#include <vector>

using namespace std;

template<typename F>
F RetPrice(F & aMsg) {
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

	cout << "\nPrice: " << aMsg.substr(pos2+1, (pos3-pos2)) << endl;
	return 0;
}


int main() {
	vector<string> avec;
	string msg = R"({"jsonrpc":"2.0","method":"subscription","params":{"channel":"trades.future.BTC.raw","data":[{"trade_seq":56891999,"trade_id":"84563160","timestamp":1634662756067,"tick_direction":1,"price":63181.5,"mark_price":63146.89,"instrument_name":"BTC-PERPETUAL","index_price":63127.5,"direction":"buy","amount":2000.0}]}})";
	avec.insert(avec.begin(), msg);
	avec.push_back(msg);
	avec.push_back(msg);
	avec.push_back(msg);

	for (auto itr = avec.begin(); itr != avec.end(); ++itr)
		cout << RetPrice(* itr) << endl;

}
