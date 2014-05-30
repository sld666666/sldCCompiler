#include "stdafx.h"
#include "AtomJudgment.h"

namespace arithmetic{
	bool AtomJudgent::isDigit(char input)
	{
		return input>='0' && input<='9'; 
	}

	bool AtomJudgent::isSpace(char input)
	{
		return (' ' == input
			||'\t' == input
			|| AtomJudgent::isEnter(input)
			|| 13 == input);
	}
	bool AtomJudgent::isOpreator(char input)
	{
		return (input == '+'
			|| input == '-'
			|| input == '*'
			|| input == '/');
	}
	bool AtomJudgent::isPunctuation(char input)
	{
		return (input == ')'
			|| input == '(');
	}

	bool AtomJudgent::isEnter(char input)
	{
		return ('\n' == input);
	}

	

}

