// sldCompiler.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "../core/Log.h"
//#include "TestorInclude.h"
#include "ComplierProcess.h"



int _tmain(int argc, _TCHAR* argv[])
{
	initLog();
	ComplierProcess().doComplile();
	return 0;
}

