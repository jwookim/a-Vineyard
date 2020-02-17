#include "Rank.h"



Rank::Rank()
{
}

void Rank::Show(int line)
{
	Load();

	for (int i = 0; i < 10; i++)
	{
		if (m_Info[i].name != "")
		{
			DrawManager.TextDraw(m_Info[i].name, WIDTH - (WIDTH / 3), line + (i * 2));
			DrawManager.TextDraw(to_string(m_Info[i].score), WIDTH, line + (i * 2));
			DrawManager.TextDraw(to_string(m_Info[i].level), WIDTH + (WIDTH / 3), line + (i * 2));
		}
	}
	getch();
}

void Rank::Load()
{
	ifstream load;
	Info tmp;

	load.open("Rank.txt");

	while (!load.eof())
	{
		load >> tmp.name >> tmp.level >> tmp.score;

		for (int i = 0; i < 10; i++)
		{
			if (tmp.level > m_Info[i].level)
			{
				ListDown(i);
				m_Info[i] = tmp;
				break;
			}
			else if (tmp.level == m_Info[i].level)
			{
				if (tmp.score > m_Info[i].score)
				{
					ListDown(i);
					m_Info[i] = tmp;
					break;
				}

				if (tmp.score == m_Info[i].score && tmp.name == m_Info[i].name)
					break;
			}
		}
	}

}

void Rank::ListDown(int num)
{
	for (int i = 9; i > num; i--)
	{
		m_Info[i] = m_Info[i - 1];
	}
}

void Rank::Save(string name, int level, int score)
{
	ofstream save;
	save.open("Rank.txt", ios::app);
	if (save.is_open())
	{
		save << name << " " << level << " " << score << endl;
	}
	save.close();
}

Rank::~Rank()
{
}
