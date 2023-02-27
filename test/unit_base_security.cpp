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
	EXPECT_EQ(1, 1);
}