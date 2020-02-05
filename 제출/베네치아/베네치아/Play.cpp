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
	m_bState = true;
	int time = clock();

	int Delay = DELAY;

	while (m_bState)
	{
		while (true)
		{
			if (clock() - time >= Delay)
			{

			}
		}
	}
}

void Play::Init()
{
	m_strName = "? ? ?";
	m_iScore = 0;
	m_iLife = 9;
	m_iStage = 1;
	m_strInput = "";
	m_bState = false;

	for (int i = 0; i < LINE; i++)
		m_strStory[i] = "";
}

Play::~Play()
{
}
