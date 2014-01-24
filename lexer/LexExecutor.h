#pragma once
#include "lexer.h"

class LexExecutor : public ILexer
{
public:
	LexExecutor(void);
	~LexExecutor(void);

	virtual vector<TokenPtr> excute(char* soruce);

private:
	TokenPtr makeToken(char* soruce, LEXER_TOKEN_TYPE type, int counts, int line);
};
