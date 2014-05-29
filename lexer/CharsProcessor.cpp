#include "StdAfx.h"
#include "CharsProcessor.h"
#include "KeyWordsConfig.h"

CharsProcessor::CharsProcessor(void)
{
}

CharsProcessor::~CharsProcessor(void)
{
}

int CharsProcessor::lexerChars(char*& input
								, LexFp lexFp)
{
	int count (0);
	while(lexFp(*input)){
		++count;
		++input;
	}
	return count;
}

int	CharsProcessor::lexerOneChar(char*& input
								 , LexFp lexFp)
{
	int count(0);
	if(lexFp(*input)){
		++count;
		++input;
	}
	return count;
}

bool CharsProcessor::lexerChars(char*& input, char comparedCh)
{
	bool rtn(false);
	if(comparedCh == *input){
		++input;
		rtn = true;
	}
	return rtn;
}

int	CharsProcessor::removeSpace(char*& input)
{
	 return CharsProcessor::lexerChars(input, bind(CharsJudgment::isSpace, _1));
}

int	CharsProcessor::lexerKeyWordOrVar(char*& input)
{
	int counts = CharsProcessor::lexerChars(input
		, bind(CharsJudgment::isNotWordsSeparator, _1));
	return counts;
}

int	CharsProcessor::lexerOperator(char*& input)
{
	return CharsProcessor::lexerChars(input, bind(CharsJudgment::isOpreator, _1));
}

int	CharsProcessor::lexerIdentifier(char*& input)
{
	return CharsProcessor::lexerOneChar(input, bind(CharsJudgment::isPunctuation, _1));
}

int	CharsProcessor::lexerString(char*& input)
{
	int count(0);
	if (lexerChars(input, '\"')){
		++count;
		count += lexerChars(input,  bind(CharsJudgment::notDQM, _1));
		if (!lexerChars(input, '\"')){
			input = input - count;
			count = 0;
		}else{
			++count;
		}
	}
	return count;
}

bool CharsProcessor::isNumber(const char* input)
{
	while(*input != '\0'){	
		if (!CharsJudgment::isDigit(*input))
			return false;
		++input;
	}
	return true;
}

int	CharsProcessor::lexerReal(char*& input)
{
	int count(0);
	return count;
}

int	CharsProcessor::lexerDelimiter(char*& input)
{
	int count(0);
	return count;
}
/**/
int	CharsProcessor::lexerComment(char*& input)
{
	int count(0);
	if (lexerChars(input, '/')){
		++count;
		count += lexerChars(input,  bind(CharsJudgment::notEndComment, _1));
		if (!lexerChars(input, '/')){
			input = input - count;
			count = 0;
		}else{
			++count;
		}
	}
	return count;
}