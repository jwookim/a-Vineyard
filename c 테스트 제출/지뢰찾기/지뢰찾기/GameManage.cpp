#include "GameManage.h"

GameManage::GameManage()
{
	m_iCheckNum = 0;
	m_Cursor = { 0,0 };
	for (int y = 0; y < HEIGHT; y++)
	{
		for (int x = 0; x < WIDTH; x++)
		{
			MapDraw::GetInstance()->DrawPoint("бр", x, y);
		}
	}

	MapDraw::GetInstance()->gotoxy(m_Cursor.x, m_Cursor.y);
	_getch();
}

void GameManage::Init(Position pos)
{
	Position tmp = pos;
	for (int i = 0; i < MINE; i++)
	{
		while (tmp.x == pos.x  && tmp.y == pos.y)
		{
			tmp.x = rand() % WIDTH;
			tmp.y = rand() % HEIGHT;

			if (m_Map.insert(new Mine(tmp)).second)
				break;
		}
	}

	Block* block = NULL;
	pair<set<Block*>::iterator, bool> pr;
	for (int y = 0; y < HEIGHT; y++)
	{
		for (int x = 0; x < WIDTH; x++)
		{
			if (block == NULL || pr.second == true)
				block = new Block({ x,y });
			else
				block->SetPosition({ x,y });
			
			pr = m_Map.insert(block);
		}
	}

	if (!(pr.second))
		delete block;
}