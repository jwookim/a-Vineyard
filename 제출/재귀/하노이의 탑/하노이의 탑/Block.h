#pragma once
#include<iostream>
#include<string>
using namespace std;

class Block
{
private:
	int m_iNum;
	Block* nextBlock = NULL;
public:
	void SetNum(int num);
	void SetNextBlock(Block* nextBlock);
	inline int GetNum()
	{
		return m_iNum;
	}
	inline Block* GetNextBlock()
	{
		return nextBlock;
	}
	Block();
	~Block();
};

