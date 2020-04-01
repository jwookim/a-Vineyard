#include "Play.h"



Play::Play()
{
	for (int i = 0; i < 3; i++)
		m_Line[i] = NULL;

	m_iInterval = 1000;
	m_bSkip = false;
}

void Play::Setting()
{
	cout << "쌓고싶은 탑의 층 수를 입력하시오 : ";
	cin >> m_iFloor;

	char Buff[50];

	sprintf(Buff, "mode con cols=%d lines=%d", max((m_iFloor + 1) * 6 + 5, 80), m_iFloor + 2);
	system(Buff);
	system("cls");

	for (int i = m_iFloor; i >= 1; i--)
		CreateBlock(0, i);

	DrawManager.DrawMidText("일시정지/재개 : Space Bar   Skip : Enter   가속 : w   감속 : s", max(m_iFloor * 3, 40), m_iFloor + 1);
}

void Play::Start()
{
	TimeInterval();
	MoveTower(0, 2, m_iFloor);
	if (m_bSkip)
		DrawAll();
	DrawManager.DrawMidText("하노이의 탑 종료", max(m_iFloor * 3, 40), m_iFloor);
	getch();
}

void Play::CreateBlock(int line, int num)
{
	Block* tmp = new Block;
	tmp->SetNum(num);
	tmp->SetNextBlock(m_Line[line]);
	m_Line[line] = tmp;

	m_Line[line]->DrawBlock(line, m_iFloor);
}

void Play::MoveTower(int start, int dest, int num)
{
	if (num == 1)
		MoveBlock(start, dest);
	else
	{
		for (int i = 0; i < 3; i++)
		{
			if (!(i == start || i == dest))
			{
				MoveTower(start, i, num - 1);
				MoveBlock(start, dest);
				MoveTower(i, dest, num - 1);
				break;
			}
		}
	}
}


void Play::MoveBlock(int start, int dest)
{
	if (m_Line[start] != NULL)
	{
		if (!m_bSkip)
			m_Line[start]->EraseBlock(start, m_iFloor);
		Block* tmp;
		tmp = m_Line[start];
		m_Line[start] = m_Line[start]->GetNextBlock();
		tmp->SetNextBlock(m_Line[dest]);
		m_Line[dest] = tmp;

		if (!m_bSkip)
			m_Line[dest]->DrawBlock(dest, m_iFloor);

		if (!m_bSkip)
			TimeInterval();
	}
	else
	{
		DrawManager.DrawMidText("ERROR - 이동시킬 블럭이 존재하지 않습니다.", max(m_iFloor * 3, 40), m_iFloor);
		system("pause");
	}
}

void Play::TimeInterval()
{
	for (int time = clock(); clock() - time <= m_iInterval;)
	{
		if (kbhit())
		{
			char tmp = getch();
			if (tmp == ' ')
			{
				while (getch() != ' ')
				{
				}
			}
			else if (tmp == 13)
				m_bSkip = true;
			else if (tmp == 'w' && m_iInterval > 100)
				m_iInterval -= 100;
			else if (tmp == 's' && m_iInterval != 0)
				m_iInterval += 100;

		}
	}
}

void Play::DrawAll()
{
	system("cls");
	for (int i = 0; i < 3; i++)
	{
		if (m_Line[i] != NULL)
			m_Line[i]->DrawAll(i, m_iFloor);
	}
}

void Play::DeleteBlock(Block* block)
{
	if (block != NULL)
	{
		DeleteBlock(block->GetNextBlock());
		block->SetNextBlock(NULL);
		delete block;
	}
}

Play::~Play()
{
	for (int i = 0; i < 3; i++)
	{
		DeleteBlock(m_Line[i]);
		m_Line[i] = NULL;
	}
}
