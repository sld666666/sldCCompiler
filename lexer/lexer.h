#pragma once
#include "../core/base.h"

enum LEXER_TOKEN_TYPE{
	LTT_FLAG	= 0,
	LTT_KEYWORD = 1,//�ؼ���
	LTT_OPERATOR	,//�����
	LTT_CONSTANT	,//����
	LTT_VARIATE		,//����
	LTT_IDENTIFIER	,//��ʶ��
	LTT_STRING		,//�ַ���
	//LTT_NUMBER		,
	//LTT_Real		,
	LTT_DELIMITER	,
	LTT_COMMENT//ע��
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