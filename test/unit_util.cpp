#include <gtest/gtest.h>
#include <fstream>
#include "util.hpp"

using namespace std;
using namespace CarlosSouza;
using json = nlohmann::json;

TEST(UnitUtil, GetYahooFinanceOptionsData) {
	json res = getYahooFinanceOptionsData("^SPX");

	// Saves to file for debugging purposes
	string fname = "SPX_option.json";
	ofstream myfile(fname);
	if (myfile.is_open())
	{
		myfile << setw(4) << res << endl;
	}

	json data = res["optionChain"]["result"][0]["quote"];
	string short_name = data["shortName"];
	// cout << setw(4) << data << endl;
	EXPECT_EQ(short_name, "S&P 500 INDEX");
}

TEST(UnitUtil, GetYahooFinancePriceData) {
	string symbol = "^SPX";  // "^SPX"
	json res = getYahooFinanceDailyPriceData(symbol);
	// json res2 = res["chart"]["result"][0]["timestamp"];
	json res2 = res["chart"]["result"][0]["indicators"]["adjclose"][0]["adjclose"];
	
	// Saves to file for debugging purposes
	string fname = symbol + "_price.json";
	ofstream myfile(fname);
	if (myfile.is_open())
	{
		myfile << setw(4) << res2 << endl;
	}
}