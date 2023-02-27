//
// Author: Carlos Souza <souza.ca80@gmail.com>, <souza@gatech.edu>
// Date: 27/Feb/2023
//
// This file tests the BaseSecurity class
//
#include <gtest/gtest.h>
#include "base_security.hpp"

using namespace std;
using namespace CarlosSouza;

TEST(BaseSecurityTest, Constructors) {
	BaseSecurity spx("^SPX");
	// EXPECT_EQ(1, 1);
}

TEST(BaseSecurityTest, PriceHistory) {
	BaseSecurity spx("^SPX");
	map<time_t, double> prices = spx.priceHistory();
	// EXPECT_EQ(1, 1);

	// map<time_t, double>::iterator it;
	// for (it = prices.begin(); it != prices.end(); it++)
	// {
	// 	cout << ctime (&(it->first)) << "\t" << it->second << endl;
	// }
}

TEST(BaseSecurityTest, PlotPriceHistory) {
	BaseSecurity spx("^SPX");
	spx.plotPriceHistory();
}