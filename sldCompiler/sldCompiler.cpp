// sldCompiler.cpp : �������̨Ӧ�ó������ڵ㡣
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

