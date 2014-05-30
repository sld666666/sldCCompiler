#include "StdAfx.h"
#include "AtriCharsProcessor.h"
#include "AtomJudgment.h"

namespace arithmetic{

	AtriCharsProcessor::AtriCharsProcessor(void)
	{
	}

	AtriCharsProcessor::~AtriCharsProcessor(void)
	{
	}

	int AtriCharsProcessor::lexerChars(char*& input
										, LexFp lexFp)
	{
		int count (0);
		while(lexFp(*input)){
			++count;
			++input;
		}
		return count;
	}

	int	AtriCharsProcessor::lexerOneChar(char*& input
		, LexFp lexFp)
	{
		int count(0);
		if(lexFp(*input)){
			++count;
			++input;
		}
		return count;
	}

	bool AtriCharsProcessor::lexerChars(char*& input, char comparedCh)
	{
		bool rtn(false);
		if(comparedCh == *input){
			++input;
			rtn = true;
		}
		return rtn;
	}

	int	AtriCharsProcessor::removeSpace(char*& input)
	{
		return AtriCharsProcessor::lexerChars(input, bind(AtomJudgent::isSpace, _1));
	}

	int	AtriCharsProcessor::lexerOperator(char*& input)
	{
		return AtriCharsProcessor::lexerOneChar(input, bind(AtomJudgent::isOpreator, _1));
	}

	int	AtriCharsProcessor::lexerReal(char*& input)
	{
		int count(0);
		return count;
	}

	int	AtriCharsProcessor::lexerPunctuation(char*& input)
	{
		return AtriCharsProcessor::lexerOneChar(input, bind(AtomJudgent::isPunctuation, _1));
	}		

	int AtriCharsProcessor::lexerInterger(char*& input)
	{
		return AtriCharsProcessor::lexerChars(input, bind(AtomJudgent::isDigit, _1));
	}

}

