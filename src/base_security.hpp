//
// Author: Carlos Souza <souza.ca80@gmail.com>, <souza@gatech.edu>
// Date: 27/Feb/2023
//
// This file specifies the BaseSecurity class
//
#ifndef BASE_SECURITY_HPP
#define BASE_SECURITY_HPP

#include <string>
#include <vector>
#include <map>
using namespace std;

namespace CarlosSouza
{
	class BaseSecurity
	{
	private:
		string m_symbol;
		double m_last_price;
		double m_bid;
		double m_ask;
		time_t m_last_trade;
		map<string, double> m_price_history;
		vector<double> m_return_distribution;
	public:
		BaseSecurity();
		BaseSecurity(string t_symbol);
		BaseSecurity(const BaseSecurity& ref);
		~BaseSecurity();

		map<time_t, double> priceHistory();
		void plotPriceHistory();
		vector<double> randomPriceDist(time_t t_future_date, int t_num_simulations);
		void plotRandomPriceDist(time_t t_future_date, int t_num_simulations);

		BaseSecurity operator=(const BaseSecurity& ref);
		double operator[](time_t t_date) const;
	};
}

#endif
