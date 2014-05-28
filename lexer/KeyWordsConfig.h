#pragma once
#include "../core/ISingleton.h"
#include "../core/base.h"
#include "../io/IWinMappingFile.h"

class KeyWordsConfig : public ISingleton<KeyWordsConfig>
					 , public IWinMappingFile<KeyWordsConfig>
{
public:
	~KeyWordsConfig(void);

	bool	isKeyWords(const string& keyword);
private:
	void	init();

private:
	KeyWordsConfig(void);
	friend class ISingleton<KeyWordsConfig>;

private:
	vector<string>	keyWords_;	
};
