#include "GameManage.h"

GameManage::GameManage()
{
	m_iCheckNum = 0;

	for (int y = 0; y < HEIGHT; y++)
	{
		for (int x = 0; x < WIDTH; x++)
		{
			m_CheckMap[y][x] = CHECK_UNKNOWN;
		}
	}
}

void GameManage::Init(Position pos)
{
	
	for (int y = 0; y < HEIGHT; y++)
	{
		for (int x = 0; x < WIDTH; x++)
		{
			m_Map[y][x] = CHECK_BLANK;
		}
	}

	Position tmp = pos;
	for (int i = 0; i < MINE; i++)
	{
		while (tmp == pos || Check(tmp) == CHECK_MINE)
		{
			tmp.x = rand() % WIDTH;
			tmp.y = rand() % HEIGHT;
		}

		m_Map[tmp.y][tmp.x] = CHECK_MINE;
	}

}