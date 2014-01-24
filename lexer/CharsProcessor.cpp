#include "StdAfx.h"
#include "CharsProcessor.h"

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

int	CharsProcessor::lexerKeyWord(char*& input)
{
	return CharsProcessor::lexerChars(input, bind(CharsJudgment::isLetter, _1));
}

int	CharsProcessor::lexerOperator(char*& input)
{
	return CharsProcessor::lexerChars(input, bind(CharsJudgment::isOpreator, _1));
}

int	CharsProcessor::lexerVariable(char*& input)
{
	int count(0);
	return count;
}

int	CharsProcessor::lexerString(char*& input)
{
	int count(0);
	if (lexerChars(input, '\"')){
		count += lexerChars(input,  bind(CharsJudgment::notDQM, _1));
		if (!lexerChars(input, '\"'))return 0;
	}
	return count;
}

int	CharsProcessor::lexerNumber(char*& input)
{
	int count(0);
	return count;
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
		count += lexerChars(input,  bind(CharsJudgment::notEndComment, _1));
		if (!lexerChars(input, '/'))return 0;
	}
	return count;
}