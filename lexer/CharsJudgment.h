#pragma once

class CharsJudgment
{
public:
	CharsJudgment(void);
	~CharsJudgment(void);

	static bool	isEnter(char input);
	static bool isDigit(char input);
	static bool isLetter(char Input);
	static bool	isSpace(char input);
	static bool isOpreator(char input);
	static bool notDQM(char input);
	static bool notEndComment(char input);
};
