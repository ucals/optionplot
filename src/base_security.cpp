//
// Author: Carlos Souza <souza.ca80@gmail.com>, <souza@gatech.edu>
// Date: 27/Feb/2023
//
// This file implements the BaseSecurity class
//
#include <iostream>
#include <nlohmann/json.hpp>
#include "base_security.hpp"
#include "util.hpp"

using namespace std;
using json = nlohmann::json;

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

	BaseSecurity::~BaseSecurity() {}

	map<string, double> BaseSecurity::priceHistory()
	{
		map<string, double> x;
		return x;
	}
}