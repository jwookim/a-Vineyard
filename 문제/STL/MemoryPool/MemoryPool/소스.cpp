#include<iostream>
#include<ctime>
#include<chrono>
#include"MemoryPool.h"
#include <crtdbg.h>
#define _CRTDBG_MAP_ALLOC

void main()
{

	srand((unsigned)time(NULL));
	 
	MemoryPool<char*> Mp;

	chrono::system_clock::time_point start;
	chrono::system_clock::time_point end;
	chrono::microseconds microSec;

	char** list[100];


	start = chrono::system_clock::now();
	for (int i = 0; i < 100; i++)
	{
		int ran = rand() % 9991 + 10;
		list[i] = new char*;
		*list[i] = new char[ran];
	}


	for (int i = 0; i < 100; i++)
	{
		delete *list[i];

		delete list[i];
	}


	end = chrono::system_clock::now();

	microSec = chrono::duration_cast<chrono::microseconds>(end - start);

	cout << "메모리풀 미적용 작업시간 - " << microSec.count() << " us\n" << endl;



	start = chrono::system_clock::now();
	for (int i = 0; i < 100; i++)
	{
		int ran = rand() % 9991 + 10;
		list[i] = (char**)Mp.Alloc();
		*list[i] = new char[ran];
	}

	for (int i = 0; i < 100; i++)
	{
		delete *list[i];

		Mp.DeAlloc(list[i]);
	}
	end = chrono::system_clock::now();

	microSec = chrono::duration_cast<chrono::microseconds>(end - start);

	cout << "메모리풀 적용된 작업시간 - " << microSec.count() << " us\n" << endl;

	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
}