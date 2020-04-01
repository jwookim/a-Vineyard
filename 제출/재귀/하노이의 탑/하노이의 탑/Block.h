#pragma once
#include<iostream>
#include<string>
#include<Windows.h>
#include<time.h>
#include<conio.h>
#include"MapDraw.h"
using namespace std;

class Block
{
private:
	int m_iNum;
	Block* m_pNextBlock = NULL;
	MapDraw DrawManager;
public:
	void SetNum(int num);
	void SetNextBlock(Block* nextBlock);
	inline int GetNum()
	{
		return m_iNum;
	}
	inline Block* GetNextBlock()
	{
		return m_pNextBlock;
	}
	void DrawBlock(int line, int size);
	void EraseBlock(int line, int size);
	int DrawAll(int line, int size);
	int CheckPos();
	Block();
	~Block();
};

