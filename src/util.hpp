//
// Author: Carlos Souza <souza.ca80@gmail.com>, <souza@gatech.edu>
// Date: 27/Feb/2023
//
// This file specifies utility functions
//
#ifndef UTIL_HPP
#define UTIL_HPP

#include <string>
#include <nlohmann/json.hpp>

namespace CarlosSouza {

	nlohmann::json getYahooFinanceOptionsData(std::string symbol);

}

#endif

