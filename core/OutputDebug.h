#pragma once
#include <windows.h>
#include "OsDefinition.h"

template<typename T = Windows>

class OutputDebug{
public:
	static void outputString(const wstring& value)
	{
		::OutputDebugString(value.c_str());
	}
};



template<>
class OutputDebug<Linux>{
public:
	static void outputString(const wstring& value)
	{
	}
};