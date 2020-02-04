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
			if (line >= LINE - 1)
			{
				for (int j = 0; j < LINE - 1; j++)
					m_strStory[j] = m_strStory[j + 1];
			}

			getline(load, m_strStory[line]);

			for (int j = 0; j < LINE; j++)
			{
				/*Draw*/
				cout << m_strStory[j] << endl;
			}
			

			if (line < LINE - 1)
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

void Play::Init()
{
	m_strName = "? ? ?";
	m_iScore = 0;
	m_iLife = 9;
	m_strInput = "";

	for (int i = 0; i < LINE; i++)
		m_strStory[i] = "";
}

Play::~Play()
{
}
