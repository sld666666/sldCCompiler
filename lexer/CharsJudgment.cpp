#include "StdAfx.h"
#include "CharsJudgment.h"

CharsJudgment::CharsJudgment(void)
{
}

CharsJudgment::~CharsJudgment(void)
{
}

bool CharsJudgment::isEnter(char input)
{
	return ('\n' == input);
}

bool CharsJudgment::isDigit(char input)
{
	return input>='0' && input<='9';
}

bool CharsJudgment::isLetter(char input)
{
	return (input>=L'a' && input<=L'z') 
			||(input>=L'A' && input<=L'Z') 
			||(input==L'_');
}

bool CharsJudgment::isSpace(char input)
{
	return (' ' == input
			||'\t' == input);
}

bool CharsJudgment::isOpreator(char input)
{
	return ('=' == input 
		|| '{' == input 
		|| '}' == input 
		|| '{' == input 
		|| '}' == input);
}

bool CharsJudgment::notDQM(char input)
{
	return (input !='\"');
}

bool CharsJudgment::notEndComment(char input)
{
	return (input !='/');
}