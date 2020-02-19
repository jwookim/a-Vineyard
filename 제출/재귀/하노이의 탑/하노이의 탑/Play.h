#pragma once
#include"Block.h"

class Play
{
private:
	Block* m_Line[3];
public:
	void Setting();
	void MoveBlock(int start, int dest);
	Block* PutBlock(int line);
	void PullBlock(int line, Block* block);
	Play();
	~Play();
};

