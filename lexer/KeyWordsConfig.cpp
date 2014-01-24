#include "StdAfx.h"
#include "KeyWordsConfig.h"
#include <boost/filesystem/path.hpp>
#include <boost/filesystem/operations.hpp>
#include "../core/StringUtils.h"

KeyWordsConfig::KeyWordsConfig(void)
{
}

KeyWordsConfig::~KeyWordsConfig(void)
{
}

bool KeyWordsConfig::contains(const string& keyword)
{
	if (keyWords_.empty()) init();
	return (keyWords_.end() != std::find(keyWords_.begin(), keyWords_.end(), keyword));
}

void KeyWordsConfig::init()
{
	wstring curPath = boost::filesystem::current_path<boost::filesystem::wpath>().string();
	wstring filePath = curPath + L"/" + L"configs/keywords.txt";
	string datas = readFile(filePath);
	keyWords_ = StringUtils::splitLast(datas, ";");
}
