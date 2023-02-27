#include <gtest/gtest.h>
#include <fstream>
#include "util.hpp"

using namespace std;
using namespace CarlosSouza;
using json = nlohmann::json;

TEST(UnitUtil, GetYahooFinanceOptionsData) {
	json res = getYahooFinanceOptionsData("^SPX");

	// Saves to file for debugging purposes
	string fname = "SPX.json";
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