#include "StdAfx.h"
#include "ArithmeticProcess.h"
#include "ArithmeticLexer.h"
#include "../core/StringConvertor.h"
#include "../core/OutputDebug.h"

namespace arithmetic{

	void printToken(const TokenPtr& token)
	{
		wstring tokenStr = L"tokens-----TOKEN_TYPE:" 
			+ StringConvertor<int>::toString(token->type) + L","
			+ L"token:"+StringConvertor<string>::toString(token->content)+L"\n";

		OutputDebug<>::outputString(tokenStr);
	}

	ArithmeticProcess::ArithmeticProcess(void)
	{
	}

	ArithmeticProcess::~ArithmeticProcess(void)
	{
	}

	void ArithmeticProcess::excute()
	{
		string str = "1*2*3+4*5*6+7*8*9";
		vector<TokenPtr>tokens =  ArithmeticLexer().excute(&str[0]);

		std::for_each(tokens.begin(), tokens.end(), printToken);
	}
}

