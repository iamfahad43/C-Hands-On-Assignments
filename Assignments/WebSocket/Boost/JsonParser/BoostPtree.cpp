#ifdef _MSC_VER
#include <boost/config/compiler/visualc.hpp>
#endif
#include <boost/property_tree/json_parser.hpp>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/exceptions.hpp>
#include <boost/exception/diagnostic_information.hpp>
#include <boost/foreach.hpp>
#include <cassert>
#include <exception>
#include <map>
#include <iostream>
#include <sstream>
#include <string>

typedef boost::property_tree::iptree    ptree_t;
typedef ptree_t::value_type             ptree_value_t;
typedef boost::optional<ptree_t &>      optional_ptree_t;

int main()
{
    try
    {
        std::stringstream ss;
        //ss << "{ \"root\": { \"values\": [1, 2 ] } }";
	ss << R"( {"jsonrpc":"2.0","method":"subscription","params":{"channel":"book.BTC-PERPETUAL.raw","data":{"type":"change","timestamp":1635513739435,"prev_change_id":6807100702,"instrument_name":"BTC-PERPETUAL","change_id":6807100703,"bids":[["new",60772.0,50.0], "demo"],"asks":[]}}}
        )";

        boost::property_tree::ptree pt;
        boost::property_tree::read_json(ss, pt);
	
	std::cout << "\njsonrpc: " << pt.get<std::string>("jsonrpc") << std::endl;
	std::cout << "\nmethod: " << pt.get<std::string>("method") << std::endl;
	std::cout << "\nparams: " << pt.get_child<std::string>("params") << std::endl;
	std::cout << "\nparams.channel: " << pt.get<std::string>("params.channel") << std::endl;
	std::cout << "\nparams.data: " << pt.get<std::string>("params.data") << std::endl;
	std::cout << "\nparams.data.timestamp: " << pt.get<std::string>("params.data.timestamp") << std::endl;
	std::cout << "\nparams.data.instrument_name: " << pt.get<std::string>("params.data.instrument_name") << std::endl;

	for (auto& array_element : pt.get_child("params.data.bids")) {
        	for (auto& property : array_element.second) {
            		std::cout << property.first << "=== " << property.second.get_value<std::string>() << "\n";
        	}
    	}


/******	
	boost::property_tree::basic_ptree<std::string,std::string>::const_iterator iter = pt.begin(),iterEnd = pt.end();
	for(;iter != iterEnd;++iter)
	{
    	//->first;  // Key.  Array elements have no names 
    	//->second; // The object at each step

    	std::cout << "=> " << iter->second.get_value<std::string>() << std::endl;
	}

*****/

/***	
	optional_ptree_t ptBlah = pt.get_child_optional("params");

    	if (ptBlah)
    	{
        	BOOST_FOREACH (property_tree_t::value_type & field, pt.get_child("params"))
        	{

        	}
    	}

****/

	//std::cout << "\nparams.data.asks: " << pt.get<std::string>("params.data.asks") << std::endl;
	//std::cout << "instrument_name: " << pt.get<std::string>("params") << std::endl;
/*********
	for (auto& itr : pt.get_child("params.data")) {
	std::cout << std::endl;
        std::cout << "for params.data: " << itr.second.data() << "\n";
   	}	

        //BOOST_FOREACH(boost::property_tree::ptree::value_type &v, pt.get_child("root.values"))
        BOOST_FOREACH(boost::property_tree::ptree::value_type &v, pt.get_child("params.data"))
        {
            //assert(v.first.empty()); // array elements have no names
            std::cout <<"boost::ptree" << v.first << "= " << v.second.data() << std::endl;
	    //std::cout << "Bids: " << pt.get<std::string>("instrument_name") << std::endl;
        }
     
    	return EXIT_SUCCESS;
****/
    }
    catch (std::exception const& e)
    {
        std::cerr << e.what() << std::endl;
    }
    return EXIT_FAILURE;
}


