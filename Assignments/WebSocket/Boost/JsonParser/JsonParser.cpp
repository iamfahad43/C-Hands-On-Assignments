#include <boost/json.hpp>
#include <boost/json/src.hpp> // header-only for Compiler Explorer
#include <iostream>
namespace json = boost::json;

int main() {
    auto req = json::parse(R"({
            "jsonrpc": "2.0",
            "method": "subscription",
            "params": {
                "channel": "book.BTC-PERPETUAL.raw",
                "data": {
                    "type": "change",
                    "timestamp": 1635513739435,
                    "prev_change_id": 6807100702,
                    "instrument_name": "BTC-PERPETUAL",
                    "change_id": 6807100703,
                    "bids": [
                        ["new", 60772.0, 50.0], "demo"],
                    "asks": []
                }
            }
        })") .as_object();

    auto& params = req["params"].as_object();
    auto& data   = params["data"].as_object();
    std::cout << "jsonrpc:                     " << req["jsonrpc"].as_string()    << "\n";
    std::cout << "methdo:                      " << req["method"].as_string()     << "\n";
    std::cout << "params.channel:              " << params["channel"].as_string() << "\n";
    std::cout << "params.data:                 " << params["data"]                << "\n";
    std::cout << "params.data.timestamp:       " << data["timestamp"]             << "\n";
    std::cout << "params.data.instrument_name: " << data["instrument_name"]       << "\n";
    for (auto& bid : data["bids"].as_array()) {
    std::cout << "\nbid: " << bid << "\n";
    }
    for (auto& ask : data["asks"].as_array()) {
    std::cout << "\nask: " << ask << "\n";
    }
}
