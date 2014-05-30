#include "StdAfx.h"
#include "ArithmeticLexer.h"
#include "AtomJudgment.h"
#include "AtriCharsProcessor.h"

namespace arithmetic{

	ArithmeticLexer::ArithmeticLexer(void)
	{
	}

	ArithmeticLexer::~ArithmeticLexer(void)
	{
	}

	vector<TokenPtr> ArithmeticLexer::excute(char* input)
	{
		vector<TokenPtr> tokens;

		AtriCharsProcessor::lexerChars(input, bind(AtomJudgent::isEnter, _1));

		while(*input != NULL){
			int count(0);
			if (count=AtriCharsProcessor::lexerOperator(input)){
				tokens.push_back(makeToken(input, TT_OPERATOR, count));
			}else if(count=AtriCharsProcessor::lexerPunctuation(input)){
				tokens.push_back(makeToken(input, TT_BRACKETS, count));
			}else if(count=AtriCharsProcessor::lexerInterger(input)){
				tokens.push_back(makeToken(input, TT_INTEGER, count));
			}else{
				++input;
			}
		}

		return tokens;
	}

	TokenPtr ArithmeticLexer::makeToken(char* soruce
									, TOKEN_TYPE type
									, int count)
	{
		string token = string(soruce-count, count);
		return TokenPtr(new Token(type,token));
	}
}

