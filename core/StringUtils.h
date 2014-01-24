#pragma once
#include "base.h"
class StringUtils{
public:
	static string wstrToStr(const wstring& wstr);
	static wstring strToWstr(const string& str);

	static vector<wstring> splitLast(const wstring& wstr, const wstring& stuff);
	static vector<string> splitLast(const string& str, const string& stuff);
};