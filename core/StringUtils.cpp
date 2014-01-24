#include "stdafx.h"
#include "StringUtils.h"

string StringUtils::wstrToStr(const wstring& wstr)
{
	return std::string(wstr.begin(), wstr.end());
}


wstring StringUtils::strToWstr(const string& str)
{
	return std::wstring(str.begin(), str.end());
}

vector<wstring> StringUtils::splitLast(const wstring& wstr, const wstring& stuff)
{
	vector<wstring> strList;
	int pos = wstr.rfind(stuff);
	if (-1 != pos){
		strList.push_back(wstr.substr(0,pos));
		strList.push_back(wstr.substr(pos+1, wstr.length()));

	}
	strList.push_back(wstr);
	return strList;
}

vector<string> StringUtils::splitLast(const string& str, const string& stuff)
{
	vector<string> strList;
	int pos = str.rfind(stuff);
	if (-1 != pos){
		strList.push_back(str.substr(0,pos));
		strList.push_back(str.substr(pos+1, str.length()));

	}
	strList.push_back(str);
	return strList;
}
