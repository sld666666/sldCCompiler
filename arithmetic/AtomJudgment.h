#pragma once

namespace arithmetic{
	class AtomJudgent{
	public:
		static bool isDigit(char input);
		static bool isLetter(char Input);
		static bool	isSpace(char input);
		static bool isOpreator(char input);
		static bool isPunctuation(char input);
		static bool	isEnter(char input);
	};
}

