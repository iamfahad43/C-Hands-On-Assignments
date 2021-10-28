#include <boost/beast/core.hpp>
#include <boost/beast/websocket.hpp>
#include <boost/asio/connect.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <boost/beast/ssl.hpp>
#include <boost/beast/websocket/ssl.hpp>
#include <cstdlib>
#include <iostream>
#include <typeinfo>
#include <string>
#include <vector>
#include <openssl/sha.h>
#include <openssl/hmac.h>
#include <openssl/evp.h>
#include <openssl/buffer.h>
#include <openssl/bio.h>

namespace ssl = boost::asio::ssl;       // from <boost/asio/ssl.hpp>

namespace beast = boost::beast;         // from <boost/beast.hpp>
namespace http = beast::http;           // from <boost/beast/http.hpp>
namespace websocket = beast::websocket; // from <boost/beast/websocket.hpp>
namespace net = boost::asio;            // from <boost/asio.hpp>
using tcp = boost::asio::ip::tcp;       // from <boost/asio/ip/tcp.hpp>

// @ Return ASKS
template<typename F>
F RetAsks(F aMsg) {
	std::string null = "NULL";
        F name = "asks";
        size_t pos1 = aMsg.find(name);
        if (pos1==std::string::npos)
                return null;
        size_t pos2 = aMsg.find(':', pos1+1);
        if (pos2==std::string::npos)
                return null;

        size_t pos3 = aMsg.find('}', pos2+1);
        if (pos3==std::string::npos)
                return null;

        return aMsg.substr(pos2+1, ((pos3-pos2)-1));
}

// @ Return BIDS
template<typename F>
F RetBids(F aMsg) {
	std::string null = "NULL";
        F name = "bids";
        size_t pos1 = aMsg.find(name);
        if (pos1==std::string::npos)
                return null;
        size_t pos2 = aMsg.find(':', pos1+1);
        if (pos2==std::string::npos)
                return null;

        size_t pos3 = aMsg.find(']', pos2+1);
        if (pos3==std::string::npos)
                return null;

        size_t pos4 = aMsg.find(',', pos3+1);
        if (pos3==std::string::npos)
                return null;

        return aMsg.substr(pos2+1, ((pos4-pos2)-1));
}

// @ Return Instrument Name
std::string RetInstrument(const std::string &aMsg) {
	std::string null = "NULL";
	std::string token = "instrument_name";
        size_t pos1 = aMsg.find(token);
        if (pos1==std::string::npos)
                return null;

        size_t pos2 = aMsg.find(':', pos1+1);
        if (pos2==std::string::npos)
                return null;

        size_t pos3 = aMsg.find(',', pos2+1);
        if (pos3==std::string::npos)
                return null;
        return aMsg.substr(pos2+1, (((pos3-pos2))-1));
}


// Sends a WebSocket message and prints the response
int main(int argc, char** argv)
{
    try
    {
        // Check command line arguments.
/***
        if(argc != 4)
        {
            std::cerr <<
                "Usage: websocket-client-sync <host> <port> <text>\n" <<
                "Example:\n" <<
                "    websocket-client-sync echo.websocket.org 80 \"Hello, world!\"\n";
            return EXIT_FAILURE;
        }
**/
        auto const host = "test.deribit.com";
        auto const port = "443";
        auto const text = R"(
{"method": "public/subscribe", "params": {"channels": ["trades.future.BTC.raw", "book.BTC-PERPETUAL.raw"]},"jsonrpc": "2.0","id": 4}
)";
        // The io_context is required for all I/O
        net::io_context ioc;

        // These objects perform our I/O
//        tcp::resolver resolver{ioc};
//        websocket::stream<tcp::socket> ws{ioc};

        ssl::context ctx{ssl::context::sslv23_client};

        // These objects perform our I/O
        tcp::resolver resolver{ioc};
        websocket::stream<beast::ssl_stream<tcp::socket>> ws{ioc, ctx};

        // Look up the domain name
        auto const results = resolver.resolve(host, port);

        // Make the connection on the IP address we get from a lookup
//        net::connect(ws.next_layer(), results.begin(), results.end());
        net::connect(ws.next_layer().next_layer(), results.begin(), results.end());

	ws.next_layer().handshake(ssl::stream_base::client);

        // Set a decorator to change the User-Agent of the handshake
        ws.set_option(websocket::stream_base::decorator(
            [](websocket::request_type& req)
            {
                req.set(http::field::user_agent,
                    std::string(BOOST_BEAST_VERSION_STRING) +
                        " websocket-client-coro");
            }));

        // Perform the websocket handshake
        ws.handshake(host, "/ws/api/v2");
        // Send the message
        ws.write(net::buffer(std::string(text)));

        while(true) {

                // This buffer will hold the incoming message
                beast::flat_buffer buffer;

                // Read a message into our buffer
                ws.read(buffer);

                // The make_printable() function helps print a ConstBufferSequence
                //std::cout << beast::make_printable(buffer.data()) << std::endl;

		// The buffers_to_string() funcion convert the buffer data into string
                //std::cout << beast::buffers_to_string(buffer.data()) << std::endl;

		std::string str1 = beast::buffers_to_string(buffer.data());
		std::cout << "\n\nInstrument Name: " << RetInstrument(str1) << std::endl;
		std::cout << "Bids: " << RetBids(str1) << std::endl;
		std::cout << "Asks: " << RetAsks(str1) << std::endl;
        }

        // Close the WebSocket connection
        ws.close(websocket::close_code::normal);
        // If we get here then the connection is closed gracefully

    }
    catch(std::exception const& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}
           

