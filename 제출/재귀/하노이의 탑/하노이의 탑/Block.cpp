#include "Block.h"



Block::Block()
{
	m_pNextBlock = NULL;
}

void Block::SetNum(int num)
{
	m_iNum = num;
}

void Block::SetNextBlock(Block* nextBlock)
{
	m_pNextBlock = nextBlock;
}

void Block::DrawBlock(int line, int size)
{
	string content;

	for (int i = 0; i < m_iNum; i++)
		content += "¢Ë";

	DrawManager.DrawMidText(content, size + (((size + 1) * 2) * line) + 2, size - CheckPos());
}

void Block::EraseBlock(int line, int size)
{
	string content;

	for (int i = 0; i < m_iNum; i++)
		content += "  ";

	DrawManager.DrawMidText(content, size + (((size + 1) * 2) * line) + 2, size - CheckPos());
}

int Block::DrawAll(int line, int size)
{
	string content;
	int pos = 1;

	for (int i = 0; i < m_iNum; i++)
		content += "¢Ë";


	if (m_pNextBlock != NULL)
	{
		pos = m_pNextBlock->DrawAll(line, size) + 1;
	}

	DrawManager.DrawMidText(content, size + (((size + 1) * 2) * line) + 2, size - pos);

	return pos;
}

int Block::CheckPos()
{
	if (m_pNextBlock != NULL)
	{
		return m_pNextBlock->CheckPos() + 1;
	}
	else
		return 1;
}


Block::~Block()
{
}
