#pragma once
#include <sstream>

template <typename Input, typename Output = wstring>
class StringConvertor{
public:
	static Output	toString(const Input& input){
		std::wstringstream ss;
		ss << input;
		return ss.str();
	};
};


template<typename Input>
class StringConvertor<Input, string>{
public:
	static string	toString(const Input& input){
		std::stringstream ss;
		ss << input;
		return ss.str();
	};
};


template<>
class StringConvertor<string, wstring>{
public:
	static wstring	toString(const string& input){
		return std::wstring(input.begin(), input.end());
	};
};

template<>
class StringConvertor<wstring, string>{
public:
	static string	toString(const string& input){
		return std::string(input.begin(), input.end());
	};
};