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

	string tmp = str;
	int pos = tmp.rfind(stuff);
	while (-1 != pos)
	{
		string value = tmp.substr(pos+1, str.length());
		if (!value.empty())strList.push_back(value);

		tmp = str.substr(0,pos);
		pos = tmp.rfind(stuff);	
	}

	if(!tmp.empty())strList.push_back(tmp);

	return strList;
}
