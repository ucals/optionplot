//
// Author: Carlos Souza <souza.ca80@gmail.com>, <souza@gatech.edu>
// Date: 27/Feb/2023
//
// This file implements utility functions
//
#include <iostream>
#include <curl/curl.h>
#include "util.hpp"

using namespace std;
using json = nlohmann::json;

namespace CarlosSouza {

	static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp)
	{
		((std::string*)userp)->append((char*)contents, size * nmemb);
		return size * nmemb;
	}

	string getUrl(const char *x)
	{
		CURL *curl;
		CURLcode res;
		string readBuffer;

		curl = curl_easy_init();
		if(curl) {
			curl_easy_setopt(curl, CURLOPT_URL, x);
			curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
			curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
			res = curl_easy_perform(curl);
			curl_easy_cleanup(curl);
		}
		return readBuffer;
	}

	json getYahooFinanceOptionsData(string symbol) 
	{
		string buffer = getUrl(("https://query2.finance.yahoo.com/v7/finance/options/" + symbol).c_str());
		json j_complete = json::parse(buffer);
		// json result = j_complete["optionChain"]["result"][0];
		// json expirationDates = result["expirationDates"];
		// json strikes = result["strikes"];
		// json calls = result["options"][0]["calls"];
		// json puts = result["options"][0]["puts"];
		return j_complete;
	}

	json getYahooFinanceDailyPriceData(string symbol)
	{
		// Fix a bug in Yahoo: ^SPX has no history, but ^GSPC has
		if (symbol == "^SPX") symbol = "^GSPC";

		string url = "https://query2.finance.yahoo.com/v8/finance/chart/" + symbol;
		url += "?interval=1d&range=10y";
		string buffer = getUrl((url).c_str());
		json j_complete = json::parse(buffer);

		return j_complete;
	}

}

/*
https://query1.finance.yahoo.com/v7/finance/download/"
            + symbol
            + "?period1=" + ss1.str()
            + "&period2=" + ss2.str()


https://query1.finance.yahoo.com/v7/finance/download/TSLA?period1=1425070234&period2=1677531100&interval=1d



https://query2.finance.yahoo.com/v8/finance/chart/TSLA
*/