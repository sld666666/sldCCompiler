#include "StdAfx.h"
#include "ComplierProcess.h"
#include "../io/MappingFileReader.h"
#include "../lexer/LexExecutor.h"

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

}