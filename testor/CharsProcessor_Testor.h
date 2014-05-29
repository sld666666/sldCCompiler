#pragma  once

//#define BOOST_TEST_MODULE KeyWordsConfig_Testor
#include <boost/test/included/unit_test.hpp>
#include "../lexer/CharsProcessor.h"
#include <vector>
#include <string>
#include <algorithm>

BOOST_AUTO_TEST_SUITE (CharsProcessor_Testor) // name of the test suite is stringtest

BOOST_AUTO_TEST_CASE (lexerKeyWordOrVar)
{
	std::vector<std::string> keywords;
	keywords.push_back("int");
	keywords.push_back("double");
	keywords.push_back("goto");
	for (std::vector<std::string>::iterator iter = keywords.begin();
			iter != keywords.end(); ++iter)
	{
		string tmp = *iter;
		char* input = &tmp[0];
		BOOST_CHECK(CharsProcessor::lexerKeyWordOrVar(input) > 0);
	}
}

void checkOpreator(const std::string& value)
{
	string tmp = value;
	char* input = &tmp[0];
	BOOST_CHECK(CharsProcessor::lexerOperator(input) > 0);
}

BOOST_AUTO_TEST_CASE (lexerOperator)
{
	std::vector<std::string> values;
	values.push_back("=");
	values.push_back("=12");
	values.push_back(">12");
	values.push_back("<ab");
	std::for_each(values.begin(), values.end(), checkOpreator);

	string value("1234");
	char* input = &value[0];
	BOOST_CHECK(CharsProcessor::lexerOperator(input) <= 0);
}

BOOST_AUTO_TEST_CASE (lexerString)
{
	string value("1234");
	char* input = &value[0];
	BOOST_CHECK(CharsProcessor::lexerString(input) <= 0);

	value = ("\"1234\"");
	input = &value[0];
	BOOST_CHECK(CharsProcessor::lexerString(input) == 4);
}

BOOST_AUTO_TEST_CASE (isNumber)
{
	char* input = "1234";
	BOOST_CHECK(CharsProcessor::isNumber(input));

	input = "123a4";
	BOOST_CHECK(!CharsProcessor::isNumber(input));
}

BOOST_AUTO_TEST_CASE (lexerComment)
{
	char* input = "/*1234*/";
	BOOST_CHECK(CharsProcessor::lexerComment(input) == 8);

}



BOOST_AUTO_TEST_SUITE_END( )