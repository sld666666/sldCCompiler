#pragma  once

//#define BOOST_TEST_MODULE KeyWordsConfig_Testor
#include <boost/test/included/unit_test.hpp>
#include "../lexer/KeyWordsConfig.h"
#include <vector>
#include <string>
#include <algorithm>

void checked(const std::string& value)
{
	bool result(false);
	//result = KeyWordsConfig::instance().isKeyWords(value);
	//BOOST_CHECK(result);
}

BOOST_AUTO_TEST_SUITE (KeyWordsConfig_Testor) // name of the test suite is stringtest

BOOST_AUTO_TEST_CASE (test1)
{
	std::vector<std::string> keywords;
	keywords.push_back("int");
	keywords.push_back("double");
	keywords.push_back("goto");
	std::for_each(keywords.begin(), keywords.end(), checked);
}


BOOST_AUTO_TEST_SUITE_END( )