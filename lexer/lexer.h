#pragma once
#include "../core/base.h"

enum LEXER_TOKEN_TYPE{
	LTT_FLAG	= 0,
	LTT_KEYWORD = 1,//关键字
	LTT_OPERATOR	,//运算符
	LTT_CONSTANT	,//常量
	LTT_VARIATE		,//变量
	LTT_IDENTIFIER	,//标识符
	LTT_STRING		,//字符串
	//LTT_NUMBER		,
	//LTT_Real		,
	LTT_DELIMITER	,
	LTT_COMMENT//注释
};

struct Token{
	Token(ulong _lineNum, LEXER_TOKEN_TYPE _tokenType, const string& _token)
		: lineNum(_lineNum)
		, tokenType(_tokenType)
		, token(_token)
	{
	}
	
	wstring		fileName;
	ulong		lineNum;
	LEXER_TOKEN_TYPE tokenType;
	string		token;	
};

typedef shared_ptr<Token> TokenPtr;

sld_interface ILexer{
	virtual	vector<TokenPtr> excute(char* soruce) = 0;
};