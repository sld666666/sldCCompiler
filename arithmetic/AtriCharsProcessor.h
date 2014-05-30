#pragma once
#include "../core/base.h"

namespace arithmetic{
	typedef function<int(char)> LexFp;

	class AtriCharsProcessor
	{
	public:
		AtriCharsProcessor(void);
		~AtriCharsProcessor(void);

		static int	lexerChars(char*& input, LexFp lexFp);
		static int	lexerOneChar(char*& input, LexFp lexFp);
		static bool lexerChars(char*& input, char comparedCh);

		static int	removeSpace(char*& input);
		static int	lexerOperator(char*& input);
		static int	lexerPunctuation(char*& input);
		static int	lexerReal(char*& input);
		static int	lexerInterger(char*& input);
	};
}


