#pragma once
#include <iostream>
#include <crtdbg.h>
#if _DEBUG
#define new new(_NORMAL_BLOCK, _FILE_, _LINE_)
#define malloc(s) _malloc_dbg(s,_NORMAL_BLOCK, _FILE_ ,_LINE_)
#endif

using namespace std;

int main()
{

	int* a = new int;
	_CrtDumpMemoryLeaks();

	return 0;
}