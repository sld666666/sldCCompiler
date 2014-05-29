#include "StdAfx.h"
#include "ComplierProcess.h"
#include "../io/MappingFileReader.h"
#include "../lexer/LexExecutor.h"
#include "../core/OutputDebug.h"
#include "../core/StringConvertor.h"
#include "../core/base.h"

void printToken(const TokenPtr& token)
{
	wstring tokenStr = L"tokens-----line_num:" 
		+ StringConvertor<long>::toString(token->lineNum) + L","
		+ L"token_type:" + StringConvertor<int>::toString(token->tokenType)+L","
		+ L"token:"+StringConvertor<string>::toString(token->token)+L"\n";

	OutputDebug<>::outputString(tokenStr);
}
ComplierProcess::ComplierProcess(void)
{
}

ComplierProcess::~ComplierProcess(void)
{
}

void ComplierProcess::doComplile()
{
	// 1. read
	shared_ptr<IFileReader> fileReader(new MappingFileReader());
	wstring filePath = L"E:\\project\\github\\sldCCompiler\\testor\\test.c";
	fileReader->setFileName(filePath);
	char* datas = fileReader->read();

	//2. lexer
	shared_ptr<ILexer> lexer(new LexExecutor());
	vector<TokenPtr> lexUnits = lexer->excute(datas);
	std::for_each(lexUnits.begin(), lexUnits.end(), bind(&printToken, _1));
}