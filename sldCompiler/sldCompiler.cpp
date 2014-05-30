// sldCompiler.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "../core/Log.h"
//#include "TestorInclude.h"
#include "ComplierProcess.h"
#include "../arithmetic/ArithmeticProcess.h"



int _tmain(int argc, _TCHAR* argv[])
{
	initLog();
	//ComplierProcess().doComplile();
	arithmetic::ArithmeticProcess().excute();
	return 0;
}

