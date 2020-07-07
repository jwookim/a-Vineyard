#include "GameManage.h"

GameManage::GameManage()
{
	char Buff[30];
	sprintf_s(Buff, "mode con: cols=%d lines=%d", WIDTH * 2 + 1, HEIGHT + 1);
	system(Buff);


	m_iCheckNum = 0;
	m_bAlive = true;
	m_Cursor = { 0,0 };

	for (int y = 0; y < HEIGHT; y++)
	{
		for (int x = 0; x < WIDTH; x++)
		{
			MapDraw::GetInstance()->DrawPoint("□", x, y);
		}
	}
	
	MoveCursor();
}

void GameManage::Play()
{
	while (m_bAlive && m_iCheckNum < WIDTH*HEIGHT - MINE)
	{
		Move();
	}
	MapDraw::GetInstance()->gotoxy(0, HEIGHT);
	cout << "게임 종료!";
	_getch();
}

void GameManage::Init(Position pos)
{
	Position tmp;
	Mine* mtmp;
	for (int i = 0; i < MINE; i++)
	{
		while (1)
		{
			tmp.x = rand() % WIDTH;
			tmp.y = rand() % HEIGHT;

			if (tmp != pos)
			{
				if (m_Map.insert(pair<Position, Block*>(tmp, mtmp = new Mine(tmp))).second)
					break;
				else
					delete mtmp;
			}
		}
	}

	Block* block = NULL;
	pair<map<Position, Block*>::iterator, bool> pr;
	for (int y = 0; y < HEIGHT; y++)
	{
		for (int x = 0; x < WIDTH; x++)
		{
			if (block == NULL || pr.second == true)
				block = new Block({ x,y });
			else
				block->SetPosition({ x,y });
			
			pr = m_Map.insert(pair<Position, Block*>({ x, y }, block));
		}
	}

	if (!(pr.second))
		delete block;
}

void GameManage::Move()
{
	if (_kbhit())
	{
		switch (_getch())
		{
		case 'w':
			if (m_Cursor.y > 0)
			{
				m_Cursor += UP;
				MoveCursor();
			}
			break;
		case 'a':
			if (m_Cursor.x > 0)
			{
				m_Cursor += LEFT;
				MoveCursor();
			}
			break;
		case 's':
			if (m_Cursor.y < HEIGHT - 1)
			{
				m_Cursor += DOWN;
				MoveCursor();
			}
			break;
		case 'd':
			if (m_Cursor.x < WIDTH - 1)
			{
				m_Cursor += RIGHT;
				MoveCursor();
			}
			break;
		case ENTER:
			Check(m_Cursor);
			MoveCursor();
			break;
		}
	}
}


void GameManage::MoveCursor()
{
	MapDraw::GetInstance()->gotoxy(m_Cursor.x * 2, m_Cursor.y);
}


void GameManage::Check(Position pos)
{
	if (m_iCheckNum == 0)
		Init(pos);

	auto iter = m_Map.find(pos);
	if (iter != m_Map.end())
	{
		m_iCheckNum++;

		if (iter->second->Click() == CHECK_MINE)
			Boom();
		else
		{
			delete iter->second;
			m_Map.erase(iter);
			Direct dir;
			int sum = Detection(pos + (dir = UP));
			sum += Detection(pos + (dir = DOWN));
			sum += Detection(pos + (dir = LEFT));
			sum += Detection(pos + (dir = RIGHT));
			sum += Detection(pos + (dir = UL));
			sum += Detection(pos + (dir = UR));
			sum += Detection(pos + (dir = DL));
			sum += Detection(pos + (dir = DR));

			if (sum == 0)
				Spread(pos);
			else
				MapDraw::GetInstance()->DrawPoint(to_string(sum), pos.x, pos.y);

		}

	}
}


void GameManage::Spread(Position pos)
{
	Direct dir;
	Check(pos + (dir = UP));
	Check(pos + (dir = DOWN));
	Check(pos + (dir = LEFT));
	Check(pos + (dir = RIGHT));
}


int GameManage::Detection(Position pos)
{
	auto iter = m_Map.find(pos);
	if (iter != m_Map.end())
	{
		if (dynamic_cast<Mine*>(iter->second) == NULL)
			return NULL;
		else
			return 1;
	}
	else
		return NULL;
}

void GameManage::Boom()
{
	map<Position, Block*>::iterator iter;
	for (iter = m_Map.begin(); iter != m_Map.end();)
	{
		if (dynamic_cast<Mine*>(iter->second) != NULL)
			iter->second->Click();

		delete iter->second;
		iter = m_Map.erase(iter);
	}

	m_bAlive = false;
}

GameManage::~GameManage()
{
	map<Position, Block*>::iterator iter;
	for (iter = m_Map.begin(); iter != m_Map.end();)
	{
		delete iter->second;
		iter = m_Map.erase(iter);
	}

	MapDraw::DestroyInstance();
}