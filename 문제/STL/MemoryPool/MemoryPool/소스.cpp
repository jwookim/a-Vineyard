#include<iostream>
#include<ctime>
#include"MemoryPool.h"

void main()
{

	srand((unsigned)time(NULL));

	MemoryPool<char*> Mp;

	int time = clock();
	char** list = new char*[100];
	Mp.Alloc();
}