#pragma  once

#define BOOST_TEST_MODULE MappingFileReader_Testor
#include <boost/test/included/unit_test.hpp>
#define private public
#include "../io/MappingFileReader.h"

BOOST_AUTO_TEST_SUITE (MappingFileReader_Testor) // name of the test suite is stringtest

BOOST_AUTO_TEST_CASE (test1)
{
	wstring filePath = L"E:\\project\\github\\sldCCompiler\\testor\\test.c";
	MappingFileReader read;
	HANDLE  fileHandle =read.openFile(filePath);
	BOOST_CHECK(fileHandle != NULL);
	
	HANDLE handleMapping = read.createFileMap(fileHandle);
	BOOST_CHECK(handleMapping != NULL);

	CloseHandle(handleMapping);
	CloseHandle(fileHandle);

	BOOST_CHECK(read.readFile(filePath) != NULL);
}


BOOST_AUTO_TEST_SUITE_END( )