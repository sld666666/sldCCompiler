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
			||'\t' == input
			|| CharsJudgment::isEnter(input)
			|| 13 == input);
}

bool CharsJudgment::isOpreator(char input)
{
	return ('=' == input 
		|| '>' == input 
		|| '<' == input 
		|| '+' == input 
		|| '-' == input
		|| '*' == input
		|| '/' == input
		|| '%' == input
		|| '!' == input
		|| '&' == input);
}

bool CharsJudgment::isPunctuation(char input)
{
	return ('[' == input 
		|| ']' == input 
		|| '(' == input 
		|| ')' == input 
		|| '{' == input
		|| '}' == input
		|| ',' == input
		|| ';' == input
		|| '#' == input);
}

bool CharsJudgment::notDQM(char input)
{
	return (input !='\"');
}

bool CharsJudgment::notEndComment(char input)
{
	return (input !='/');
}

bool CharsJudgment::isNotWordsSeparator(char input)
{
	return !isWordsSeparator(input);
}

bool CharsJudgment::isWordsSeparator(char input)
{
	return (CharsJudgment::isSpace(input)
		|| CharsJudgment::isOpreator(input)
		|| CharsJudgment::isPunctuation(input));
}