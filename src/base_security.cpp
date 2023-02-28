//
// Author: Carlos Souza <souza.ca80@gmail.com>, <souza@gatech.edu>
// Date: 27/Feb/2023
//
// This file implements the BaseSecurity class
//
#include <iostream>
#include <nlohmann/json.hpp>
#include <matplot/matplot.h>
#include "base_security.hpp"
#include "util.hpp"

using namespace std;
using json = nlohmann::json;
using namespace matplot;

namespace CarlosSouza
{
	// Default constructor
	BaseSecurity::BaseSecurity(): m_symbol("") {}

	// Constructor with symbol: loads the data from Yahoo Finance
	BaseSecurity::BaseSecurity(string t_symbol)
	{
		m_symbol = t_symbol;
		// load the data
		json res = getYahooFinanceOptionsData(t_symbol);
		json data = res["optionChain"]["result"][0]["quote"];
		m_last_price = data["regularMarketPrice"];
		m_bid = data["bid"];
		m_ask = data["ask"];
		m_last_trade = data["regularMarketTime"];
	}

	// Copy constructor
	BaseSecurity::BaseSecurity(const BaseSecurity& ref)
	{
		m_symbol = ref.m_symbol;
		m_last_price = ref.m_last_price;
		m_bid = ref.m_bid;
		m_ask = ref.m_ask;
		m_last_trade = ref.m_last_trade;
		m_price_history = ref.m_price_history;
		m_return_distribution = ref.m_return_distribution;	
	}

	// Destructor
	BaseSecurity::~BaseSecurity() {}

	// Retrieves the price history from Yahoo Finance
	map<time_t, double> BaseSecurity::priceHistory()
	{
		map<time_t, double> result;

		// Gets the data and parses it
		json data = getYahooFinanceDailyPriceData(m_symbol);
		json dates = data["chart"]["result"][0]["timestamp"];
		json prices = data["chart"]["result"][0]["indicators"]["adjclose"][0]["adjclose"];

		// Puts in a map with dates and prices
		json::iterator it_dates = dates.begin();
		json::iterator it_prices = prices.begin();
		for (; it_prices != prices.end(); ++it_dates, ++it_prices) 
		{
			result.insert(pair<time_t, double>(*it_dates, *it_prices));
		}

		return result;
	}

	// Plots price history on screen
	void BaseSecurity::plotPriceHistory()
	{
		map<time_t, double> data = priceHistory();

		vector<time_t> x;
		vector<int> z;
		vector<double> y;
		int i = 0;
		map<time_t, double>::iterator it;
		for (it = data.begin(); it != data.end(); it++)
		{
			z.push_back(i);
			x.push_back(it->first);
			y.push_back(it->second);
			i++;
		}
		plot(z, y);
		show();
	}
}