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
	nlohmann::json getYahooFinanceDailyPriceData(std::string symbol);

}

#endif

// cmake --no-warn-unused-cli -DCMAKE_EXPORT_COMPILE_COMMANDS:BOOL=TRUE -DCMAKE_C_COMPILER:FILEPATH=/usr/bin/clang -DCMAKE_CXX_COMPILER:FILEPATH=/usr/bin/clang++ -S/Users/carlossouza/code/optionplot -B/Users/carlossouza/code/optionplot/build -G Ninja