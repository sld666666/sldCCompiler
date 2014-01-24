#pragma once
#include "../core/base.h"
#include "CharsJudgment.h"

typedef function<int(char)> LexFp;

class CharsProcessor
{
public:
	CharsProcessor(void);
	~CharsProcessor(void);

	static int	lexerChars(char*& input, LexFp lexFp);
	static bool lexerChars(char*& input, char comparedCh);
	static int	removeSpace(char*& input);
	static int	lexerKeyWord(char*& input);
	static int	lexerOperator(char*& input);
	static int	lexerVariable(char*& input);
	static int	lexerString(char*& input);
	static int	lexerNumber(char*& input);
	static int	lexerReal(char*& input);
	static int	lexerDelimiter(char*& input);
	static int	lexerComment(char*& input);
};
