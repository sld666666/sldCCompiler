#include "StdAfx.h"
#include "LexExecutor.h"
#include "CharsProcessor.h"
#include "KeyWordsConfig.h"

LexExecutor::LexExecutor(void)
{
}

LexExecutor::~LexExecutor(void)
{
}

vector<TokenPtr> LexExecutor::excute(char* soruce)
{
	vector<TokenPtr> lexUnits;

	int line(0);
	while(*soruce != NULL){
		line += CharsProcessor::lexerChars(soruce, bind(CharsJudgment::isEnter, _1));

		int count(0);
		if ( count=CharsProcessor::lexerComment(soruce)){
			lexUnits.push_back(makeToken(soruce, LTT_COMMENT, count, line));
		}else if (count=CharsProcessor::lexerString(soruce)){
			lexUnits.push_back(makeToken(soruce, LTT_STRING, count, line));
		}else if ( count=CharsProcessor::lexerOperator(soruce)){
			lexUnits.push_back(makeToken(soruce, LTT_OPERATOR, count, line));
		}else if(count=CharsProcessor::lexerIdentifier(soruce)){
			lexUnits.push_back(makeToken(soruce, LTT_IDENTIFIER, count, line));
		} else {
			if (count=CharsProcessor::lexerKeyWordOrVar(soruce)){
				string token = string(soruce-count, count);
				if(KeyWordsConfig::instance().isKeyWords(token)){
					lexUnits.push_back(makeToken(soruce, LTT_KEYWORD, count, line));
				} else if(CharsProcessor::isNumber(token.c_str())){
					lexUnits.push_back(makeToken(soruce, LTT_CONSTANT, count, line));
				} else{
					lexUnits.push_back(makeToken(soruce, LTT_VARIATE, count, line));
				}
			
			}else{
				++soruce;
			}
		}
	}
	return lexUnits;
}


TokenPtr LexExecutor::makeToken(char* soruce
							 , LEXER_TOKEN_TYPE type
							 , int counts
							 , int line)
{
	string token = string(soruce-counts, counts);
	return TokenPtr(new Token(line, type,token));
}