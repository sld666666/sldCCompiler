#pragma once
#include "../core/base.h"

namespace arithmetic{
	enum TOKEN_TYPE
	{
		TT_INTEGER = 0	,
		TT_DOUBLE		,
		TT_OPERATOR	,
		TT_BRACKETS
	};

	struct Token
	{
		TOKEN_TYPE	type;
		string		content;

		Token(TOKEN_TYPE _type, const string& _content)
			: type(_type)
			, content(_content){

		}
	};

	typedef shared_ptr<Token>	TokenPtr;

	class ArithmeticLexer
	{
	public:
		ArithmeticLexer(void);
		~ArithmeticLexer(void);

		vector<TokenPtr> excute(char* input);

	private:
		TokenPtr	makeToken(char* soruce, TOKEN_TYPE type, int count);
	};
}
