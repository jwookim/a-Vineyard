#include "Play.h"



Play::Play()
{
	Init();
}

void Play::Story()
{
	ifstream load;
	int lineMax;
	int line = 0;
	int time;
	char skip = NULL;

	load.open("베네치아_스토리.txt");

	if (load.is_open())
	{
		load >> lineMax;


		for (int i = 0; i < lineMax && skip != 's'; i++)
		{
			system("cls");
			time = clock();
			if (line >= LINE)
			{
				for (int j = 0; j < LINE - 1; j++)
					m_strStory[j] = m_strStory[j + 1];
				line--;
			}

			getline(load, m_strStory[line]);

			for (int j = 0; j < LINE; j++)
			{
				/*Draw*/
				cout << m_strStory[j] << endl;
			}
			

			if (line < LINE)
				line++;

			while (clock() - time < 1000)
			{
				if (kbhit())
				{
					skip = getch();

					if (skip == 's')
						break;
				}
			}
		}
	}
}

void Play::Game()
{
	int time = clock();
	char input;
	int totalScore = 0;
	int Delay = DELAY;

	while (m_iLife > 0)
	{

		if (clock() - time >= Delay)
		{
			AddWord();
			m_iLife -= DropWord();

			time = clock();
		}

		if (kbhit() && !m_bStun)
		{
			input = getch();

			if ((input >= 'a' && input <= 'z') || (input >= 'A' && input <= 'A'))
				m_strInput += input;
			else if (input == 13 && m_strInput != "")
				WordCheck(CheckWord(m_strInput));
		}

		if (m_bStun && clock() - m_iStunTime >= STUN)
		{
			m_bStun = false;
		}
		if (m_iScore >= SCOREMAX - ((m_iStage - 1) * LVSCORE))
		{
			totalScore += m_iScore;
			m_iScore = 0;
			m_iStage++;
		}
	}
}

void Play::Goal(int len)
{
	m_iScore += len * SCORE;
}

void Play::WordCheck(bool check)
{
	if (check)
	{
		Goal(m_strInput.length());
	}
	else if (!check)
	{
		m_bStun = true;
		m_iStunTime = clock();
	}

	m_strInput = "";
}

void Play::Init()
{
	m_strName = "? ? ?";
	m_iScore = 0;
	m_iLife = LIFE;
	m_iStage = 1;
	m_bStun = false;

	for (int i = 0; i < LINE; i++)
		m_strStory[i] = "";

	WordInit();
}

Play::~Play()
{
}
